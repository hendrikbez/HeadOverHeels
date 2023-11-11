
#include "Font.hpp"

#include "ospaths.hpp"

#include <iostream>
#include <fstream>
#include <algorithm> // std::for_each


namespace gui
{

/* static */ Picture * Font::imageOfFont = nilPointer ;

/* static */ unsigned int Font::howManyLetters = 0 ;

/* static */ std::string * Font::listOfLetters = nilPointer ;


Font::Font( const std::string& name, const std::string& color, bool doubleHeight ) :
        fontName( name ),
        fontColor( color )
{
        if ( Font::imageOfFont == nilPointer )
        {
                std::string nameOfFontFile = ospaths::sharePath() + "font.png" ;
                autouniqueptr< allegro::Pict > fontFromFile( allegro::Pict::fromPNGFile( ospaths::pathToFile( nameOfFontFile ) ) );
                if ( ! fontFromFile->isNotNil() )
                {
                        std::cerr << "oops, can’t get the image of letters from file \"" << nameOfFontFile << "\"" << std::endl ;
                        return ;
                }

                imageOfFont = new Picture( fontFromFile->getW(), fontFromFile->getH() );

                autouniqueptr< Picture > blackLetters( new Picture( *fontFromFile ) );
                blackLetters->colorize( Color::blackColor() );

                const unsigned int offsetOfTint = 1;
                allegro::bitBlit(
                        blackLetters->getAllegroPict(),
                        imageOfFont->getAllegroPict(),
                        0, 0,
                        offsetOfTint, offsetOfTint,
                        imageOfFont->getWidth() - offsetOfTint, imageOfFont->getHeight() - offsetOfTint
                );

                const allegro::Pict& previousWhere = allegro::Pict::getWhereToDraw() ;
                allegro::Pict::setWhereToDraw( imageOfFont->getAllegroPict() );
                allegro::drawSprite( *fontFromFile, 0, 0 );
                allegro::Pict::setWhereToDraw( previousWhere );

                imageOfFont->setName( "image of font’s letters" );
        }

        Picture* lettersOfFont = new Picture( *imageOfFont );
        lettersOfFont->setName( "picture of letters to make " + name + " font" );

        std::string justFamily = name.substr( name.find( "." ) + 1 );
        std::string justColor = name.substr( 0, name.find( "." ) );

        // stretch for the double height
        if ( doubleHeight )
        {
                Picture* bigfont = new Picture( lettersOfFont->getWidth(), lettersOfFont->getHeight() << 1 ) ;
                allegro::stretchBlit( lettersOfFont->getAllegroPict(), bigfont->getAllegroPict(),
                                        0, 0, lettersOfFont->getWidth(), lettersOfFont->getHeight(),
                                        0, 0, bigfont->getWidth(), bigfont->getHeight() );
                delete lettersOfFont ;
                lettersOfFont = bigfont ;
                lettersOfFont->setName( "picture of stretched double height letters to make " + name + " font" );
        }

        // colorize letters
        if ( color != "white" )
        {
                lettersOfFont->colorize( Color::byName( color ) );
                lettersOfFont->setName( lettersOfFont->getName() + ", yet colored " + justColor );
        }

        // read the list of letters once for all fonts
        if ( Font::listOfLetters == nilPointer )
        {
                howManyLetters = 0;

                std::string file = ospaths::sharePath() + "letters.utf8";
                std::ifstream lettersFile ( ospaths::pathToFile( file ), std::ifstream::binary );
                if ( lettersFile )      /* no comparison with nil here, see https://gcc.gnu.org/gcc-6/porting_to.html
                                         “ The change to iostream classes also affects code that tries
                                           to check for stream errors by comparing to NULL or 0.
                                           Such code should be changed to simply test the stream directly,
                                           instead of comparing it to a null pointer ” */
                {
                        lettersFile.seekg( 0, lettersFile.end );
                        unsigned int length = lettersFile.tellg();
                        lettersFile.seekg( 0, lettersFile.beg );

                        char buffer[ length ];
                        lettersFile.read( buffer, length );
                        lettersFile.close ();

                        for ( unsigned int at = 0 ; at < length ; at ++ )
                        {
                                unsigned char c = static_cast< unsigned char >( buffer[ at ] );
                                if ( ( c == 0 ) || ( ( c & 0x80 ) == 0 ) || ( ( c & 0xC0 ) == 0xC0 ) )
                                {
                                        howManyLetters++;
                                }
                        }

                        std::cout << "file \"" << file << "\" lists " << howManyLetters << " letters" << std::endl ;
                        listOfLetters = new std::string[ howManyLetters ];

                        unsigned int inTable = 0;
                        for ( unsigned int inBuf = 0 ; inBuf < length ; )
                        {
                                unsigned char c = static_cast< unsigned char >( buffer[ inBuf ] );

                                if ( c == 0 )
                                {
                                        listOfLetters[ inTable++ ] = "";
                                        inBuf ++;
                                }
                                else
                                {
                                        char letter[ 5 ];
                                        unsigned int bytesInLetter = 0;

                                        do {
                                                letter[ bytesInLetter++ ] = c;
                                                c = static_cast< unsigned char >( buffer[ ++inBuf ] );
                                        }
                                        while ( ( ( c & 0x80 ) != 0 ) && ( ( c & 0xC0 ) != 0xC0 )
                                                        && ( bytesInLetter < 4 ) && ( inBuf < length ) ) ;

                                        letter[ bytesInLetter ] = 0 ; // end of string

                                        listOfLetters[ inTable ] = std::string( letter );
                                        inTable++ ;
                                }
                        }
                }
                else
                {
                        std::cerr << "can't read file \"" << file << "\" with the list of letters drawn in the font" << std::endl ;
                }
        }

        // decompose letters
        const unsigned int lettersPerLine = 16;
        const unsigned int linesInFont = 21;

        if ( linesInFont * lettersPerLine != howManyLetters )
                std::cout << "hmmm, the list of letters has more or less letters than the picture of font" << std::endl ;

        // the size of the font image is 272 x 609 pixels, or 16 x 21 letters 17 x 29 pixels each
        unsigned int charWidth = lettersOfFont->getWidth() / lettersPerLine ;
        unsigned int charHeight = lettersOfFont->getHeight() / linesInFont ;

        size_t positionInTable = 0;

        for ( unsigned int y = 0; y < lettersOfFont->getHeight(); y += charHeight )
        {
                for ( unsigned int x = 0; x < lettersOfFont->getWidth(); x += charWidth )
                {
                        Picture* letter = new Picture( charWidth, charHeight );
                        if ( listOfLetters[ positionInTable ] != "" )
                                allegro::bitBlit( lettersOfFont->getAllegroPict(), letter->getAllegroPict(), x, y, 0, 0, charWidth, charHeight );

                        letter->setName( "image of letter \'" + listOfLetters[ positionInTable ++ ] + "\' for " + justFamily + " font colored " + justColor );
                        letters.push_back( letter );
                }
        }

        delete lettersOfFont ;
}

Font::~Font( )
{
        for ( std::vector < Picture * >::iterator it = letters.begin () ; it != letters.end () ; ++ it )
        {
                delete *it ;
        }
}

Picture* Font::getPictureOfLetter( const std::string & letter ) const
{
        if ( listOfLetters != nilPointer )
        {
                std::string letterInTable = letter ;

                // render cyrillic ё as e diaeresis (e umlaut)
                if ( letter == "\u0451" ) letterInTable = "\u00EB" ; // \u0451 cyrillic small letter io — \u00EB latin small letter e with diaeresis
                if ( letter == "\u0401" ) letterInTable = "\u00CB" ; // \u0401 cyrillic capital letter IO — \u00CB latin capital letter E with diaeresis

                for ( unsigned int i = 0; i < howManyLetters; i++ )
                {
                        if ( letterInTable == listOfLetters[ i ] )
                                return letters.at( i );
                }
        }

        // return '?' when letter isn’t found
        if ( letters.size() > ( '?' - 32 ) )
                return letters.at( '?' - 32 );

        return nilPointer ;
}

}


#include "MenuWithTwoColumns.hpp"

#include "Gui.hpp"
#include "GuiManager.hpp"
#include "InputManager.hpp"
#include "Label.hpp"
#include "Font.hpp"


namespace gui
{

MenuWithTwoColumns::MenuWithTwoColumns( unsigned int space )
        : Menu( )
        , spaceBetweenColumns( space )
{

}

MenuWithTwoColumns::~MenuWithTwoColumns( )
{

}

void MenuWithTwoColumns::draw( BITMAP* where )
{
        if ( where == nilPointer ) return ;

        if ( where != this->whereToDraw )
        {
                this->whereToDraw = where;
        }

        if ( activeOption == nilPointer )
        {
                resetActiveOption ();
        }

        // rows in first column, after this number options go to second column
        unsigned int rowsInFirstColumn = options.size () >> 1;

        unsigned int widthOfOption = ( this->optionImage != nilPointer ) ? this->optionImage->w : 0 ;

        // calculate position of second column
        unsigned int widthOfFirstColumn = 0;
        unsigned int countOfRows = 0;
        for ( std::list< Label* >::const_iterator i = options.begin (); i != options.end (); ++i, countOfRows++ )
        {
                if ( countOfRows <= rowsInFirstColumn )
                {
                        unsigned int theWidth = ( *i )->getWidth() + widthOfOption;
                        if ( theWidth > widthOfFirstColumn ) widthOfFirstColumn = theWidth ;
                }
        }
        unsigned int secondColumnX = widthOfFirstColumn + this->spaceBetweenColumns;

        // update position of the whole menu to draw it centered
        int previousX = getX (); int previousY = getY ();
        setX( previousX + ( ( isomot::ScreenWidth - previousX ) >> 1 ) - ( getWidthOfMenu () >> 1 ) );
        setY( previousY + ( ( isomot::ScreenHeight - previousY ) >> 1 ) - ( getHeightOfMenu() >> 1 ) );

        int dx( widthOfOption );
        int dy( 0 );

        // for each label
        // para cada etiqueta
        countOfRows = 0;
        for ( std::list< Label* >::const_iterator i = options.begin (); i != options.end (); ++i, countOfRows++ )
        {
                Label* label = *i;

                // pick a font & color of text
                if ( label == this->activeOption )
                {
                        if ( label->getColor() != "orange" )
                                label->changeFontFamilyAndColor( "regular", "orange" );
                }
                else
                {
                        if ( label->getColor() != "white" )
                                label->changeFontFamilyAndColor( "regular", "white" );
                }

                BITMAP* mark = ( activeOption == label ) ? chosenOptionImageMini : optionImage ;

                // place option in first column
                if ( countOfRows <= rowsInFirstColumn )
                {
                        if ( mark != nilPointer )
                                allegro::drawSprite( where, mark, getX (), getY () + dy );

                        label->moveTo( getX () + dx, getY () + dy );
                        label->draw( where );
                }
                // place option in second column
                else
                {
                        // for first option in second column
                        if ( countOfRows == rowsInFirstColumn + 1 )
                        {
                                dy = 0;
                        }

                        // dibuja la viñeta
                        // para cada etiqueta
                        // ( poems, no less )
                        if ( mark != nilPointer )
                                allegro::drawSprite( where, mark, getX () + secondColumnX, getY () + dy );

                        label->moveTo( getX () + dx + secondColumnX, getY () + dy );
                        label->draw( where );
                }

                // update vertical offset
                dy += label->getFont()->getCharHeight() - 4;

                // adjust spacing between lines
                dy -= label->getFont()->getCharHeight() >> 5;
        }

        // back to initial position of menu
        setX ( previousX );
        setY ( previousY );
}

unsigned int MenuWithTwoColumns::getWidthOfMenu () const
{
        unsigned int widthOfFirstColumn = 0;
        unsigned int widthOfSecondColumn = 0;
        unsigned int countOfRows = 0;

        unsigned int rowsInFirstColumn = options.size () >> 1;

        for ( std::list< Label* >::const_iterator i = options.begin (); i != options.end (); ++i, countOfRows++ )
        {
                unsigned int theWidth = ( *i )->getWidth() + ( this->optionImage != nilPointer ? this->optionImage->w : 0 );

                if ( countOfRows <= rowsInFirstColumn )
                {
                        if ( theWidth > widthOfFirstColumn )
                                widthOfFirstColumn = theWidth ;
                }
                else
                {
                        if ( theWidth > widthOfSecondColumn )
                                widthOfSecondColumn = theWidth ;
                }
        }

        return widthOfFirstColumn + this->spaceBetweenColumns + widthOfSecondColumn;
}

unsigned int MenuWithTwoColumns::getHeightOfMenu () const
{
        unsigned int heightOfMenu = 0;
        unsigned int countOfRows = 0;
        unsigned int rowsInFirstColumn = options.size () >> 1;

        for ( std::list< Label * >::const_iterator i = options.begin () ; i != options.end () ; ++i, countOfRows++ )
        {
                if ( countOfRows <= rowsInFirstColumn )
                {
                        heightOfMenu += ( *i )->getHeight() - 4;
                        heightOfMenu -= ( *i )->getHeight() >> 5;
                }
        }

        return heightOfMenu;
}

}

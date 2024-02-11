
#include "TextField.hpp"

#include "Font.hpp"
#include "Label.hpp"

#include <algorithm> // std::for_each

using gui::TextField;
using gui::Label;


TextField::TextField( unsigned int width, const std::string & align )
        : Widget( )
        , width( width )
        , height( 0 )
        , alignment( align )
{

}

TextField::~TextField()
{
        std::for_each( this->lines.begin (), this->lines.end (), DeleteIt() );
        this->lines.clear();
}

void TextField::draw ()
{
        for ( std::vector< Label* >::const_iterator i = this->lines.begin (); i != this->lines.end (); ++ i )
        {
                Label* label = *i ;

                if ( ( label->getY() + static_cast< int >( label->getWidth() ) >= 0 ) &&
                                ( label->getY() < static_cast< int >( allegro::Pict::getWhereToDraw().getH() ) ) )
                {
                        label->draw ();
                }
        }
}

void TextField::appendText( const std::string & text, bool height2x, const std::string & color )
{
        bool multicolor = ( color == "multicolor" ) ;
        Label* label = new Label( text, Font::fontByColorAndSize( multicolor ? "" : color, height2x ), multicolor );

        const int deltaW = static_cast< int >( this->width ) - static_cast< int >( label->getWidth() );
        int posX = 0;

        if ( alignment == "center" )
                posX = deltaW >> 1;
        else if ( alignment == "right" )
                posX = deltaW;

        label->moveTo( posX + this->getX (), this->getY () + this->height );
        this->height += label->getHeight();

        lines.push_back( label );
}

void TextField::setAlignment( const std::string& newAlignment )
{
        for ( std::vector< Label * >::const_iterator i = this->lines.begin (); i != this->lines.end (); ++ i )
        {
                Label* label = ( *i );

                int offsetX = 0;

                if ( newAlignment == "center" )
                        offsetX = ( this->width - label->getWidth() ) >> 1;
                else if ( newAlignment == "right" )
                        offsetX = this->width - label->getWidth();

                label->moveTo( offsetX + this->getX (), label->getY () );
        }

        this->alignment = newAlignment;
}

void TextField::moveTo( int x, int y )
{
        for ( std::vector< Label * >::const_iterator i = this->lines.begin (); i != this->lines.end (); ++ i )
        {
                Label* label = ( *i );
                label->moveTo( label->getX() + x - this->getX(), label->getY() + y - this->getY() );
        }

        Widget::moveTo( x, y );
}

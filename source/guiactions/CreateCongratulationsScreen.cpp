
#include "CreateCongratulationsScreen.hpp"

#include "GameManager.hpp"
#include "GuiManager.hpp"
#include "LanguageManager.hpp"
#include "LanguageText.hpp"
#include "GamePreferences.hpp"
#include "Screen.hpp"
#include "PictureWidget.hpp"
#include "TextField.hpp"
#include "CreateEndScreen.hpp"

using gui::CreateCongratulationsScreen ;


CreateCongratulationsScreen::CreateCongratulationsScreen( unsigned short rooms, unsigned short planets )
        : Action( )
        , rooms( rooms )
        , planets( planets )
{

}

CreateCongratulationsScreen::~CreateCongratulationsScreen( )
{

}

void CreateCongratulationsScreen::doAction ()
{
        LanguageManager* languageManager = GuiManager::getInstance().getLanguageManager();
        LanguageText* langString = 0;

        Screen& screen = * GuiManager::getInstance().findOrCreateScreenForAction( this );

        if ( screen.countWidgets() == 0 )
        {
                screen.setEscapeAction( new CreateEndScreen( rooms, planets ) );
        }
        else
        {
                screen.freeWidgets() ;
        }

        // Head coronado
        screen.addWidget( new PictureWidget( 192, 50, PicturePtr( Screen::loadPicture( "crown.png" ) ), "crown.png" ) );
        screen.addPictureOfHeadAt( 192, 100 );

        // Heels coronado
        screen.addWidget( new PictureWidget( 400, 50, PicturePtr( Screen::loadPicture( "crown.png" ) ), "crown.png" ) );
        screen.addPictureOfHeelsAt( 400, 100 );

        // texto final
        langString = languageManager->findLanguageStringForAlias( "final-text" );
        TextField* textField = new TextField( GamePreferences::getScreenWidth(), "center" );
        textField->moveTo( 0, 180 );

        for ( size_t i = 0; i < langString->howManyLinesOfText(); i ++ )
        {
                const LanguageLine & line = langString->getNthLine( i );
                textField->appendText( line.getText(), line.getFontName(), line.getColor() );
        }

        screen.addWidget( textField );

        GuiManager::getInstance().changeScreen( screen, true );
}

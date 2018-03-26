
#include "SaveGame.hpp"
#include "Ism.hpp"
#include "GameManager.hpp"
#include "ContinueGame.hpp"

using gui::SaveGame;
using gui::ContinueGame;


SaveGame::SaveGame( BITMAP* picture, unsigned int slot )
        : Action( picture )
        , slot( slot )
{

}

void SaveGame::doAction ()
{
        clear_keybuf();

        if ( slot > 0 )
        {
                isomot::GameManager* gameManager = isomot::GameManager::getInstance();

                std::stringstream ss;
                ss << slot;
                gameManager->saveGame( isomot::homePath() + "savegame" + pathSeparator + "saved" + ss.str() + ".xml" );
        }

        ContinueGame * game = new ContinueGame( getWhereToDraw(), true );
        game->doIt ();
}

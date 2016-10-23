// The free and open source remake of Head over Heels
//
// Copyright © 2016 Douglas Mencken dougmencken @ gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game copyright © 1987 Ocean Software Ltd.
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef ContinueGame_h_
#define ContinueGame_h_

#include <allegro.h>
#include "Action.hpp"

namespace gui
{

class ContinueGame : public Action
{

public:

        /**
         * Constructor
         * @param picture Imagen donde se dibujará la interfaz gráfica
         * @param gameInProgress Indica si hay una partida en curso o comienza una nueva
         */
        ContinueGame( BITMAP* picture, bool gameInProgress ) ;

        /**
         * Begin the game
         */
        void doIt () ;

private:

        /**
         * Imagen donde se dibujará la interfaz gráfica
         */
        BITMAP* where ;

        /**
         * Indica si hay una partida en curso o comienza una nueva
         */
        bool gameInProgress ;

};

}

#endif
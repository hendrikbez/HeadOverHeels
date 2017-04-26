// The free and open source remake of Head over Heels
//
// Copyright © 2017 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game copyright © 1987 Ocean Software Ltd.
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef CreateMenuOfGraphicSets_hpp_
#define CreateMenuOfGraphicSets_hpp_

#include "Action.hpp"

#include <string>
#include <map>
#include <allegro.h>


namespace gui
{

class Menu;

/**
 * Create menu with list of graphic sets
 */

class CreateMenuOfGraphicSets : public Action
{

public:

        /**
         * Constructor
         * @param picture Image where to draw
         * @param previous Instance of action to do on escape
         */
        CreateMenuOfGraphicSets( BITMAP * picture, Action * previous ) ;

        /**
         * Show this menu
         */
        void doIt () ;

        std::string getNameOfAction ()  {  return "CreateMenuOfGraphicSets" ;  }

private:

        BITMAP * where ;

        Action * actionOnEscape ;

        Menu * menuOfGraphicSets;

        std::map < std::string, std::string > graphicSets ;

};

}

#endif

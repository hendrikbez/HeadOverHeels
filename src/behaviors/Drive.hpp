// The free and open source remake of Head over Heels
//
// Copyright © 2018 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game copyright © 1987 Ocean Software Ltd.
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef Drive_hpp_
#define Drive_hpp_

#include "Behavior.hpp"
#include "Timer.hpp"


namespace isomot
{

class Item ;

/**
 * Mueve al elemento en la dirección marcada por el elemento que tiene encima
 */

class Drive : public Behavior
{

public:

        Drive( Item * item, const std::string & behavior ) ;

        virtual ~Drive( ) ;

        virtual bool update () ;

private:

       /**
        * Indica si el elemento está en marcha o parado
        */
        bool running ;

       /**
        * Cronómetro que controla la velocidad de movimiento del elemento
        */
        Timer * speedTimer ;

       /**
        * Cronómetro que controla la velocidad de caída del elemento
        */
        Timer * fallTimer ;

};

}

#endif

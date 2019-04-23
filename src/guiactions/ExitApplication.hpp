// The free and open source remake of Head over Heels
//
// Copyright © 2019 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game copyright © 1987 Ocean Software Ltd.
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef ExitApplication_hpp_
#define ExitApplication_hpp_

#include "Action.hpp"


namespace gui
{

class ExitApplication : public Action
{

public:

        ExitApplication( ) : Action( ) { }

        virtual std::string getNameOfAction () const {  return "ExitApplication" ;  }

protected:

        virtual void doAction () {  bye () ;  }

private:

        void bye () ;

};

}

#endif

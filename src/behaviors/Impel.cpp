
#include "Impel.hpp"
#include "Item.hpp"
#include "FreeItem.hpp"
#include "DisplaceKindOfActivity.hpp"
#include "FallKindOfActivity.hpp"
#include "Mediator.hpp"
#include "Room.hpp"


namespace isomot
{

Impel::Impel( Item * item, const std::string & behavior ) :
        Behavior( item, behavior )
{
        activity = Wait;
        speedTimer = new Timer();
        fallTimer = new Timer();
        speedTimer->go();
        fallTimer->go();
}

Impel::~Impel()
{
        delete speedTimer;
        delete fallTimer;
}

bool Impel::update ()
{
        FreeItem * freeItem = dynamic_cast< FreeItem * >( this->item );
        bool vanish = false;

        switch ( activity )
        {
                case Wait:
                        break;

                case DisplaceNorth:
                case DisplaceSouth:
                case DisplaceEast:
                case DisplaceWest:
                case DisplaceNortheast:
                case DisplaceNorthwest:
                case DisplaceSoutheast:
                case DisplaceSouthwest:
                        // is it time to move
                        if ( speedTimer->getValue() > freeItem->getSpeed() )
                        {
                                if ( ! DisplaceKindOfActivity::getInstance()->displace( this, &activity, true ) )
                                {
                                        activity = Wait;
                                }

                                speedTimer->reset();
                        }

                        freeItem->animate();
                        break;

                case Fall:
                        // look for reaching floor in a room without floor
                        if ( freeItem->getZ() == 0 && freeItem->getMediator()->getRoom()->getKindOfFloor() == "none" )
                        {
                                // item disappears
                                vanish = true;
                        }
                        // is it time to fall
                        else if ( fallTimer->getValue() > freeItem->getWeight() )
                        {
                                if ( ! FallKindOfActivity::getInstance()->fall( this ) )
                                {
                                        activity = Wait;
                                }

                                fallTimer->reset();
                        }
                        break;

                default:
                        ;
        }

        return vanish;
}

}

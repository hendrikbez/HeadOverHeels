
#include "Mobile.hpp"
#include "Item.hpp"
#include "FreeItem.hpp"
#include "Room.hpp"
#include "Mediator.hpp"
#include "DisplaceKindOfActivity.hpp"
#include "FallKindOfActivity.hpp"
#include "SoundManager.hpp"


namespace isomot
{

Mobile::Mobile( Item * item, const std::string & behavior ) :
        Behavior( item, behavior )
{
        speedTimer = new Timer();
        fallTimer = new Timer();
        speedTimer->go ();
        fallTimer->go ();
}

Mobile::~Mobile()
{
        delete speedTimer;
        delete fallTimer;
}

bool Mobile::update ()
{
        FreeItem* freeItem = dynamic_cast< FreeItem * >( this->item );
        bool isGone = false;

        switch ( activity )
        {
                case Wait:
                        // see if item falls yet
                        if ( FallKindOfActivity::getInstance()->fall( this ) )
                        {
                                fallTimer->reset();
                                activity = Fall;
                        }
                        break;

                case DisplaceNorth:
                case DisplaceSouth:
                case DisplaceEast:
                case DisplaceWest:
                case DisplaceNortheast:
                case DisplaceSoutheast:
                case DisplaceSouthwest:
                case DisplaceNorthwest:
                        // is it time to move
                        if ( speedTimer->getValue() > freeItem->getSpeed() )
                        {
                                // emit sound of displacement if item is pushed but not displaced by item below it
                                if ( this->sender == nilPointer || this->sender != this->item )
                                {
                                        SoundManager::getInstance()->play( freeItem->getLabel(), activity );
                                }

                                this->changeActivityOfItem( activity );
                                DisplaceKindOfActivity::getInstance()->displace( this, &activity, true );

                                activity = Wait;

                                speedTimer->reset();
                        }

                        freeItem->animate();
                        break;

                case ForceDisplaceNorth:
                case ForceDisplaceSouth:
                case ForceDisplaceEast:
                case ForceDisplaceWest:
                        // item is on conveyor
                        if ( speedTimer->getValue() > item->getSpeed() )
                        {
                                DisplaceKindOfActivity::getInstance()->displace( this, &activity, true );

                                activity = Fall;

                                speedTimer->reset();
                        }
                        break;

                case Fall:
                        // look for reaching floor in a room without floor
                        if ( freeItem->getZ() == 0 && freeItem->getMediator()->getRoom()->getKindOfFloor() == "none" )
                        {
                                isGone = true;
                        }
                        // is it time to fall
                        else if ( fallTimer->getValue() > freeItem->getWeight() )
                        {
                                this->changeActivityOfItem( activity );
                                if ( ! FallKindOfActivity::getInstance()->fall( this ) )
                                {
                                        // play sound of falling
                                        SoundManager::getInstance()->play( freeItem->getLabel(), activity );
                                        activity = Wait;
                                }

                                fallTimer->reset();
                        }
                        break;

                case Vanish:
                        // disappear when this item is caught
                        isGone = true;
                        break;

                default:
                        ;
        }

        return isGone;
}

}


#include "KindOfActivity.hpp"
#include "Behavior.hpp"
#include "Item.hpp"
#include "FreeItem.hpp"
#include "PlayerItem.hpp"
#include "Room.hpp"
#include "Mediator.hpp"
#include "GameManager.hpp"


namespace isomot
{

KindOfActivity::KindOfActivity( )
{

}

KindOfActivity::~KindOfActivity( )
{

}

void KindOfActivity::propagateActivityToAdjacentItems( Item * sender, const ActivityOfItem& activity )
{
        Mediator* mediator = sender->getMediator();

        // as long as there are items collided with sender
        while ( ! mediator->isStackOfCollisionsEmpty() )
        {
                std::string nameOfCollision = mediator->popCollision();
                Item * itemMeetsSender = mediator->findItemByUniqueName( nameOfCollision );

                if ( itemMeetsSender != nilPointer )
                {
                        // is it free item or grid item
                        if ( itemMeetsSender->whichKindOfItem() == "grid item" ||
                                itemMeetsSender->whichKindOfItem() == "free item" || itemMeetsSender->whichKindOfItem() == "player item" )
                        {
                                // is it item with behavior
                                if ( itemMeetsSender->getBehavior() != nilPointer )
                                {
                                        // if it’s player item and sender is mortal, then player loses its life
                                        if ( dynamic_cast< PlayerItem * >( itemMeetsSender ) && sender->isMortal() &&
                                                        ! dynamic_cast< PlayerItem * >( itemMeetsSender )->hasShield() )
                                        {
                                                if ( itemMeetsSender->getBehavior()->getActivityOfItem() != MeetMortalItem &&
                                                                itemMeetsSender->getBehavior()->getActivityOfItem() != Vanish )
                                                {
                                                        if ( ! GameManager::getInstance()->isImmuneToCollisionsWithMortalItems () )
                                                        {
                                                                std::cout << "mortal item \"" << sender->getLabel() << "\" just met player" << std::endl ;

                                                                // is it direct contact
                                                                if ( mediator->depthOfStackOfCollisions() <= 1 )
                                                                {
                                                                        itemMeetsSender->getBehavior()->changeActivityOfItem( MeetMortalItem );
                                                                }
                                                        }
                                                        /* else std::cout << "right to inviolability granted when item \"" << sender->getLabel() << "\" met player" << std::endl ; */
                                                }
                                        }
                                        // if sender is player and colliding one is mortal, then player loses its life
                                        else if ( dynamic_cast< PlayerItem * >( sender ) && itemMeetsSender->isMortal() &&
                                                        ! dynamic_cast< PlayerItem * >( sender )->hasShield() )
                                        {
                                                if ( sender->getBehavior()->getActivityOfItem() != MeetMortalItem &&
                                                                itemMeetsSender->getBehavior()->getActivityOfItem() != Vanish )
                                                {
                                                        if ( ! GameManager::getInstance()->isImmuneToCollisionsWithMortalItems () )
                                                        {
                                                                std::cout << "player just met mortal item \"" << itemMeetsSender->getLabel() << "\"" << std::endl ;

                                                                sender->getBehavior()->changeActivityOfItem( MeetMortalItem );
                                                                itemMeetsSender->getBehavior()->changeActivityOfItem( activity, sender );
                                                        }
                                                        /* else std::cout << "right to inviolability granted when player met item \"" << itemMeetsSender->getLabel() << "\"" << std::endl ; */
                                                }
                                        }
                                        // if not, propagate activity to that item
                                        else
                                        {
                                                if ( itemMeetsSender->getBehavior()->getActivityOfItem() != Vanish )
                                                {
                                                        itemMeetsSender->getBehavior()->changeActivityOfItem( activity, sender );
                                                }
                                        }
                                }
                                // otherwise it is item without behavior, which may be mortal too
                                else if ( dynamic_cast< PlayerItem * >( sender ) && itemMeetsSender->isMortal() &&
                                                ! dynamic_cast< PlayerItem * >( sender )->hasShield() )
                                {
                                        if ( sender->getBehavior()->getActivityOfItem() != MeetMortalItem &&
                                                        sender->getBehavior()->getActivityOfItem() != Vanish )
                                        {
                                                if ( ! GameManager::getInstance()->isImmuneToCollisionsWithMortalItems () )
                                                {
                                                        sender->getBehavior()->changeActivityOfItem( MeetMortalItem );
                                                }
                                        }
                                }
                        }
                }
                // is it player which leaves room via some door
                else if ( sender->whichKindOfItem() == "player item" &&
                        ( ( nameOfCollision == "north limit"  &&  mediator->getRoom()->hasDoorAt( "north" ) ) ||
                          ( nameOfCollision == "south limit"  &&  mediator->getRoom()->hasDoorAt( "south" ) ) ||
                          ( nameOfCollision == "east limit"  &&  mediator->getRoom()->hasDoorAt( "east" ) ) ||
                          ( nameOfCollision == "west limit"  &&  mediator->getRoom()->hasDoorAt( "west" ) ) ||
                          ( nameOfCollision == "northeast limit"  &&  mediator->getRoom()->hasDoorAt( "northeast" ) ) ||
                          ( nameOfCollision == "northwest limit"  &&  mediator->getRoom()->hasDoorAt( "northwest" ) ) ||
                          ( nameOfCollision == "southeast limit"  &&  mediator->getRoom()->hasDoorAt( "southeast" ) ) ||
                          ( nameOfCollision == "southwest limit"  &&  mediator->getRoom()->hasDoorAt( "southwest" ) ) ||
                          ( nameOfCollision == "eastnorth limit"  &&  mediator->getRoom()->hasDoorAt( "eastnorth" ) ) ||
                          ( nameOfCollision == "eastsouth limit"  &&  mediator->getRoom()->hasDoorAt( "eastsouth" ) ) ||
                          ( nameOfCollision == "westnorth limit"  &&  mediator->getRoom()->hasDoorAt( "westnorth" ) ) ||
                          ( nameOfCollision == "westsouth limit"  &&  mediator->getRoom()->hasDoorAt( "westsouth" ) ) ) )
                {
                        PlayerItem * character = dynamic_cast< PlayerItem * >( sender );

                        if ( nameOfCollision == "north limit" )
                                character->setWayOfExit( "north" );
                        else if ( nameOfCollision == "south limit" )
                                character->setWayOfExit( "south" );
                        else if ( nameOfCollision == "east limit" )
                                character->setWayOfExit( "east" );
                        else if ( nameOfCollision == "west limit" )
                                character->setWayOfExit( "west" );
                        else if ( nameOfCollision == "northeast limit" )
                                character->setWayOfExit( "northeast" );
                        else if ( nameOfCollision == "northwest limit" )
                                character->setWayOfExit( "northwest" );
                        else if ( nameOfCollision == "southeast limit" )
                                character->setWayOfExit( "southeast" );
                        else if ( nameOfCollision == "southwest limit" )
                                character->setWayOfExit( "southwest" );
                        else if ( nameOfCollision == "eastnorth limit" )
                                character->setWayOfExit( "eastnorth" );
                        else if ( nameOfCollision == "eastsouth limit" )
                                character->setWayOfExit( "eastsouth" );
                        else if ( nameOfCollision == "westnorth limit" )
                                character->setWayOfExit( "westnorth" );
                        else if ( nameOfCollision == "westsouth limit" )
                                character->setWayOfExit( "westsouth" );
                }
        }
}

void KindOfActivity::propagateActivityToItemsAbove( Item * sender, const ActivityOfItem& activity )
{
        Mediator* mediator = sender->getMediator();

        // is there anything above
        if ( ! sender->canAdvanceTo( 0, 0, 1 ) )
        {
                // copy stack of collisions
                std::stack< std::string > itemsAbove;
                while ( ! mediator->isStackOfCollisionsEmpty() )
                {
                        itemsAbove.push( mediator->popCollision() );
                }

                while ( ! itemsAbove.empty() )
                {
                        // get first item
                        std::string uniqueName = itemsAbove.top();
                        itemsAbove.pop();

                        Item* itemAbove = mediator->findItemByUniqueName( uniqueName );

                        // is it free item
                        if ( itemAbove != nilPointer &&
                                ( itemAbove->whichKindOfItem() == "free item" || itemAbove->whichKindOfItem() == "player item" ) )
                        {
                                FreeItem* freeItemAbove = dynamic_cast< FreeItem * >( itemAbove );

                                // is it item with behavior
                                if ( freeItemAbove != nilPointer && freeItemAbove->getBehavior() != nilPointer )
                                {
                                        // look for collisions of that free item with items below it
                                        if ( ! freeItemAbove->canAdvanceTo( 0, 0, -1 ) )
                                        {
                                                // propagate activity when there’s no more than one item below or when sender is anchor of that item
                                                if ( mediator->depthOfStackOfCollisions() <= 1 || freeItemAbove->getAnchor() == sender )
                                                {
                                                        if ( freeItemAbove->getBehavior()->getActivityOfItem() != Vanish )
                                                        {
                                                                // if it’s player item above sender and sender is mortal, then player loses its life
                                                                if ( dynamic_cast< PlayerItem * >( freeItemAbove ) && sender->isMortal() &&
                                                                        ! dynamic_cast< PlayerItem * >( freeItemAbove )->hasShield() )
                                                                {
                                                                        if ( freeItemAbove->getBehavior()->getActivityOfItem() != MeetMortalItem )
                                                                        {
                                                                                if ( ! GameManager::getInstance()->isImmuneToCollisionsWithMortalItems () )
                                                                                {
                                                                                        std::cout << "player is above mortal item \"" << sender->getLabel() << "\"" << std::endl ;
                                                                                        freeItemAbove->getBehavior()->changeActivityOfItem( MeetMortalItem );
                                                                                }
                                                                                /* else std::cout << "right to inviolability granted when player is above item \"" << sender->getLabel() << "\"" << std::endl ; */
                                                                        }
                                                                }
                                                                // if not, propagate activity to that item above
                                                                else
                                                                {
                                                                        ActivityOfItem currentActivity = freeItemAbove->getBehavior()->getActivityOfItem();
                                                                        if ( currentActivity != DisplaceNorth && currentActivity != DisplaceSouth &&
                                                                                currentActivity != DisplaceEast && currentActivity != DisplaceWest )
                                                                        {
                                                                                freeItemAbove->getBehavior()->changeActivityOfItem( activity, freeItemAbove );
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
}

}

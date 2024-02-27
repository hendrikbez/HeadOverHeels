
#include "ThereAndBack.hpp"

#include "Item.hpp"
#include "FreeItem.hpp"
#include "Moving.hpp"
#include "Displacing.hpp"
#include "Falling.hpp"
#include "Mediator.hpp"
#include "Room.hpp"
#include "SoundManager.hpp"


namespace behaviors
{

ThereAndBack::ThereAndBack( const ItemPtr & item, const std::string & behavior, bool flying ) :
        Behavior( item, behavior )
        , isFlying( flying )
        , speedTimer( new Timer() )
        , fallTimer( new Timer() )
{
        speedTimer->go();
        if ( ! flying ) fallTimer->go();
}

ThereAndBack::~ThereAndBack()
{
}

bool ThereAndBack::update ()
{
        bool vanish = false;
        FreeItem& freeItem = dynamic_cast< FreeItem& >( * this->item );

        switch ( activity )
        {
                case activities::Activity::Waiting:
                        letsMove();
                        break;

                case activities::Activity::MovingNorth:
                case activities::Activity::MovingSouth:
                case activities::Activity::MovingEast:
                case activities::Activity::MovingWest:
                        if ( ! freeItem.isFrozen() )
                        {
                                if ( speedTimer->getValue() > freeItem.getSpeed() )
                                {
                                        // move it
                                        if ( ! activities::Moving::getInstance().move( this, &activity, true ) )
                                        {
                                                turnRound();

                                                // play the sound of collision
                                                SoundManager::getInstance().play( freeItem.getKind (), "collision" );
                                        }

                                        speedTimer->reset();
                                }

                                freeItem.animate();
                        }
                        break;

                case activities::Activity::PushedNorth:
                case activities::Activity::PushedSouth:
                case activities::Activity::PushedEast:
                case activities::Activity::PushedWest:
                case activities::Activity::PushedNortheast:
                case activities::Activity::PushedSoutheast:
                case activities::Activity::PushedSouthwest:
                case activities::Activity::PushedNorthwest:
                        if ( ! this->isFlying )
                        {
                                // emit the sound of displacing
                                SoundManager::getInstance().play( freeItem.getKind (), "push" );

                                // displace this item by other one
                                activities::Displacing::getInstance().displace( this, &activity, true );

                                activity = activities::Activity::Waiting;

                                // preserve inactivity for frozen item
                                if ( freeItem.isFrozen() )
                                        activity = activities::Activity::Freeze;
                        }
                        else
                        {
                                activity = activities::Activity::Waiting;
                        }
                        break;

                case activities::Activity::Falling:
                        if ( ! this->isFlying )
                        {
                                // look for reaching floor in a room without floor
                                if ( freeItem.getZ() == 0 && ! freeItem.getMediator()->getRoom()->hasFloor() )
                                {
                                        // item disappears
                                        vanish = true;
                                }
                                // is it time to fall
                                else if ( fallTimer->getValue() > freeItem.getWeight() )
                                {
                                        if ( ! activities::Falling::getInstance().fall( this ) )
                                        {
                                                // emit the sound of falling
                                                SoundManager::getInstance().play( freeItem.getKind (), "fall" );
                                                activity = activities::Activity::Waiting;
                                        }

                                        fallTimer->reset();
                                }
                        }
                        else
                        {
                                activity = activities::Activity::Waiting;
                        }
                        break;

                case activities::Activity::Freeze:
                        freeItem.setFrozen( true );
                        break;

                case activities::Activity::WakeUp:
                        freeItem.setFrozen( false );
                        activity = activities::Activity::Waiting;
                        break;

                default:
                        ;
        }

        return vanish;
}

void ThereAndBack::letsMove()
{
        switch ( Way( item->getHeading() ).getIntegerOfWay () )
        {
                case Way::North:
                        activity = activities::Activity::MovingNorth;
                        break;

                case Way::South:
                        activity = activities::Activity::MovingSouth;
                        break;

                case Way::East:
                        activity = activities::Activity::MovingEast;
                        break;

                case Way::West:
                        activity = activities::Activity::MovingWest;
                        break;

                default:
                        ;
        }
}

void ThereAndBack::turnRound()
{
        switch ( Way( item->getHeading() ).getIntegerOfWay () )
        {
                case Way::North:
                        activity = activities::Activity::MovingSouth ;
                        item->changeHeading( "south" );
                        break;

                case Way::South:
                        activity = activities::Activity::MovingNorth ;
                        item->changeHeading( "north" );
                        break;

                case Way::East:
                        activity = activities::Activity::MovingWest ;
                        item->changeHeading( "west" );
                        break;

                case Way::West:
                        activity = activities::Activity::MovingEast ;
                        item->changeHeading( "east" );
                        break;

                default:
                        ;
        }
}

}

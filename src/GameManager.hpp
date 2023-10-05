// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef GameManager_hpp_
#define GameManager_hpp_

#include <string>

#include "Ism.hpp"
#include "Picture.hpp"
#include "Isomot.hpp"
#include "Room.hpp"
#include "GameSaverAndLoader.hpp"
#include "ColorCyclingLabel.hpp"
#include "Timer.hpp"


namespace iso
{

class Isomot ;


/**
 * Marks the definitive moments of the game
 *
 * Only the single lone of these moments may be set true at the same time
 * Checking for a key moment optionally resets it to false, so be sure to use such a knowledge
 */

class TheKeyMoments
{

private:

        bool theMomentOfGameOver ;   /* all lives are lost or the user quit the game */

        bool theMomentOFishWasEaten ;      /* a chance to save the current progress */
        bool theMomentOfCrownWasTaken ;    /* crown is taken and one more planet was liberated this way */

        bool theMomentOfArrivalInFreedomNotWithAllCrowns ;            /* at least one character reached Freedom (not with all crowns) */
        bool theMomentWhenHeadAndHeelsAreInFreedomWithAllTheCrowns ;  /* both characters reached Freedom with all the crowns */

public:

        TheKeyMoments()
                : theMomentOfGameOver( false )
                , theMomentOFishWasEaten( false )
                , theMomentOfCrownWasTaken( false )
                , theMomentOfArrivalInFreedomNotWithAllCrowns( false )
                , theMomentWhenHeadAndHeelsAreInFreedomWithAllTheCrowns( false )
        {}

        void gameOver() {  resetAll() ; theMomentOfGameOver = true ;  }

        bool isGameOver( bool reset )
        {
                bool is = theMomentOfGameOver ;
                if ( reset ) theMomentOfGameOver = false ;
                return is ;
        }

        void fishEaten() {  resetAll() ; theMomentOFishWasEaten = true ;  }

        bool wasFishEaten( bool reset )
        {
                bool was = theMomentOFishWasEaten ;
                if ( reset ) theMomentOFishWasEaten = false ;
                return was ;
        }

        void crownTaken() {  resetAll() ; theMomentOfCrownWasTaken = true ;  }

        bool wasCrownTaken( bool reset )
        {
                bool was = theMomentOfCrownWasTaken ;
                if ( reset ) theMomentOfCrownWasTaken = false ;
                return was ;
        }

        void arriveInFreedomNotWithAllCrowns() {  resetAll() ; theMomentOfArrivalInFreedomNotWithAllCrowns = true ;  }

        bool arrivedInFreedomNotWithAllCrowns( bool reset )
        {
                bool arrived = theMomentOfArrivalInFreedomNotWithAllCrowns ;
                if ( reset ) theMomentOfArrivalInFreedomNotWithAllCrowns = false ;
                return arrived ;
        }

        void HeadAndHeelsAreInFreedomWithAllTheCrowns() {  resetAll() ; theMomentWhenHeadAndHeelsAreInFreedomWithAllTheCrowns = true ;  }

        bool areHeadAndHeelsInFreedomWithAllTheCrowns( bool reset )
        {
                bool are = theMomentWhenHeadAndHeelsAreInFreedomWithAllTheCrowns ;
                if ( reset ) theMomentWhenHeadAndHeelsAreInFreedomWithAllTheCrowns = false ;
                return are ;
        }

        bool isThereAny()
        {
                return ( theMomentOfGameOver
                         || theMomentOFishWasEaten
                            || theMomentOfCrownWasTaken
                               || theMomentOfArrivalInFreedomNotWithAllCrowns
                                  || theMomentWhenHeadAndHeelsAreInFreedomWithAllTheCrowns ) ;
        }

        void resetAll()
        {
                theMomentOfGameOver = false ;
                theMomentOFishWasEaten = false ;
                theMomentOfCrownWasTaken = false ;
                theMomentOfArrivalInFreedomNotWithAllCrowns = false ;
                theMomentWhenHeadAndHeelsAreInFreedomWithAllTheCrowns = false ;
        }

} ;


/**
 * Why the game was paused
 */

class WhyPaused
{
private:

        unsigned int whyPaused ;

        static const unsigned int Nevermind = 0 ;
        static const unsigned int LiberatePlanet = 1 ;
        static const unsigned int SaveGame = 2 ;
        static const unsigned int InFreedom = 3 ;
        static const unsigned int TheFinalScreen = 4 ;
        static const unsigned int GameOver = 5 ;

public:

        WhyPaused() : whyPaused( Nevermind ) { }
        WhyPaused( unsigned int why ) : whyPaused( why ) { }

        bool stillNevermind() {  return whyPaused == Nevermind ;  }

        void forNewlyLiberatedPlanet() {  whyPaused = LiberatePlanet ;  }
        void forSaving() {  whyPaused = SaveGame ;  }
        void forArrivingInFreedom() {  whyPaused = InFreedom ;  }
        void forThatFinalScreen() {  whyPaused = TheFinalScreen ;  }
        void forGameOver() {  whyPaused = GameOver ;  }

        bool toCallOnlyWithinDoActionOfContinueGame_isPlanetLiberated() {  return whyPaused == LiberatePlanet ;  }
        bool toCallOnlyWithinDoActionOfContinueGame_isTimeToSaveTheGame() {  return whyPaused == SaveGame ;  }
        bool toCallOnlyWithinDoActionOfContinueGame_isThatFinalSuccessScreen() {  return whyPaused == TheFinalScreen ;  }
        bool toCallOnlyWithinDoActionOfContinueGame_isInFreedomWithoutAllTheCrowns() {  return whyPaused == InFreedom ;  }
        bool toCallOnlyWithinDoActionOfContinueGame_isAllLivesLost() {  return whyPaused == GameOver ;  }
} ;


/**
 * Manages user interface and isometric engine. Plus, holds the game's data
 * such as how many lives left for characters, which planets are free already, and so on
 */

class GameManager
{

private:

        GameManager( ) ;

        GameManager( const GameManager & ) { }

protected:

        static PicturePtr refreshPicture ( const std::string & nameOfPicture ) ;

public:

        static const unsigned int updatesPerSecond = 50 ;

        static const unsigned int spaceForAmbiance = 100 ;

        static GameManager & getInstance () ;

        virtual ~GameManager( ) ;

        void cleanUp () ;

        static bool readPreferences ( const std::string& fileName ) ;

        static bool writePreferences ( const std::string& fileName ) ;

        /**
         * Game begins here
         * @return Reason why the game is paused
         */
        WhyPaused begin () ;

        /**
         * Pause game in progress
         */
        WhyPaused pause () ;

        /**
         * Resume game after a pause
         * @return Reason why the game was paused
         */
        WhyPaused resume () ;

        std::string getHeadRoom () const {  return headRoom ;  }

        void setHeadRoom( const std::string& room ) {  headRoom = room ;  }

        std::string getHeelsRoom () const {  return heelsRoom ;  }

        void setHeelsRoom( const std::string& room ) {  heelsRoom = room ;  }

        /**
         * Draw ambiance of game, that is info about game like lives, tools, donus, thing in bag
         */
        void drawAmbianceOfGame ( const allegro::Pict& where ) ;

        /**
         * bitBlit the view on the allegro's screen
         */
        void drawOnScreen ( const allegro::Pict& view ) ;

        void loadGame ( const std::string& fileName ) ;

        void saveGame ( const std::string& fileName ) ;

        void addLives ( const std::string& player, unsigned char lives ) ;

        void loseLife ( const std::string& player ) ;

        /**
         * Player takes magic item
         */
        void takeMagicItem ( const std::string& label ) ;

        void consumeDonut () {  this->donuts-- ;  }

        void addHighSpeed ( const std::string& player, unsigned int highSpeed ) ;

        void decreaseHighSpeed ( const std::string& player ) ;

        void addHighJumps ( const std::string& player, unsigned int highJumps ) ;

        void decreaseHighJumps ( const std::string& player ) ;

        void addShield ( const std::string& player, float shield ) ;

        void modifyShield ( const std::string& player, float shield ) ;

        void emptyHandbag () {  setImageOfItemInBag( PicturePtr () ) ;  }

        /**
         * Image of the item inside hand bag
         */
        void setImageOfItemInBag ( const PicturePtr & pic ) {  this->imageOfItemInBag = pic ;  }

        void resetPlanets () ;

        /**
         * Libera un planeta
         * @param planet Planet to liberate
         * @param now Whether is it just liberated or was already liberated in previous game
         */
        void liberatePlanet ( const std::string& planet, bool now = true ) ;

        /**
         * Indica si un planeta es libre
         * @param planet Planet in question
         * @return true if you took planet’s crown or false otherwise
         */
        bool isFreePlanet ( const std::string& planet ) const ;

        /**
         * How many planets are already liberated
         */
        unsigned short countFreePlanets () const ;

        /**
         * Eat fish, that is, begin the process to save the game
         */
        void eatFish ( const PlayerItem & character, Room * room ) ;

        void eatFish ( const PlayerItem & character, Room * room, int x, int y, int z ) ;

        std::string getChosenGraphicSet () const {  return chosenGraphicSet ;  }

        void setChosenGraphicSet ( const std::string & newSet ) {  chosenGraphicSet = newSet ;  }

        bool isPresentGraphicSet () const {  return ( chosenGraphicSet == "gfx" ) ;  }

        bool isSimpleGraphicSet () const {  return ( chosenGraphicSet == "gfx.simple" ) ;  }

private:

        /**
         * Update game periodically by redrawing isometric view and updating items
         * @return reason why update was paused
         */
        WhyPaused update () ;

        void refreshAmbianceImages () ;

        void refreshSceneryBackgrounds () ;

public:

        bool areLivesInexhaustible () const {  return vidasInfinitas ;  }

        void toggleInfiniteLives () {  vidasInfinitas = ! vidasInfinitas ;  }

        bool isImmuneToCollisionsWithMortalItems () const {  return immunityToCollisions ;  }

        void toggleImmunityToCollisionsWithMortalItems () {  immunityToCollisions = ! immunityToCollisions ;  }

        bool charactersFly () const {  return noFallingDown ;  }

        void setCharactersFly ( bool fly ) {  noFallingDown = fly ;  }

        bool playMelodyOfScenery () const {  return playTuneOfScenery ;  }

        void togglePlayMelodyOfScenery () {  playTuneOfScenery = ! playTuneOfScenery ;  }

        bool getCastShadows () const {  return castShadows ;  }

        void toggleCastShadows () {  castShadows = ! castShadows ;  }

        bool hasBackgroundPicture () const {  return drawBackgroundPicture ;  }

        void toggleBackgroundPicture () {  drawBackgroundPicture = ! drawBackgroundPicture ;  }

        bool recordingCaptures () const {  return recordCaptures ;  }

        void toggleRecordingCaptures ()
        {
                recordingTimer->reset () ;
                recordCaptures = ! recordCaptures ;

                if ( recordCaptures )
                        prefixOfCaptures = makeRandomString( 10 );
                else
                        numberOfCapture += 1000 ;
        }

private:

        static GameManager instance ;

        std::string headRoom ;

        std::string heelsRoom ;

        gui::ColorCyclingLabel * freedomLabel ;

        unsigned int numberOfCapture ;

        std::string prefixOfCaptures ;

        std::string capturePath ;

        std::string chosenGraphicSet ;

        bool vidasInfinitas ;

        bool immunityToCollisions ;

        bool noFallingDown ;

        bool playTuneOfScenery ;

        bool castShadows ;

        bool drawBackgroundPicture ;

        bool recordCaptures ;

        autouniqueptr < Timer > recordingTimer ;

        Isomot isomot ;

        GameSaverAndLoader saverAndLoader ; // to save and restore games

        unsigned char headLives ;

        unsigned char heelsLives ;

        // the remaining time of bonus high speed for Head
        unsigned int highSpeed ;

        // the number of remaining bonus high jumps for Heels
        unsigned int highJumps ;

        // the remaining time of Head's inviolability
        float headShield ;

        // the remaining time of Heels' inviolability
        float heelsShield ;

        // does Head have the doughnut horn
        bool horn ;

        // does Heels have the hand bag
        bool handbag ;

        // the number of donuts collected by Head
        unsigned short donuts ;

        TheKeyMoments keyMoments ;

        PicturePtr imageOfItemInBag ;

        std::map < std::string /* the planet's name */, bool /* is free or not */ > planets ;

        std::map < std::string, PicturePtr > sceneryBackgrounds ;

        std::map < std::string, PicturePtr > ambiancePictures ;

public:

        Isomot & getIsomot () {  return isomot ;  }

        /**
         * Returns the number of lives left for player
         */
        unsigned char getLives ( const std::string& player ) const ;

        void setHeadLives ( unsigned char lives ) {  this->headLives = lives ;  }

        void setHeelsLives ( unsigned char lives ) {  this->heelsLives = lives ;  }

        void setHighSpeed ( unsigned int highSpeed ) {  this->highSpeed = highSpeed ;  }

        unsigned int getHighSpeed () const {  return this->highSpeed;  }

        void setHighJumps ( unsigned int highJumps ) {  this->highJumps = highJumps ;  }

        unsigned int getHighJumps () const {  return this->highJumps ;  }

        void setHeadShield ( unsigned int shield ) {  this->headShield = shield ;  }

        void setHeelsShield ( unsigned int shield ) {  this->heelsShield = shield ;  }

        float getShield ( const std::string& player ) const ;

        void setHorn ( bool hasHorn ) {  this->horn = hasHorn ;  }

        void setHandbag ( bool hasHandbag ) {  this->handbag = hasHandbag ;  }

        void fillToolsOwnedByCharacter ( const std::string& player, std::vector < std::string > & tools ) const ;

        void setDonuts ( unsigned short number ) {  this->donuts = number ;  }

        unsigned short getDonuts ( const std::string& player ) const ;

        unsigned int getVisitedRooms () ;

        // at the end of the game it's time to count the crowns
        void inFreedomWithSoManyCrowns( unsigned int crowns ) ;

};

}

#endif

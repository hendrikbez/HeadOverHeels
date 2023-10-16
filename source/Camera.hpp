// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef Camera_hpp_
#define Camera_hpp_

#include "Item.hpp"


namespace iso
{

class Offset2D
{

private:

        int offsetX ;
        int offsetY ;

public:

        int getX () const {  return offsetX ;  }
        int getY () const {  return offsetY ;  }

        void setX ( int x ) {  offsetX = x ;  }
        void setY ( int y ) {  offsetY = y ;  }

        void addToX ( int dx ) {  offsetX += dx ;  }
        void addToY ( int dy ) {  offsetY += dy ;  }

        Offset2D() : offsetX( 0 ) , offsetY( 0 ) {}
        Offset2D( int x, int y ) : offsetX( x ) , offsetY( y ) {}

        Offset2D( const Offset2D & toCopy ) : offsetX( toCopy.offsetX ) , offsetY( toCopy.offsetY ) {}

        bool operator == ( const Offset2D & toCompare ) const {  return   equals( toCompare ) ;  }
        bool operator != ( const Offset2D & toCompare ) const {  return ! equals( toCompare ) ;  }

        bool equals ( const Offset2D & toCompare ) const
        {
                return toCompare.offsetX == offsetX && toCompare.offsetY == offsetY ;
        }

} ;

typedef Offset2D CameraOffset ;


class Room ;

/**
 * The camera deals with the offset of the room's image
 */

class Camera
{
private:

        /**
         * La sala objetivo de la cámara
         */
        Room * room ;

        CameraOffset offset ;

        CameraOffset roomCenterOffset ;

        static const unsigned int spaceForAmbiance = 100 ;

public:

        Camera( Room * room ) ;

        virtual ~Camera( ) { }

        const CameraOffset & getOffset () const {  return offset ;  }

        void setOffsetX ( int x ) {  this->offset.setX( x );  }

        void setOffsetY ( int y ) {  this->offset.setY( y );  }

        void shiftAlongX ( int dx ) {  this->offset.addToX( dx );  }

        void shiftAlongY ( int dy ) {  this->offset.addToY( dy );  }

        const CameraOffset & getOffsetToRoomCenter () const {  return roomCenterOffset ;  }

        /** @return false if the new offset is the same as the current one */
        bool softShiftTo ( const CameraOffset & newOffset ) ;

        /** @return whether camera has moved */
        bool softCenterRoom () ;

        void instantCenterRoom () ;

        void recenterRoom () ;

        /** @return whether camera has moved */
        bool centerOnItem ( const Item & item ) ;

} ;

}

#endif

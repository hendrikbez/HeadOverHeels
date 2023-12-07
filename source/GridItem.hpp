// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef GridItem_hpp_
#define GridItem_hpp_

#include <string>

#include "WrappersAllegro.hpp"

#include "Picture.hpp"
#include "Item.hpp"
#include "Drawable.hpp"


class DescriptionOfItem ;

/**
 * The grid items are those which are placed in a particular position and have the same widths
 * as the grid cells have. Grid items are mostly static. You can only change the Z coordinate
 * of a grid item, but can’t change the X and Y coordinates
 */

class GridItem : public Item, public Drawable
{

public:

        /**
         * @param description Description of item
         * @param cx Position on X of the cell in room where this item is
         * @param cy Position on Y of the cell in room where this item is
         * @param z Position on Z, or how far is floor
         * @param way Initial orientation of item
         */
        GridItem( const DescriptionOfItem * description, int cx, int cy, int z, const std::string& way ) ;

        virtual ~GridItem( ) ;

        virtual std::string whichItemClass () const {  return "grid item" ;  }

        /**
         * for sorting grid items in a container
         */
        bool operator < ( const GridItem & other ) const
        {
                return ( getZ() < other.getZ() + other.getHeight_Signed() );
        }

        bool isSegmentOfWallOnX () const
                {  return getOriginalKind().find( "wall-x" ) != std::string::npos &&
                                getOriginalKind().find( "invisible-wall" ) == std::string::npos ;  }

        bool isSegmentOfWallOnY () const
                {  return getOriginalKind().find( "wall-y" ) != std::string::npos &&
                                getOriginalKind().find( "invisible-wall" ) == std::string::npos ;  }

        virtual int getImageOffsetX () const {  return imageOffset.first ;  }
        virtual int getImageOffsetY () const {  return imageOffset.second ;  }

        /**
         * Draw this grid item
         */
        virtual void draw () ;

        virtual bool addToPosition ( int x, int y, int z ) ;

        /**
         * The X of the cell in the room where this item is
         */
        int getCellX () const {  return cell.first ;  }

        /**
         * The Y of the cell in the room where this item is
         */
        int getCellY () const {  return cell.second ;  }

        unsigned int getColumnOfGrid () const ;

        void updateImageOffset () ;

private:

        /**
         * Position ( X, Y ) of the cell in the room where this item is
         */
        std::pair < int, int > cell ;

        /**
         * The offset on ( X, Y ) of processed image from the room’s origin
         */
        std::pair < int, int > imageOffset ;

        virtual void updateImage () ;

        virtual void updateShadow () ;

};

typedef multiptr < GridItem > GridItemPtr ;

#endif

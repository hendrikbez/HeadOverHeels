
#include "Miniature.hpp"

#include "Color.hpp"
#include "FlickeringColor.hpp"
#include "GameManager.hpp"
#include "GameMap.hpp"
#include "Room.hpp"
#include "ConnectedRooms.hpp"
#include "Mediator.hpp"
#include "DescriptionOfItem.hpp"


Miniature::Miniature( const Room& roomForMiniature, int leftX, int topY, unsigned int sizeOfTileForMiniature )
        : room( roomForMiniature )
        , sizeOfTile( sizeOfTileForMiniature )
        , offset( std::pair< int, int >( leftX, topY ) )
{
        if ( sizeOfTile < 2 ) sizeOfTile = 2 ;
}

void Miniature::draw ()
{
        const ConnectedRooms * connections = room.getConnections() ;
        assert( connections != nilPointer );

        std::string roomAbove = connections->getConnectedRoomAt( "above" );
        std::string roomBelow = connections->getConnectedRoomAt( "below" );
        std::string roomToTeleport = connections->getConnectedRoomAt( "via teleport" );
        std::string roomToTeleportToo = connections->getConnectedRoomAt( "via second teleport" );

        const unsigned int tilesX = room.getTilesOnX ();
        const unsigned int tilesY = room.getTilesOnY ();

        const int deltaX = offset.first ;
        const int deltaY = offset.second + ( roomAbove.empty() ? 4 : ( 3 * sizeOfTile ) );

        const int originX = deltaX + ( tilesY * ( sizeOfTile << 1 ) );
        const int originY = deltaY + ( sizeOfTile << 1 );

        unsigned int firstTileX = 0;
        unsigned int firstTileY = 0;
        unsigned int lastTileX = tilesX - 1;
        unsigned int lastTileY = tilesY - 1;

        Door* eastDoor = room.getDoorOn( "east" );
        Door* southDoor = room.getDoorOn( "south" );
        Door* northDoor = room.getDoorOn( "north" );
        Door* westDoor = room.getDoorOn( "west" );

        Door* eastnorthDoor = room.getDoorOn( "eastnorth" );
        Door* eastsouthDoor = room.getDoorOn( "eastsouth" );
        Door* southeastDoor = room.getDoorOn( "southeast" );
        Door* southwestDoor = room.getDoorOn( "southwest" );
        Door* northeastDoor = room.getDoorOn( "northeast" );
        Door* northwestDoor = room.getDoorOn( "northwest" );
        Door* westnorthDoor = room.getDoorOn( "westnorth" );
        Door* westsouthDoor = room.getDoorOn( "westsouth" );

        if ( northDoor != nilPointer || northeastDoor != nilPointer || northwestDoor != nilPointer )
                firstTileX++ ;

        if ( eastDoor != nilPointer || eastnorthDoor != nilPointer || eastsouthDoor != nilPointer )
                firstTileY++ ;

        if ( southDoor != nilPointer || southeastDoor != nilPointer || southwestDoor != nilPointer )
                lastTileX --;

        if ( westDoor != nilPointer || westnorthDoor != nilPointer || westsouthDoor != nilPointer )
                lastTileY --;

        bool narrowRoomAlongX = ( lastTileY == firstTileY + 1 ) ;
        bool narrowRoomAlongY = ( lastTileX == firstTileX + 1 ) ;

        const allegro::Pict& where = allegro::Pict::getWhereToDraw() ;

        const Color& roomColor = Color::byName( room.getColor () );

        // draw doors

        if ( eastDoor != nilPointer && ! narrowRoomAlongY )
        {
                unsigned int eastDoorXmid = eastDoor->getCellX() + 1 ;
                drawEastDoorOnMiniature( where,
                        originX, originY,
                        eastDoorXmid, eastDoor->getCellY(),
                        roomColor.multiply( Color::whiteColor() ) );
        }
        if ( eastnorthDoor != nilPointer )
        {
                unsigned int eastnorthDoorXmid = eastnorthDoor->getCellX() + 1 ;
                drawEastDoorOnMiniature( where,
                        originX, originY,
                        eastnorthDoorXmid, eastnorthDoor->getCellY(),
                        roomColor.multiply( Color::whiteColor() ) );
        }
        if ( eastsouthDoor != nilPointer )
        {
                unsigned int eastsouthDoorXmid = eastsouthDoor->getCellX() + 1 ;
                drawEastDoorOnMiniature( where,
                        originX, originY,
                        eastsouthDoorXmid, eastsouthDoor->getCellY(),
                        roomColor.multiply( Color::whiteColor() ) );
        }

        if ( northDoor != nilPointer && ! narrowRoomAlongX )
        {
                unsigned int northDoorYmid = northDoor->getCellY() + 1 ;
                drawNorthDoorOnMiniature( where,
                        originX, originY,
                        northDoor->getCellX(), northDoorYmid,
                        roomColor.multiply( Color::whiteColor() ) );
        }
        if ( northeastDoor != nilPointer )
        {
                unsigned int northeastDoorYmid = northeastDoor->getCellY() + 1 ;
                drawNorthDoorOnMiniature( where,
                        originX, originY,
                        northeastDoor->getCellX(), northeastDoorYmid,
                        roomColor.multiply( Color::whiteColor() ) );
        }
        if ( northwestDoor != nilPointer )
        {
                unsigned int northwestDoorYmid = northwestDoor->getCellY() + 1 ;
                drawNorthDoorOnMiniature( where,
                        originX, originY,
                        northwestDoor->getCellX(), northwestDoorYmid,
                        roomColor.multiply( Color::whiteColor() ) );
        }

        if ( westDoor != nilPointer && ! narrowRoomAlongY )
        {
                unsigned int westDoorXmid = westDoor->getCellX() + 1 ;
                drawWestDoorOnMiniature( where,
                        originX, originY,
                        westDoorXmid, westDoor->getCellY(),
                        roomColor.multiply( Color::whiteColor() ) );
        }
        if ( westnorthDoor != nilPointer )
        {
                unsigned int westnorthDoorXmid = westnorthDoor->getCellX() + 1 ;
                drawWestDoorOnMiniature( where,
                        originX, originY,
                        westnorthDoorXmid, westnorthDoor->getCellY(),
                        roomColor.multiply( Color::whiteColor() ) );
        }
        if ( westsouthDoor != nilPointer )
        {
                unsigned int westsouthDoorXmid = westsouthDoor->getCellX() + 1 ;
                drawWestDoorOnMiniature( where,
                        originX, originY,
                        westsouthDoorXmid, westsouthDoor->getCellY(),
                        roomColor.multiply( Color::whiteColor() ) );
        }

        if ( southDoor != nilPointer && ! narrowRoomAlongX )
        {
                unsigned int southDoorYmid = southDoor->getCellY() + 1 ;
                drawSouthDoorOnMiniature( where,
                        originX, originY,
                        southDoor->getCellX(), southDoorYmid,
                        roomColor.multiply( Color::whiteColor() ) );
        }
        if ( southeastDoor != nilPointer )
        {
                unsigned int southeastDoorYmid = southeastDoor->getCellY() + 1 ;
                drawSouthDoorOnMiniature( where,
                        originX, originY,
                        southeastDoor->getCellX(), southeastDoorYmid,
                        roomColor.multiply( Color::whiteColor() ) );
        }
        if ( southwestDoor != nilPointer )
        {
                unsigned int southwestDoorYmid = southwestDoor->getCellY() + 1 ;
                drawSouthDoorOnMiniature( where,
                        originX, originY,
                        southwestDoor->getCellX(), southwestDoorYmid,
                        roomColor.multiply( Color::whiteColor() ) );
        }

        // draw boundaries of room

        drawIsoSquare( where, originX, originY, tilesX, tilesY, roomColor.multiply( Color::byName( "gray" ) ) );

        // draw walls

        int minXne = firstTileX ;
        int minYne = firstTileY ;
        int maxXsw = lastTileX ;
        int maxYsw = lastTileY ;

        ////room.getMediator()->lockGridItemsMutex ();

        const std::vector< std::vector< GridItemPtr > > & gridItemsInRoom = room.getGridItems();

        for ( unsigned int column = 0; column < gridItemsInRoom.size(); column ++ )
        {
                for ( std::vector< GridItemPtr >::const_iterator gi = gridItemsInRoom[ column ].begin (); gi != gridItemsInRoom[ column ].end (); ++ gi )
                {
                        const GridItem & item = *( *gi ) ;

                        std::string kind = item.getKind ();
                        int tileX = item.getCellX();
                        int tileY = item.getCellY();

                        if ( kind == "invisible-wall-x" )
                        {
                                int newPos = tileY - 1 ;
                                if ( newPos < maxYsw ) maxYsw = newPos ;
                        }
                        else if ( kind.find( "wall-x" ) != std::string::npos )
                        {
                                int newPos = tileY + 1 ;
                                if ( newPos > minYne ) minYne = newPos ;
                        }

                        if ( kind == "invisible-wall-y" )
                        {
                                int newPos = tileX - 1 ;
                                if ( newPos < maxXsw ) maxXsw = newPos ;
                        }
                        else if ( kind.find( "wall-y" ) != std::string::npos )
                        {
                                int newPos = tileX + 1 ;
                                if ( newPos > minXne ) minXne = newPos ;
                        }
                }
        }

        ////room.getMediator()->unlockGridItemsMutex ();

        for ( unsigned int unsignedTileX = firstTileX ; unsignedTileX <= lastTileX ; unsignedTileX ++ )
        {
                int tileX = static_cast< int >( unsignedTileX );

                if ( tileX >= minXne )
                {
                        if ( ! ( eastDoor != nilPointer && ( tileX == eastDoor->getCellX() + 1 || tileX == eastDoor->getCellX() ) ) &&
                                ! ( eastnorthDoor != nilPointer && ( tileX == eastnorthDoor->getCellX() + 1 || tileX == eastnorthDoor->getCellX() ) ) &&
                                ! ( eastsouthDoor != nilPointer && ( tileX == eastsouthDoor->getCellX() + 1 || tileX == eastsouthDoor->getCellX() ) ) )
                        {
                                drawIsoTile (
                                        where, originX, originY,
                                        unsignedTileX, firstTileY,
                                        roomColor.multiply( Color::whiteColor() ),
                                        true, false, false, false );
                        }
                }

                if ( tileX <= maxXsw )
                {
                        if ( ! ( westDoor != nilPointer && ( tileX == westDoor->getCellX() + 1 || tileX == westDoor->getCellX() ) ) &&
                                ! ( westnorthDoor != nilPointer && ( tileX == westnorthDoor->getCellX() + 1 || tileX == westnorthDoor->getCellX() ) ) &&
                                ! ( westsouthDoor != nilPointer && ( tileX == westsouthDoor->getCellX() + 1 || tileX == westsouthDoor->getCellX() ) ) )
                        {
                                drawIsoTile (
                                        where, originX, originY,
                                        unsignedTileX, lastTileY,
                                        roomColor.multiply( Color::whiteColor() ),
                                        false, false, true, false );
                        }
                }

                if ( narrowRoomAlongX )
                {
                        if ( northDoor != nilPointer )
                        {
                                drawIsoTile ( where, originX, originY, 0, firstTileY,
                                                roomColor.multiply( Color::byName( "gray 75% white" ) ),
                                                true, false, false, false );

                                drawIsoTile ( where, originX, originY, 0, lastTileY,
                                                roomColor.multiply( Color::byName( "gray 75% white" ) ),
                                                false, false, true, false );
                        }

                        if ( southDoor != nilPointer )
                        {
                                drawIsoTile ( where, originX, originY, tilesX - 1, firstTileY,
                                                roomColor.multiply( Color::byName( "gray 75% white" ) ),
                                                true, false, false, false );

                                drawIsoTile ( where, originX, originY, tilesX - 1, lastTileY,
                                                roomColor.multiply( Color::byName( "gray 75% white" ) ),
                                                false, false, true, false );
                        }
                }
        }

        for ( unsigned int unsignedTileY = firstTileY ; unsignedTileY <= lastTileY ; unsignedTileY ++ )
        {
                int tileY = static_cast< int >( unsignedTileY );

                if ( tileY <= maxYsw )
                {
                        if ( ! ( southDoor != nilPointer && ( tileY == southDoor->getCellY() + 1 || tileY == southDoor->getCellY() ) ) &&
                                ! ( southeastDoor != nilPointer && ( tileY == southeastDoor->getCellY() + 1 || tileY == southeastDoor->getCellY() ) ) &&
                                ! ( southwestDoor != nilPointer && ( tileY == southwestDoor->getCellY() + 1 || tileY == southwestDoor->getCellY() ) ) )
                        {
                                drawIsoTile (
                                        where, originX, originY,
                                        lastTileX, unsignedTileY,
                                        roomColor.multiply( Color::whiteColor() ),
                                        false, false, false, true );
                        }
                }

                if ( tileY >= minYne )
                {
                        if ( ! ( northDoor != nilPointer && ( tileY == northDoor->getCellY() + 1 || tileY == northDoor->getCellY() ) ) &&
                                ! ( northeastDoor != nilPointer && ( tileY == northeastDoor->getCellY() + 1 || tileY == northeastDoor->getCellY() ) ) &&
                                ! ( northwestDoor != nilPointer && ( tileY == northwestDoor->getCellY() + 1 || tileY == northwestDoor->getCellY() ) ) )
                        {
                                drawIsoTile (
                                        where, originX, originY,
                                        firstTileX, unsignedTileY,
                                        roomColor.multiply( Color::whiteColor() ),
                                        false, true, false, false );
                        }
                }

                if ( narrowRoomAlongY )
                {
                        if ( eastDoor != nilPointer )
                        {
                                drawIsoTile ( where, originX, originY, firstTileX, 0,
                                                roomColor.multiply( Color::byName( "gray 75% white" ) ),
                                                false, true, false, false );

                                drawIsoTile ( where, originX, originY, lastTileX, 0,
                                                roomColor.multiply( Color::byName( "gray 75% white" ) ),
                                                false, false, false, true );
                        }

                        if ( westDoor != nilPointer )
                        {
                                drawIsoTile ( where, originX, originY, firstTileX, tilesY - 1,
                                                roomColor.multiply( Color::byName( "gray 75% white" ) ),
                                                false, true, false, false );

                                drawIsoTile ( where, originX, originY, lastTileX, tilesY - 1,
                                                roomColor.multiply( Color::byName( "gray 75% white" ) ),
                                                false, false, false, true );
                        }
                }
        }

        ////room.getMediator()->lockGridItemsMutex ();

        for ( unsigned int column = 0; column < gridItemsInRoom.size(); column ++ )
        {
                const std::vector< GridItemPtr >& columnOfItems = gridItemsInRoom[ column ];

                for ( std::vector< GridItemPtr >::const_iterator gi = columnOfItems.begin (); gi != columnOfItems.end (); ++ gi )
                {
                        const GridItem& item = *( *gi ) ;

                        std::string kind = item.getKind ();
                        int tileX = item.getCellX();
                        int tileY = item.getCellY();

                        // show teleports

                        if ( kind == "teleport" && ! roomToTeleport.empty() )
                        {
                                fillIsoTile( where, originX, originY, tileX, tileY, Color::byName( "yellow" ) );
                        }
                        else if ( kind == "teleport-too" && ! roomToTeleportToo.empty() )
                        {
                                fillIsoTile( where, originX, originY, tileX, tileY, Color::byName( "magenta" ) );
                        }

                        // show triple room’s walls

                        if ( kind.find( "wall-x" ) != std::string::npos )
                        {
                                if ( kind.find( "invisible-wall" ) != std::string::npos )
                                        drawIsoTile( where,
                                                        originX, originY,
                                                        tileX, tileY,
                                                        roomColor.multiply( Color::whiteColor() ),
                                                        true, false, false, false );
                                else
                                        drawIsoTile( where,
                                                        originX, originY,
                                                        tileX, tileY,
                                                        roomColor.multiply( Color::whiteColor() ),
                                                        false, false, true, false );
                        }
                        if ( kind.find( "wall-y" ) != std::string::npos )
                        {
                                if ( kind.find( "invisible-wall" ) != std::string::npos )
                                        drawIsoTile( where,
                                                        originX, originY,
                                                        tileX, tileY,
                                                        roomColor.multiply( Color::whiteColor() ),
                                                        false, true, false, false );
                                else
                                        drawIsoTile( where,
                                                        originX, originY,
                                                        tileX, tileY,
                                                        roomColor.multiply( Color::whiteColor() ),
                                                        false, false, false, true );
                        }
                }
        }

        ////room.getMediator()->unlockGridItemsMutex ();

        ////room.getMediator()->lockFreeItemsMutex ();

        const std::vector< FreeItemPtr > & freeItemsInRoom = room.getFreeItems();

        for ( std::vector< FreeItemPtr >::const_iterator fi = freeItemsInRoom.begin (); fi != freeItemsInRoom.end (); ++ fi )
        {
                if ( *fi == nilPointer || ( *fi )->whichItemClass() == "avatar item" ) continue ;
                const FreeItem & item = *( *fi ) ;

                const DescriptionOfItem & descriptionOfItem = item.getDescriptionOfItem () ;
                const std::string & kind = descriptionOfItem.getKind ();

                // show tools

                if ( kind == "handbag" || kind == "horn" || kind == "donuts" )
                {
                        unsigned int roomTileSize = room.getSizeOfOneTile() ;

                        // free coordinates to tile coordinates
                        int tileX = ( item.getX() - ( ( roomTileSize - descriptionOfItem.getWidthX() ) >> 1 ) ) / roomTileSize ;
                        int tileY = ( ( item.getY() + ( ( roomTileSize - descriptionOfItem.getWidthY() ) >> 1 ) + 1 ) / roomTileSize ) - 1 ;

                        fillIsoTile( where, originX, originY, tileX, tileY, Color::byName( "orange" ) );
                }

                // show rabbit bonuses

                if ( kind == "extra-life" || kind == "high-jumps" || kind == "quick-steps" || kind == "shield" )
                {
                        unsigned int roomTileSize = room.getSizeOfOneTile() ;

                        // free coordinates to tile coordinates
                        int tileX = ( item.getX() - ( ( roomTileSize - descriptionOfItem.getWidthX() ) >> 1 ) ) / roomTileSize ;
                        int tileY = ( ( item.getY() + ( ( roomTileSize - descriptionOfItem.getWidthY() ) >> 1 ) + 1 ) / roomTileSize ) - 1 ;

                        fillIsoTile( where, originX, originY, tileX, tileY, Color::byName( "cyan" ) );
                }

                // show fish

                if ( kind == "reincarnation-fish" || kind == "mortal-fish" )
                {
                        unsigned int roomTileSize = room.getSizeOfOneTile() ;

                        // free coordinates to tile coordinates
                        int tileX = ( item.getX() - ( ( roomTileSize - descriptionOfItem.getWidthX() ) >> 1 ) ) / roomTileSize ;
                        int tileY = ( ( item.getY() + ( ( roomTileSize - descriptionOfItem.getWidthY() ) >> 1 ) + 1 ) / roomTileSize ) - 1 ;

                        if ( kind == "reincarnation-fish" )
                                fillIsoTile( where, originX, originY, tileX, tileY, Color::byName( "green" ) );
                        else if ( kind == "mortal-fish" )
                                fillIsoTile( where, originX, originY, tileX, tileY, Color::byName( "red" ) );
                }
        }

        ////room.getMediator()->unlockFreeItemsMutex ();

        // show characters in room

        const std::vector< AvatarItemPtr >& charactersInRoom = room.getCharactersYetInRoom() ;

        for ( std::vector< AvatarItemPtr >::const_iterator pi = charactersInRoom.begin (); pi != charactersInRoom.end (); ++ pi )
        {
                const AvatarItem & character = *( *pi ) ;

                unsigned int roomTileSize = room.getSizeOfOneTile() ;

                // the range of tiles where the character is
                int xBegin = character.getX() / roomTileSize;
                int xEnd = ( character.getX() + character.getWidthX() - 1 ) / roomTileSize;
                int yBegin = ( character.getY() - character.getWidthY() + 1 ) / roomTileSize;
                int yEnd = character.getY() / roomTileSize;

                /* for ( int x = xBegin ; x <= xEnd ; ++ x )
                        for ( int y = yBegin ; y <= yEnd ; ++ y )
                                drawIsoTile( where, originX, originY, x, y, Color::byName( "blue" ), true, true, true, true ) ; */

                int deltaWx = ( roomTileSize - character.getWidthX() ) >> 1 ;
                int deltaWy = ( roomTileSize - character.getWidthY() ) >> 1 ;

                int tileX = ( character.getX() > deltaWx ) ? ( character.getX() - deltaWx ) / roomTileSize : 0 ;
                int tileY = ( ( character.getY() + deltaWy + 1 ) / roomTileSize ) - 1 ;
                if ( tileY < 0 ) tileY = 0 ;

                if ( xBegin == xEnd && yBegin == yEnd )
                {
                        tileX = xBegin ;
                        tileY = yEnd ;
                }
                else
                {
                        if ( tileX < xBegin ) tileX = xBegin ;
                        else if ( tileX > xEnd ) tileX = xEnd ;

                        if ( tileY < yBegin ) tileY = yBegin ;
                        else if ( tileY > yEnd ) tileY = yEnd ;
                }

                fillIsoTileInside( where,
                        originX, originY, tileX, tileY,
                        character.isActiveCharacter() ? FlickeringColor::flickerWhiteAndTransparent() : FlickeringColor::flickerGray75AndTransparent(),
                        true );
        }

        // show when there’s a room above or below

        if ( ! roomAbove.empty() || ! roomBelow.empty() )
        {
                int miniatureMidX = deltaX + ( tilesY + tilesX ) * sizeOfTile ;
                int aboveY = originY - 2 ;
                int belowY = originY + ( tilesY + tilesX ) * sizeOfTile ;
                aboveY -= sizeOfTile << 1 ;
                belowY += sizeOfTile << 1 ;

                drawVignetteForRoomAboveOrBelow( where, miniatureMidX, aboveY, belowY, Color::byName( "green" ).toAllegroColor(), roomAbove, roomBelow );
        }

        // paint final room

        if ( room.getNameOfRoomDescriptionFile() == "finalroom.xml" )
        {
                for ( unsigned int x = 0 ; x < tilesX ; ++ x )
                {
                        for ( unsigned int y = 0 ; y < tilesY ; ++ y )
                        {
                                drawIsoTile( where, originX, originY, x, y, Color::byName( "green" ), true, true, true, true ) ;
                                fillIsoTileInside( where, originX, originY, x, y, Color::byName( "yellow" ), true ) ;
                        }
                }
        }
}

void Miniature::drawVignetteForRoomAboveOrBelow( const allegro::Pict& where, int midX, int aboveY, int belowY, const Color& color, const std::string& roomAbove, const std::string& roomBelow )
{
        if ( color.isFullyTransparent () ) return ;

        if ( roomAbove.empty() && roomBelow.empty() ) return ;

        const allegro::Pict& previousWhere = allegro::Pict::getWhereToDraw() ;
        allegro::Pict::setWhereToDraw( where );

        const unsigned int linesEven = ( ( sizeOfTile + 1 ) >> 1 ) << 1;

        if ( ! roomAbove.empty() )
        {
                // draw middle line
                allegro::drawLine( midX, aboveY - linesEven + 1, midX, aboveY - ( linesEven << 1 ), color.toAllegroColor() );

                int pos = 0;
                for ( unsigned int off = linesEven ; off > 0 ; off -- , pos ++ )
                {
                        allegro::drawLine( midX - off, aboveY - pos, midX - off, aboveY - pos - linesEven, color.toAllegroColor() );
                        allegro::drawLine( midX + off, aboveY - pos, midX + off, aboveY - pos - linesEven, color.toAllegroColor() );
                }
        }

        if ( ! roomBelow.empty() )
        {
                // draw middle line
                allegro::drawLine( midX, belowY + linesEven - 1, midX, belowY + ( linesEven << 1 ), color.toAllegroColor() );

                int pos = 0;
                for ( unsigned int off = linesEven ; off > 0 ; off -- , pos ++ )
                {
                        allegro::drawLine( midX - off, belowY + pos, midX - off, belowY + pos + linesEven, color.toAllegroColor() );
                        allegro::drawLine( midX + off, belowY + pos, midX + off, belowY + pos + linesEven, color.toAllegroColor() );
                }
        }

        allegro::Pict::setWhereToDraw( previousWhere );
}

void Miniature::drawEastDoorOnMiniature( const allegro::Pict& where, int x0, int y0, unsigned int tilesX, unsigned int tilesY, const Color& color )
{
        if ( color.isFullyTransparent () ) return ;

        drawIsoTile( where, x0, y0, tilesX - 1, tilesY, color, false, true, false, false );

        {
                int x = x0 + ( ( tilesX - 1 ) - ( tilesY + 1 ) ) * ( sizeOfTile << 1 ) ;
                int y = y0 + ( ( tilesY + 1 ) + ( tilesX - 1 ) ) * sizeOfTile ;
                where.drawPixelAt( x, y, color.toAllegroColor() );
                where.drawPixelAt( x + 1, y, color.toAllegroColor() );
        }

        drawIsoTile( where, x0, y0, tilesX, tilesY, color, false, false, false, true );

        {
                int x = x0 + ( ( tilesX + 1 ) - ( tilesY + 1 ) ) * ( sizeOfTile << 1 ) ;
                int y = y0 + ( ( tilesY + 1 ) + ( tilesX + 1 ) ) * sizeOfTile ;
                where.drawPixelAt( x - 2, y - 1, color.toAllegroColor() );
                where.drawPixelAt( x - 1, y - 1, color.toAllegroColor() );
        }
}

void Miniature::drawWestDoorOnMiniature( const allegro::Pict& where, int x0, int y0, unsigned int tilesX, unsigned int tilesY, const Color& color )
{
        if ( color.isFullyTransparent () ) return ;

        drawIsoTile( where, x0, y0, tilesX - 1, tilesY, color, false, true, false, false );

        {
                int x = x0 + ( ( tilesX - 1 ) - tilesY ) * ( sizeOfTile << 1 ) ;
                int y = y0 + ( tilesY + ( tilesX - 1 ) ) * sizeOfTile ;
                where.drawPixelAt( x + 2, y - 1, color.toAllegroColor() );
                where.drawPixelAt( x + 3, y - 1, color.toAllegroColor() );
        }

        drawIsoTile( where, x0, y0, tilesX, tilesY, color, false, false, false, true );

        {
                int x = x0 + ( ( tilesX + 1 ) - tilesY ) * ( sizeOfTile << 1 ) ;
                int y = y0 + ( tilesY + ( tilesX + 1 ) ) * sizeOfTile ;
                where.drawPixelAt( x, y - 2, color.toAllegroColor() );
                where.drawPixelAt( x + 1, y - 2, color.toAllegroColor() );
        }
}

void Miniature::drawNorthDoorOnMiniature( const allegro::Pict& where, int x0, int y0, unsigned int tilesX, unsigned int tilesY, const Color& color )
{
        if ( color.isFullyTransparent () ) return ;

        drawIsoTile( where, x0, y0, tilesX, tilesY - 1, color, true, false, false, false );

        {
                int x = x0 + ( ( tilesX + 1 ) - ( tilesY - 1 ) ) * ( sizeOfTile << 1 ) ;
                int y = y0 + ( ( tilesY - 1 ) + ( tilesX + 1 ) ) * sizeOfTile ;
                where.drawPixelAt( x, y, color.toAllegroColor() );
                where.drawPixelAt( x + 1, y, color.toAllegroColor() );
        }

        drawIsoTile( where, x0, y0, tilesX, tilesY, color, false, false, true, false );

        {
                int x = x0 + ( ( tilesX + 1 ) - ( tilesY + 1 ) ) * ( sizeOfTile << 1 ) ;
                int y = y0 + ( ( tilesY + 1 ) + ( tilesX + 1 ) ) * sizeOfTile ;
                where.drawPixelAt( x + 2, y - 1, color.toAllegroColor() );
                where.drawPixelAt( x + 3, y - 1, color.toAllegroColor() );
        }
}

void Miniature::drawSouthDoorOnMiniature( const allegro::Pict& where, int x0, int y0, unsigned int tilesX, unsigned int tilesY, const Color& color )
{
        if ( color.isFullyTransparent () ) return ;

        drawIsoTile( where, x0, y0, tilesX, tilesY - 1, color, true, false, false, false );

        {
                int x = x0 + ( tilesX - ( tilesY - 1 ) ) * ( sizeOfTile << 1 ) ;
                int y = y0 + ( ( tilesY - 1 ) + tilesX ) * sizeOfTile ;
                where.drawPixelAt( x - 2, y - 1, color.toAllegroColor() );
                where.drawPixelAt( x - 1, y - 1, color.toAllegroColor() );
        }

        drawIsoTile( where, x0, y0, tilesX, tilesY, color, false, false, true, false );

        {
                int x = x0 + ( tilesX - ( tilesY + 1 ) ) * ( sizeOfTile << 1 ) ;
                int y = y0 + ( ( tilesY + 1 ) + tilesX ) * sizeOfTile ;
                where.drawPixelAt( x, y - 2, color.toAllegroColor() );
                where.drawPixelAt( x + 1, y - 2, color.toAllegroColor() );
        }
}

void Miniature::drawIsoSquare( const allegro::Pict& where, int x0, int y0, unsigned int tilesX, unsigned int tilesY, const Color& color )
{
        if ( color.isFullyTransparent () ) return ;

        unsigned int posX = x0 ;
        unsigned int posY = y0 ;

        for ( unsigned int tile = 0 ; tile < tilesX ; tile ++ )
        {
                for ( unsigned int pix = 0 ; pix < sizeOfTile ; pix ++ )
                {
                        where.drawPixelAt( posX++, posY, color.toAllegroColor() );
                        where.drawPixelAt( posX++, posY++, color.toAllegroColor() );
                }
        }

        posX--; posY--;

        for ( unsigned int tile = 0 ; tile < tilesY ; tile ++ )
        {
                for ( unsigned int pix = 0 ; pix < sizeOfTile ; pix ++ )
                {
                        where.drawPixelAt( posX--, posY, color.toAllegroColor() );
                        where.drawPixelAt( posX--, posY++, color.toAllegroColor() );
                }
        }

        posX = x0 + 1 ;
        posY = y0 ;

        for ( unsigned int tile = 0 ; tile < tilesY ; tile ++ )
        {
                for ( unsigned int pix = 0 ; pix < sizeOfTile ; pix ++ )
                {
                        where.drawPixelAt( posX--, posY, color.toAllegroColor() );
                        where.drawPixelAt( posX--, posY++, color.toAllegroColor() );
                }
        }

        posX++; posY--;

        for ( unsigned int tile = 0 ; tile < tilesX ; tile ++ )
        {
                for ( unsigned int pix = 0 ; pix < sizeOfTile ; pix ++ )
                {
                        where.drawPixelAt( posX++, posY, color.toAllegroColor() );
                        where.drawPixelAt( posX++, posY++, color.toAllegroColor() );
                }
        }
}

void Miniature::drawIsoTile( const allegro::Pict& where, int x0, int y0, int tileX, int tileY, const Color& color, bool loX, bool loY, bool hiX, bool hiY )
{
        if ( color.isFullyTransparent () ) return ;

        int x = 0 ;
        int y = 0 ;

        if ( loX )
        {
                x = x0 + ( tileX - tileY ) * ( sizeOfTile << 1 ) ;
                y = y0 + ( tileY + tileX ) * sizeOfTile ;

                for ( unsigned int pix = 0 ; pix < sizeOfTile ; pix ++ )
                {
                        where.drawPixelAt( x++, y, color.toAllegroColor() );
                        where.drawPixelAt( x++, y++, color.toAllegroColor() );
                }
        }

        if ( loY )
        {
                x = x0 + ( tileX - tileY ) * ( sizeOfTile << 1 ) + 1 ;
                y = y0 + ( tileY + tileX ) * sizeOfTile ;

                for ( unsigned int pix = 0 ; pix < sizeOfTile ; pix ++ )
                {
                        where.drawPixelAt( x--, y, color.toAllegroColor() );
                        where.drawPixelAt( x--, y++, color.toAllegroColor() );
                }
        }

        if ( hiX )
        {
                x = x0 + ( tileX - tileY ) * ( sizeOfTile << 1 ) - ( ( sizeOfTile - 1 ) << 1 ) ;
                y = y0 + ( tileY + tileX ) * sizeOfTile + ( sizeOfTile - 1 ) ;

                for ( unsigned int pix = 0 ; pix < sizeOfTile ; pix ++ )
                {
                        where.drawPixelAt( x++, y, color.toAllegroColor() );
                        where.drawPixelAt( x++, y++, color.toAllegroColor() );
                }
        }

        if ( hiY )
        {
                x = x0 + ( tileX - tileY ) * ( sizeOfTile << 1 ) + ( ( sizeOfTile - 1 ) << 1 ) + 1 ;
                y = y0 + ( tileY + tileX ) * sizeOfTile + ( sizeOfTile - 1 ) ;

                for ( unsigned int pix = 0 ; pix < sizeOfTile ; pix ++ )
                {
                        where.drawPixelAt( x--, y, color.toAllegroColor() );
                        where.drawPixelAt( x--, y++, color.toAllegroColor() );
                }
        }
}

void Miniature::fillIsoTile( const allegro::Pict& where, int x0, int y0, int tileX, int tileY, const Color& color )
{
        if ( color.isFullyTransparent () ) return ;

        for ( unsigned int piw = 0 ; piw < sizeOfTile ; piw ++ )
        {
                int x = x0 + ( tileX - tileY ) * ( sizeOfTile << 1 ) - ( piw << 1 ) ;
                int y = y0 + ( tileY + tileX ) * sizeOfTile + piw ;

                for ( unsigned int pix = 0 ; pix < sizeOfTile ; pix ++ )
                {
                        where.drawPixelAt( x++, y, color.toAllegroColor() );
                        where.drawPixelAt( x++, y++, color.toAllegroColor() );
                }
        }
}

void Miniature::fillIsoTileInside( const allegro::Pict& where, int x0, int y0, int tileX, int tileY, const Color& color, bool fullFill )
{
        if ( color.isFullyTransparent () ) return ;

        if ( sizeOfTile == 2 )
        {
                int x = x0 + ( tileX - tileY ) * ( sizeOfTile << 1 ) ;
                int y = y0 + ( tileY + tileX ) * sizeOfTile + 1 ;

                where.drawPixelAt( x++, y, color.toAllegroColor() );
                where.drawPixelAt( x++, y++, color.toAllegroColor() );
        }
        else
        {
                for ( unsigned int piw = 1 ; piw < ( sizeOfTile - 1 ) ; piw ++ )
                {
                        int x = x0 + ( tileX - tileY ) * ( sizeOfTile << 1 ) - ( piw << 1 ) + 2 ;
                        int y = y0 + ( tileY + tileX ) * sizeOfTile + piw + 1 ;

                        for ( unsigned int pix = 1 ; pix < ( sizeOfTile - 1 ) ; pix ++ )
                        {
                                if ( fullFill )
                                {
                                        where.drawPixelAt( x, y - 1, color.toAllegroColor() );
                                        where.drawPixelAt( x + 1, y - 1, color.toAllegroColor() );

                                        where.drawPixelAt( x, y + 1, color.toAllegroColor() );
                                        where.drawPixelAt( x + 1, y + 1, color.toAllegroColor() );

                                        where.drawPixelAt( x - 2, y, color.toAllegroColor() );
                                        where.drawPixelAt( x - 1, y, color.toAllegroColor() );

                                        where.drawPixelAt( x + 2, y, color.toAllegroColor() );
                                        where.drawPixelAt( x + 3, y, color.toAllegroColor() );
                                }

                                where.drawPixelAt( x++, y, color.toAllegroColor() );
                                where.drawPixelAt( x++, y++, color.toAllegroColor() );
                        }
                }
        }
}

std::pair< int, int > Miniature::calculatePositionOfConnectedMiniature( const std::string& where, unsigned short gap )
{
        const ConnectedRooms * connections = room.getConnections() ;
        assert( connections != nilPointer );

        std::string fileOfConnectedRoom = connections->getConnectedRoomAt( where );

        if ( fileOfConnectedRoom.empty () ) return this->offset ;

        const Room* connectedRoom = GameMap::getInstance().getOrBuildRoomByFile( fileOfConnectedRoom );
        assert( connectedRoom != nilPointer );

        int adjacentDifferenceX = 0 ;
        int adjacentDifferenceY = 0 ;

        int gapX = - 2 + ( gap << 1 ) ;
        int gapY = - 1 + gap ;

        if ( where == "south" )
        {
                Door* southDoor = room.getDoorOn( "south" );
                assert( southDoor != nilPointer );
                Door* connectedNorthDoor = connectedRoom->getDoorOn( "north" );
                if ( connectedNorthDoor == nilPointer ) connectedNorthDoor = connectedRoom->getDoorOn( "northeast" );
                if ( connectedNorthDoor == nilPointer ) connectedNorthDoor = connectedRoom->getDoorOn( "northwest" );
                assert( connectedNorthDoor != nilPointer );

                int deltaCellY = southDoor->getCellY() - connectedNorthDoor->getCellY() ;
                adjacentDifferenceX = ( room.getTilesOnX () + deltaCellY ) * ( sizeOfTile << 1 ) + gapX ;
                adjacentDifferenceY = ( room.getTilesOnX () + deltaCellY ) * sizeOfTile + gapY ;
        }
        else if ( where == "north" )
        {
                Door* northDoor = room.getDoorOn( "north" );
                assert( northDoor != nilPointer );
                Door* connectedSouthDoor = connectedRoom->getDoorOn( "south" );
                if ( connectedSouthDoor == nilPointer ) connectedSouthDoor = connectedRoom->getDoorOn( "southeast" );
                if ( connectedSouthDoor == nilPointer ) connectedSouthDoor = connectedRoom->getDoorOn( "southwest" );
                assert( connectedSouthDoor != nilPointer );

                int deltaCellY = northDoor->getCellY() - connectedSouthDoor->getCellY() ;
                adjacentDifferenceX = ( - connectedRoom->getTilesOnX () + deltaCellY ) * ( sizeOfTile << 1 ) - gapX ;
                adjacentDifferenceY = ( - connectedRoom->getTilesOnX () + deltaCellY ) * sizeOfTile - gapY ;
        }
        else if ( where == "east" )
        {
                Door* eastDoor = room.getDoorOn( "east" );
                assert( eastDoor != nilPointer );
                Door* connectedWestDoor = connectedRoom->getDoorOn( "west" );
                if ( connectedWestDoor == nilPointer ) connectedWestDoor = connectedRoom->getDoorOn( "westnorth" );
                if ( connectedWestDoor == nilPointer ) connectedWestDoor = connectedRoom->getDoorOn( "westsouth" );
                assert( connectedWestDoor != nilPointer );

                int deltaCellX = eastDoor->getCellX() - connectedWestDoor->getCellX() ;
                adjacentDifferenceX = ( room.getTilesOnY () + deltaCellX ) * ( sizeOfTile << 1 ) + gapX ;
                adjacentDifferenceY = ( - connectedRoom->getTilesOnY () + deltaCellX ) * sizeOfTile - gapY ;
        }
        else if ( where == "west" )
        {
                Door* westDoor = room.getDoorOn( "west" );
                assert( westDoor != nilPointer );
                Door* connectedEastDoor = connectedRoom->getDoorOn( "east" );
                if ( connectedEastDoor == nilPointer ) connectedEastDoor = connectedRoom->getDoorOn( "eastnorth" );
                if ( connectedEastDoor == nilPointer ) connectedEastDoor = connectedRoom->getDoorOn( "eastsouth" );
                assert( connectedEastDoor != nilPointer );

                int deltaCellX = westDoor->getCellX() - connectedEastDoor->getCellX() ;
                adjacentDifferenceX = ( - connectedRoom->getTilesOnY () + deltaCellX ) * ( sizeOfTile << 1 ) - gapX ;
                adjacentDifferenceY = ( room.getTilesOnY () + deltaCellX ) * sizeOfTile + gapY ;
        }

        return std::pair< int, int >( this->offset.first + adjacentDifferenceX , this->offset.second + adjacentDifferenceY ) ;
}

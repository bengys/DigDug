#ifndef BLOCKARRAY_H
#define BLOCKARRAY_H
#include "Block.h"
#include <vector>

/**
 * @class BlockOutOfBounds
 * @brief Error to be thrown if Block requested does not exist
 * @author Benji
 * @date 23/09/2016
 * @file BlockArray.h
 */
class BlockOutOfBounds
{
};

/**
* @class BlockArray
* @brief BlockArray consists of a 2D Vector container which stores and manages all the individual Block objects which
* make up the
* screen.
* @author Benji Shear
* @date 21/09/16
* @file BlockArray.h
*/
class BlockArray
{

public:
    /**
    *@brief Creates a 2D vector container of blocks that form the screen. Also creates the starting tunnels.
    */
    BlockArray();

    /**
     * @brief Updates Borders and status of block based on Dug's past and present position and direction
     * @param dugPos Dug's current position
     * @param dugDir Dug's current directions
     */
    void eatBlock(const sf::Vector2f& dugPos, const Direction& dugDir);

    /**
    *@brief Get a particular block in the block Array
    *@param pos x,y co-ords of requested block
    *@return A reference to the Block Object requested
    */
    Block& getBlock(const sf::Vector2f& pos);

    /**
    *@brief Gets open blocks next to a particular block. Used by monsters to determine their available movements.
    *@param arrayPos x,y co-ords of the Block which we want it's adjacent open blocks
    *@return A Vector of enum type Direction of which directions are available to move from the requested block
    */
    std::vector<Direction> getAdjacentOpen(const sf::Vector2f& arrayPos) const;

    /**
    * @brief On Destruction sets variable used to track how many blocks were created to zero.
    */
    ~BlockArray();

private:
    /**
    *@brief Creates series of open blocks which will form the pre-existing tunnels when the game begins
    */
    void setStartTunnels();

    // Vector that forms collumn
    std::vector<Block> _arrCol;

    // 2D vector of type Block. No objects positioned outside this grid
    std::vector<std::vector<Block> > _blockArr;

    Direction _dugPastDirection;
    sf::Vector2f _previousBlockPos;
};

#endif

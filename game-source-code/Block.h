#ifndef BLOCK_H
#define BLOCK_H
#include "Border.h"
#include "global.h"
#include "Element.h"

/**
* @class Block
* @brief Block object represents one block of earth.
* @author Benji Shear
* @date 21/09/16
* @file Block.h
*/

class Block : public Element
{
    friend class BlockArray;

public:
    /**
    * @brief Block is constructed by default to be solid, and it's border is initialised at the same position as the
    * block
    */
    Block();

    /**
    * @brief Changes block to empty type
    */
    void changeTypetoEmpty();

    /**
    * @brief Check if the Block is Empty
    * @return Returns true if block is Empty and False if it is not
    */
    bool isEmpty() const;

    /**
    * @brief Gets the Block's Border by reference
    * @return A reference to the Border Object
    */
    Border& getBorder();

private:
    /**
    * @brief Set the block's postion in the 2d grid depending on how many blocks have already been created
    */
    void setArrayPos();

    BlockType _type;
    Border _border;
    bool _isEmpty;

    // Variable to keep track of previously created blocks and their postions
    static int xCount;
    static int yCount;
};

#endif

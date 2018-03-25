#ifndef BLOCKPRESENTER_H
#define BLOCKPRESENTER_H
#include "ElementPresenter.h"

/**
* @class BlockPresenter
* @brief Draws Block Elements using SFML graphics library.
* @author Benji Shear
* @date 21/09/16
* @file BlockPresenter.h
*/

class BlockPresenter : public ElementPresenter

{
public:
    /**
    * @brief Position and type of the block to be drawn is defined
    * @param position Position in the array of the Block
    * @param isEmpty Determines if the block is of type solid or empty
    */
    BlockPresenter(const sf::Vector2f& position, bool isEmpty);

private:
    virtual void setShapeAttribute() override;
    bool _isEmpty;
};

#endif
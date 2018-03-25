#ifndef ENEMYPRESENTER_H
#define ENEMYPRESENTER_H
#include "ElementPresenter.h"
/**
 * @class EnemyPresenter
 * @brief Base class which Manages presentation of enemies (monster/dragon)
 * @author Benji
 * @date 22/09/2016
 * @file EnemyPresenter.h
 */

class EnemyPresenter : public ElementPresenter

{
protected:
    /**
     * @brief calls defualt constructor for Elements and also defines if in ghost form or not
     * @param isGhost Determine if Enemey currently in form of Ghost or not
     */
    EnemyPresenter(const sf::Vector2f& position, const bool& isGhost);

    virtual void setPixelPosition(const float& x, const float& y) override;
    virtual void setShapeAttribute() override;

    bool _isGhost;
    sf::Color color;
};

#endif
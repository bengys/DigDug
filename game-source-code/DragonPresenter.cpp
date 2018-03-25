#include "DragonPresenter.h"

DragonPresenter::DragonPresenter(const sf::Vector2f& position, const bool& isGhost)
    : EnemyPresenter(position, isGhost)
{
    // Has a Green colour shape
    color = sf::Color(0, 130, 0);
    setShapeAttribute();
}
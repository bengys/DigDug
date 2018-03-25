#include "MonsterPresenter.h"
#include "global.h"

MonsterPresenter::MonsterPresenter(const sf::Vector2f& position, const bool& isGhost)
    : EnemyPresenter(position, isGhost)
{
    color = sf::Color::Red;
    setShapeAttribute();
}
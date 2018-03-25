#ifndef SPLASHPRESENTER_H
#define SPLASHPRESENTER_H
#include "ElementPresenter.h"

/**
 * @class SplashPresenter
 * @brief Manages presentation of the splash screen
 * @author Benji
 * @date 23/09/2016
 * @file SplashPresenter.h
 */
class SplashPresenter : public ElementPresenter

{
public:
    /**
    *@brief Upon construction assigns presentation attributes of the splash screen
    *@param x,y co-ords of splash screen in grid
    */
    SplashPresenter(const sf::Vector2f& position);

    /**
     * @brief Draws and displays the splash screen on the window
     * @param window Game window
     */
    virtual void drawElement(sf::RenderWindow& window) override;

private:
    /**
     * @brief Loads texture for splashscreen from file and sets it to a Sprite
     */
    virtual void setShapeAttribute() override;

    sf::Sprite _sprite;
    sf::Texture _texture;
};

#endif
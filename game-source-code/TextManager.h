#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H
#include <SFML/Graphics.hpp>

/**
 * @class TextManager
 * @brief Manages presentation of text at the top of the play screen
 * @author Benji
 * @date 23/09/2016
 * @file TextManager.h
 */

class TextManager
{
public:
    /**
     * @brief On construction the position and style of the text is set
     */
    TextManager();

    /**
    * @brief Sets the ""lives remaining" text
    * @param lives Dug's remaining lives
    */
    void livesText(const unsigned int& lives);

    /**
     * @brief Sets the content of the text that will be displayed when the game ends
     * @param isWin Determines if the winning or losing text must be displayed
     */
    void endGameText(const bool isWin);

    /**
     * @brief Getter for form of text (for drawing on screen)
     * @return Text to be drawn
     */
    sf::Text getText() const;

private:
    sf::Text _gameText;
    sf::Font _MyFont;
};

#endif

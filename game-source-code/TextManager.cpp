#include "TextManager.h"

TextManager::TextManager()
{
    _gameText.setCharacterSize(20);
    _gameText.setPosition(50, 2);
    _gameText.setColor(sf::Color::Black);
    if(!_MyFont.loadFromFile("arial.ttf")) {
	// error
    }
    _gameText.setFont(_MyFont);
}

void TextManager::livesText(const unsigned int& lives)
{
    _gameText.setString("Lives remaining: " + std::to_string(lives));
}

void TextManager::endGameText(const bool isWin)
{
    if(isWin)
	_gameText.setString("Ok. You won - quite possibly the first person to win. Nice. stay in contacts with "
	                    "\n the devs and we will INFORM you when \n more levels are released. \n For now this is "
	                    "all we got.\n We wish you success. \n If you are bored we suggest you play Pac-man or "
	                    "COD. \n When get over the exhiliration of winning press ESC. \n (The top left key of "
	                    "keyboard \n {or at least my keyboard..})  ");
    else {
	_gameText.setString(
	    "Game Over - Dug is Dead. \n- You Lose. Sorry. Go home. Get some rest. (Feed the hamster). \n Come back. "
	    "Try again.\n Try win. Try win this time. \n Get more practice.\n Get some help. \n Read. \n Strategise.\n "
	    "This game "
	    "HAS been beaten before. \n. But You are not ready.\n No. \n Build up your mental strength. "
	    "\n Consult with an experienced Dig Dug player for guidance and inspiration.\n Focus your mind.\n Research "
	    "a strategy on internet. \n Ask for hints. \n Be humble.\n Be willing to learn. \n You can do it. \n Find "
	    "the ESC button and push it to exit");
    }
}

sf::Text TextManager::getText() const
{
    return _gameText;
}
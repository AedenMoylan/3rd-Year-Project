
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Menu.h"
#include "Shop.h"
#include "Controls.h"
#include "GamePlay.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	// instances
	GameState m_gameState;
	Menu m_menu;
	Shop m_shop;
	Controls m_controls;
	GamePlay m_gamePlay;

	void update(sf::Time t_deltaTime);
	void render();
	void processEvents();
	void processKeys(sf::Event t_event);
	void setupFontAndText();
	void setupSprite();

	int selectionNumber;
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP


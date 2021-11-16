#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "GameState.h"


class Controls {
public:



	void initialise(sf::Font&);
	void update(sf::Window&);
	void draw(sf::RenderWindow& window);
	int getSelectionNumber();
private:


	GameState myGameState;

	sf::Texture m_buttonTexture;
	sf::Sprite m_buttonSprite;
	sf::Font m_font;

	sf::Text m_buttonText;
	sf::Text m_controlForward;
	sf::Text m_controlBackwards;
	sf::Text m_controlLeft;
	sf::Text m_controlRight;
	sf::Text m_tipText;


	sf::Texture m_controlsBackgroundTexture;
	sf::Sprite m_controlsBackgroundSprite;

	int m_buttonOffset = 512;


	float m_topOffset = 0;
	float m_leftOffset = 525;
	float m_verticalSpacing = 500;
	float m_buttonWidth = 100;
	float m_buttonHeight = 70;



	int selectionNumber;

};
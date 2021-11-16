#include "Shop.h"

void Shop::initialise(sf::Font& font)
{
	if (!m_buttonTexture.loadFromFile("ASSETS\\IMAGES\\button.png"))
	{
		std::cout << "error with button file";
	}

	if (!m_shopBackgroundTexture.loadFromFile("ASSETS\\IMAGES\\mike.jpg"))
	{
		std::cout << "error with background file";
	}

	m_shotBackgroundSprite.setTexture(m_shopBackgroundTexture);

	m_topOffset = 0;
	m_verticalSpacing = 500;
	m_buttonWidth = 400;
	m_leftOffset = 100;
	m_buttonHeight = 70;
	int textDropOffset = 50;
	int textOffset = 75;
	m_font = font;


	sf::String m_shopMenuTexts[] = { "Speed", "Armor", "Empty", "Empty", "Back"};

	/// for loop to setup menu buttons in an array
	for (int i = 0; i < m_optionCount; i++)
	{
		m_buttonSprites[i].setTexture(m_buttonTexture);
		m_buttonSprites[i].setPosition(m_leftOffset * (i * 2),m_verticalSpacing);

		// sets font up for the array of text shapes that display over the buttons
		m_buttonTexts[i].setFont(m_font);
		m_buttonTexts[i].setString(m_shopMenuTexts[i]);
		m_buttonTexts[i].setFillColor(sf::Color::White);
		m_buttonTexts[i].setCharacterSize(22);
		sf::FloatRect textSize = m_buttonTexts[i].getGlobalBounds();
		m_buttonTexts[i].setPosition(m_leftOffset * (i * 2) + textOffset/*+ (textOffset * i + 25)*/, m_verticalSpacing + textDropOffset);
	}
}

void Shop::update(sf::RenderWindow& window)
{
	selectionNumber = 2;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(window);
		if (mouseLocation.y > m_verticalSpacing + (m_buttonHeight / 2) && mouseLocation.y < m_verticalSpacing + (m_buttonHeight * 2))
		{
			if (mouseLocation.x < m_leftOffset * 2 && mouseLocation.x > 0)
			{
				std::cout << "Speed Acquired" << std::endl;
			}
			if (mouseLocation.x < m_leftOffset * 4 && mouseLocation.x > m_leftOffset * 2)
			{				
				std::cout << "Armor Acquired" << std::endl;
			}
			if (mouseLocation.x < m_leftOffset * 6 && mouseLocation.x > m_leftOffset * 4)
			{				
				std::cout << "Empty 1" << std::endl;
			}
			if (mouseLocation.x < m_leftOffset * 8 && mouseLocation.x > m_leftOffset * 6)
			{				
				std::cout << "Empty 2" << std::endl;
			}
			if (mouseLocation.x < m_leftOffset * 10 && mouseLocation.x > m_leftOffset * 8)
			{
				selectionNumber = 1;
				myGameState = GameState::GAME_PLAY;
			}

		}
	}
}

void Shop::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_shotBackgroundSprite);
	for (int i = 0; i < m_optionCount; i++)
	{
		window.draw(m_buttonSprites[i]);
		window.draw(m_buttonTexts[i]);
	}
}

int Shop::getSelectionNumber()
{
	return selectionNumber;
}


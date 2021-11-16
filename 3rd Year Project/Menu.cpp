#include "Menu.h"


void Menu::initialise(sf::Font& font)
{
	m_topOffset = 200;
	m_verticalSpacing = 100;
	m_buttonWidth = 400;
	m_leftOffset = (1280 - m_buttonWidth) / 2;
	m_buttonHeight = 70;
	int textDropOffset = 21;
	sf::String m_menuTexts[] = { "Play", "Shop ", "Controls", "Exit" };
	m_font = font;

	/// display error if button.png doesnt load properly
	if (!m_buttonTexture.loadFromFile("ASSETS\\IMAGES\\button.png"))
	{
		std::cout << "error with button file";
	}

	/// for loop to setup menu buttons in an array
	/// keeps them in a centre nicely laid out
	/// scales them to texture size so they look to scale
	/// 
	for (int i = 0; i < m_optionCount; i++)
	{
		m_buttonSprites[i].setTexture(m_buttonTexture);
		m_buttonSprites[i].setPosition(m_leftOffset, m_verticalSpacing * i + m_topOffset);
		sf::Vector2u textureSize = m_buttonTexture.getSize();
		m_buttonSprites[i].setScale(m_buttonWidth / textureSize.x, m_buttonHeight / textureSize.y);

		// sets font up for the array of text shapes that display over the buttons
		m_buttonTexts[i].setFont(m_font);
		m_buttonTexts[i].setString(m_menuTexts[i]);
		m_buttonTexts[i].setFillColor(sf::Color::White);
		m_buttonTexts[i].setCharacterSize(22);
		sf::FloatRect textSize = m_buttonTexts[i].getGlobalBounds();
		float textOffset = (m_buttonWidth - textSize.width) / 2;
		m_buttonTexts[i].setPosition(m_leftOffset + textOffset, m_verticalSpacing * i + m_topOffset + textDropOffset);
	}
}



void Menu::update(sf::Window& window)
{
	selectionNumber = 4;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(window);
		if (mouseLocation.x > m_leftOffset && mouseLocation.x < m_leftOffset + m_buttonWidth)
		{
			if (mouseLocation.y > m_topOffset && mouseLocation.y && mouseLocation.y < m_topOffset + m_buttonHeight)
			{
				selectionNumber = 1;
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing && mouseLocation.y < m_topOffset + m_verticalSpacing + m_buttonHeight)
			{
				selectionNumber = 2;
			}

			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 2 && mouseLocation.y < m_topOffset + m_verticalSpacing * 2 + m_buttonHeight)
			{
				selectionNumber = 3;
			}

			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 3 && mouseLocation.y < m_topOffset + m_verticalSpacing * 3 + m_buttonHeight)
			{
				window.close();
			}
			std::cout << selectionNumber << std::endl;
		}
	}
}


void Menu::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(menuBgSprite);

	for (int i = 0; i < m_optionCount; i++)
	{
		window.draw(m_buttonSprites[i]);
		window.draw(m_buttonTexts[i]);
	}
}

int Menu::getSelectionNumber()
{
	return selectionNumber;
}
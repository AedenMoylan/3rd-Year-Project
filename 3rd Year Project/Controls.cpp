#include "Controls.h"
#include "GameState.h"

void Controls::initialise(sf::Font& m_font)
{
	if (!m_buttonTexture.loadFromFile("ASSETS\\IMAGES\\button.png"))
	{
		std::cout << "could not find a file called mike.jpg in the given directory.";
	}

	/*if (!m_controlsBackgroundTexture.loadFromFile("ASSETS\\IMAGES\\controls.png"))
	{
		std::cout << "could not find a file called mike.jpg in the given directory.";
	}*/
	m_buttonSprite.setTexture(m_buttonTexture);
	m_buttonSprite.setPosition(m_leftOffset , m_buttonOffset);

	m_controlsBackgroundSprite.setTexture(m_controlsBackgroundTexture);

	// Button text initialisation
	m_buttonText.setFont(m_font);
	m_buttonText.setString("Back");
	m_buttonText.setFillColor(sf::Color::White);
	m_buttonText.setCharacterSize(22);
	//m_buttonText.setPosition(m_leftOffset, m_buttonOffset);
	m_buttonText.setPosition(m_leftOffset + (m_buttonWidth / 2), m_buttonOffset + (m_buttonHeight /2));

	// Front control
	m_controlForward.setFont(m_font);
	m_controlForward.setString("To move forward, press W");
	m_controlForward.setFillColor(sf::Color::Blue);
	m_controlForward.setCharacterSize(20);
	m_controlForward.setPosition(500, 300);

	// Backwards control
	m_controlBackwards.setFont(m_font);
	m_controlBackwards.setString("To rotate right, press S");
	m_controlBackwards.setFillColor(sf::Color::Blue);
	m_controlBackwards.setCharacterSize(20);
	m_controlBackwards.setPosition(500, 350);

	// Left control
	m_controlLeft.setFont(m_font);
	m_controlLeft.setString("To rotate left, press A");
	m_controlLeft.setFillColor(sf::Color::Red);
	m_controlLeft.setCharacterSize(20);
	m_controlLeft.setPosition(500, 400);

	// Right control
	m_controlRight.setFont(m_font);
	m_controlRight.setString("To move backwards, press D");
	m_controlRight.setFillColor(sf::Color::Red);
	m_controlRight.setCharacterSize(20);
	m_controlRight.setPosition(500, 450);
}

void Controls::update(sf::Window& window)
{
	selectionNumber = 3;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(window);
		if (mouseLocation.y > m_verticalSpacing + (m_buttonHeight / 2) && mouseLocation.y < m_verticalSpacing + (m_buttonHeight * 2))
		{
			if (mouseLocation.x < m_leftOffset * 1.4 && mouseLocation.x > 550)
			{
				selectionNumber = 4;
			}
			//std::cout << "bababooey" << std::endl;
		}
	}
}

void Controls::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_controlsBackgroundSprite);
	
	window.draw(m_controlsBackgroundSprite);
	window.draw(m_buttonSprite);
	window.draw(m_buttonText);
	window.draw(m_controlForward);
	window.draw(m_controlBackwards);
	window.draw(m_controlRight);
	window.draw(m_controlLeft);
}

int Controls::getSelectionNumber()
{
	return selectionNumber;
}

#include "GamePlay.h"

void GamePlay::initialise(sf::Font& font)
{
	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\Player.png"))
	{
		std::cout << "error with player file";
	}

	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setOrigin(m_playerSprite.getGlobalBounds().width / 2 , m_playerSprite.getGlobalBounds().height / 2 );
	m_playerSprite.setPosition(300, 300);
	m_playerSprite.setScale(0.08, 0.08);
	m_playerSprite.setRotation(-90);




	acceleration = 0.2;
	deceleration = 0.2;
	speed = 0;
	angle = 0;

	isUpPressed = false;
	isDownPressed = false;
	isLeftPressed = false;
	isRightPressed = false;
}

void GamePlay::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_playerSprite);
}

void GamePlay::update(sf::Window& window)
{
	isUpPressed = false;
	isDownPressed = false;
	isLeftPressed = false;
	isRightPressed = false;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		isUpPressed = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		isDownPressed = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		isLeftPressed = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		isRightPressed = true;
	}

	carMovement();

	m_playerSprite.setPosition(x, y);
	m_playerSprite.setRotation(angle * 180 / PI);
}

void GamePlay::carMovement()
{
	if (isUpPressed && speed < maxSpeed)
	{
		if (speed < 0)
		{
			speed += deceleration;
		}
		else
		{
			speed += acceleration;
		}
	}

	if (isDownPressed && speed > -maxSpeed)
	{
		if (speed > 0)
		{
			speed -= deceleration;
		}
		else
		{
			speed -= acceleration;
		}
	}

	if (!isUpPressed && !isDownPressed)
	{
		if (speed - deceleration > 0)
		{
			speed -= deceleration;
		}
		else if (speed + deceleration < 0)
		{
			speed += deceleration;
		}
		else
		{
			speed = 0;
		}
	}

	if (isRightPressed && speed != 0)
	{
		angle += turnSpeed * speed / maxSpeed;
	}

	if (isLeftPressed && speed != 0)
	{
		angle -= turnSpeed * speed / maxSpeed;
	}

	x += sin(angle) * speed;
	y -= cos(angle) * speed;
}

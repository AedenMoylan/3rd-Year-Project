#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class GamePlay
{

	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;

	float acceleration;
	float deceleration;
	float speed;
	float angle;
	float maxSpeed = 10;
	float turnSpeed = 0.08;
	float x = 300;
	float y = 300;

	float rotationSpeed = 0.2;

	const float PI = 3.141592;

	bool isUpPressed;
	bool isDownPressed;
	bool isLeftPressed;
	bool isRightPressed;

public:

	void initialise(sf::Font&);


	void draw(sf::RenderWindow&);


	void update(sf::Window&);

	void carMovement();
};


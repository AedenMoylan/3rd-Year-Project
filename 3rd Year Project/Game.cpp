/// <summary>
/// Authors: Aeden Moylan & Sasa Kuzmanovic
/// Date: November 2021
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup the image
/// set the starting GameState
/// calls the relevant initialise functions
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1280U, 720U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	m_gameState = GameState::GAME_MENU; // set starting gamestate


	setupFontAndText(); // load font 
	setupSprite(); // load texture

	selectionNumber = 4;
	m_menu.initialise(m_ArialBlackfont);
	m_shop.initialise(m_ArialBlackfont);
	m_controls.initialise(m_ArialBlackfont);
}

Game::~Game()
{
}


void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame); //60 fps
			processEvents();
		}
		render(); // as many as possible
	}
}



/// <summary>
/// Update the game world
/// The selection number is used to determine which game state the game should change to.
/// 1 = gameplay, 2 = shop, 3 = controls, 4 = main menu
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	switch (m_gameState)
	{
	case GameState::GAME_MENU:
		m_menu.update(m_window);
		selectionNumber = m_menu.getSelectionNumber();
		break;

	case GameState::GAME_SHOP:
		m_shop.update(m_window);
		selectionNumber = m_shop.getSelectionNumber();

		break;
		
	case GameState::GAME_CONTROLS:
		m_controls.update(m_window);
		selectionNumber = m_controls.getSelectionNumber();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	if (selectionNumber == 1)
	{
		m_gameState = GameState::GAME_PLAY;
	}

	if (selectionNumber == 2)
	{
		m_gameState = GameState::GAME_SHOP;
	}

	if (selectionNumber == 3)
	{
		m_gameState = GameState::GAME_CONTROLS;
	}

	if (selectionNumber == 4)
	{
		m_gameState = GameState::GAME_MENU;
	}

	switch (m_gameState)
	{
	case GameState::GAME_MENU:
		m_menu.draw(m_window);


		break;

	case GameState::GAME_PLAY:

		std::cout << "Game Play" << std::endl;

		break;
		 
	case GameState::GAME_SHOP:
		m_shop.draw(m_window);
		//std::cout << "Game Shop" << std::endl;

		break;

	case GameState::GAME_CONTROLS:
		m_controls.draw(m_window);

		break;
	}
	m_window.display();
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}

/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);
}

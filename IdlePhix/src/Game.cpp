#include "../include/Game.h"
#include <iostream>

IdlePhix::Game::Game() :
	player("Zoey", "Rak'Tika Greatwood", "Hume", "Female", 1, 0)
{
	renderWindow.create(videoMode, gameTitle);
	logger.log("DEBUG", "RenderWindow created.");
	renderWindow.setFramerateLimit(framerateLimit);

	if (!gameFont.loadFromFile(gameFontFilePath))
		logger.log("ERROR", "Unable to load font from file: " + gameFontFilePath);
	else
		logger.log("DEBUG", "Loaded game font from file: " + gameFontFilePath);

	// player = { "Zoey", "Rak'Tika Greatwood", "Hume", "Female", 1, 0 };

	// Set up for resource bla. Will most likely be moved.
	resourceText.setFont(gameFont);
	// resourceText.setCharacterSize(30); // Default is 30
	resourceText.setFillColor(gameTextColor);
	resourceText.setPosition(30, 20);
}

void IdlePhix::Game::processEvents()
{
	sf::Event event;
	// While there are pending events
	// Check all the window's events that were triggered since the last iteration of the loop
	while (renderWindow.pollEvent(event))
	{
		// Check the event type
		switch (event.type)
		{
			case sf::Event::Closed:
				logger.log("INFO", "Exiting.");
				renderWindow.close();
				break;
			// Don't care about any other events
			default:
				break;
		}
	}
}

void IdlePhix::Game::update(float deltaTime)
{
	// player.inventory.getItems()->at(0).update(deltaTime);
	player.update(deltaTime);
	resourceText.setString("Wood: " + std::to_string(player.inventory.getItemAmount(1)));
	// resourceText.setString("Wood: " + std::to_string(player.inventory.getItems()->at(0).amount));
	// std::cout << player.inventory.getItems()->at(1).amount << std::endl;
	std::cout << player.inventory.getItemAmount(1) << std::endl;
}

void IdlePhix::Game::draw()
{
	// Clear the window
	renderWindow.clear(clearColor);

	// Add data to the buffer
	renderWindow.draw(resourceText);

	// Copy buffer to render window
	renderWindow.display();
}

void IdlePhix::Game::run()
{
	logger.log("INFO", "Welcome to IdlePhix.");

	while (renderWindow.isOpen())
	{
		// Calculate time elapsed between frames
		deltaTime = clock.restart().asSeconds();
		// FIXME (investigate alternatives): Force-limit framerate to 60
		/*if (deltaTime > 1.0f / 60.0f)
			deltaTime = 1.0f / 60.0f;*/

		processEvents();
		update(deltaTime);
		draw();
		// End of current frame
	}
}

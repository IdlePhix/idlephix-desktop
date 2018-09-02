#include "../include/Game.h"
#include <iostream>

IdlePhix::Game::Game()
{
	renderWindow.create(videoMode, gameTitle);
	std::cout << "[DEBUG] RenderWindow created." << std::endl;
	renderWindow.setFramerateLimit(framerateLimit);

	if (!gameFont.loadFromFile(gameFontFilePath))
		std::cout << "[ERROR] Unable to load font from file." << std::endl;
	else
		std::cout << "[DEBUG] Loaded game font from file." << std::endl;

}

void IdlePhix::Game::processEvents()
{
	sf::Event event;
	// While there are pending events
	while (renderWindow.pollEvent(event))
	{
		// Check the event type
		switch (event.type)
		{
			case sf::Event::Closed:
				std::cout << "[INFO] Exiting." << std::endl;
				renderWindow.close();
				break;
			// Don't case about any other events
			default:
				break;
		}
	}
}

void IdlePhix::Game::update(float deltaTime)
{
	// Not yet implemented
	// resourceAmount += incrementValue * (deltaTime / incrementPeriod);
	// resourceText.setString(std::to_string((int) resourceAmount));
}

void IdlePhix::Game::draw()
{
	// Clear the window
	renderWindow.clear(clearColor);
	// Add data to the buffer
	// renderWindow.draw(resourceText);
	// Copy buffer to render window
	renderWindow.display();
}

void IdlePhix::Game::run()
{
	std::cout << "[INFO] Welcome to IdlePhix." << std::endl;

	while (renderWindow.isOpen())
	{
		// 0. Calculate time between frames
		deltaTime = clock.restart().asSeconds();

		// 1. Process and handle events
		// Check all the window's events that were triggered since the last iteration of the loop
		processEvents();

		// 2. Update
		update(deltaTime);

		// 3. Draw/render
		draw();

		// End of current frame
	}
}

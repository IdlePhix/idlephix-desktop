#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

std::string incrementScore(int score)
{
	return std::to_string(++score);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "IdlePhix - v0.0.1");
	// Run game at the same frequency as the monitor's refresh rate
	// window.setVerticalSyncEnabled(true);
	// Run game at 60 FPS
	window.setFramerateLimit(60);
	std::cout << "[INFO] Window created." << std::endl;

	sf::Font font;
	if (!font.loadFromFile("assets/sui_generis_rg.ttf"))
	{
		std::cout << "[ERROR] Unable to load font from file." << std::endl;
	}

	float score = 0;
	float incrementValue = 1;
	float incrementPeriod = 5; // In seconds
	// sf::Time lastTime; // aka elapsedTime
	// sf::Time now;
	float deltaTime;

	sf::Text text;
	text.setFont(font);
	text.setString(std::to_string(score));
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::White);
	text.setPosition(30, 20);

	// Main loop
	sf::Clock clock;
	while (window.isOpen())
	{
		// lastTime = clock.getElapsedTime();
		// window.setTitle("IdlePhix - v0.0.1 - " + std::to_string((int)(1.0f / lastTime.asSeconds())));
		deltaTime = clock.restart().asSeconds();
		// Limit framerate to 60
		if (deltaTime > 1.0f / 60.0f)
			deltaTime = 1.0f / 60.0f;
		
		score += incrementValue * (deltaTime / incrementPeriod);
		text.setString(std::to_string((int)score));

		// Event loop
		// Check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		// While there are pending events...
		while (window.pollEvent(event))
		{
			// Check the type of the event...
			switch (event.type)
			{
				// Keyboard-related events
				case sf::Event::TextEntered:
					if (event.text.unicode < 128)
					{
						std::cout << "[DEBUG] ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
					}
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
					{
						std::cout << "[DEBUG] The escape key was pressed" << std::endl;
						std::cout << "[DEBUG] Control:" << event.key.control << std::endl;
						std::cout << "[DEBUG] Alt:" << event.key.alt << std::endl;
						std::cout << "[DEBUG] Shift:" << event.key.shift << std::endl;
						std::cout << "[DEBUG] System:" << event.key.system << std::endl;
					}
					break;
				// Mouse-related events
				case sf::Event::MouseButtonPressed:
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						std::cout << "[DEBUG] The left button was pressed" << std::endl;
					}
					else if (event.mouseButton.button == sf::Mouse::Right)
					{
						std::cout << "[DEBUG] The right button was pressed" << std::endl;
					}
					std::cout << "[DEBUG] Mouse X: " << event.mouseButton.x << std::endl;
					std::cout << "[DEBUG] Mouse Y: " << event.mouseButton.y << std::endl;
					break;
				/*
				case sf::Event::MouseMoved:
					std::cout << "[DEBUG] New mouse X: " << event.mouseMove.x << std::endl;
					std::cout << "[DEBUG] New mouse Y: " << event.mouseMove.y << std::endl;
					break;
				*/
				// Window-related events
				case sf::Event::Resized:
					std::cout << "[DEBUG] New window width: " << event.size.width << std::endl;
					std::cout << "[DEBUG] New window height: " << event.size.height << std::endl;
					break;
				case sf::Event::LostFocus:
					std::cout << "[DEBUG] Lost window focus." << std::endl;
					break;
				case sf::Event::GainedFocus:
					std::cout << "[DEBUG] Gained window focus." << std::endl;
					break;
				case sf::Event::Closed:
					std::cout << "[INFO] Exiting." << std::endl;
					window.close();
					break;
				default:
					break;
			}
		} // End of event loop

		// Clear the window
		window.clear(sf::Color::Black);
		
		// Draw
		window.draw(text);

		// End current frame (copy buffer to window)
		window.display();
	}

	return 0;
}

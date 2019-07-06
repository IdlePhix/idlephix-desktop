#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"

/// <summary>
/// Namespace for the IdlePhix game. Contains all the classes required for the game.
/// </summary>
namespace IdlePhix
{
	/// <summary>
	/// Main game class.
	/// </summary>
	class Game
	{
		public:
			/// <summary>
			/// Default constructor. Creates and initializes the SFML window and other necessary resources.
			/// </summary>
			Game();

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~Game() { }

			/// <summary>
			/// Event loop. Processes and handles window events and user-input.
			/// </summary>
			void processEvents();
			/// <summary>
			/// Updates the game state.
			/// </summary>
			void update(float deltaTime);
			/// <summary>
			/// Draws content onto the game window.
			/// </summary>
			void draw();
			/// <summary>
			/// Performs the game's main loop.
			/// </summary>
			void run();
		private:
			const std::string gameVersion = "v0.0.1";
			const std::string gameTitle = "IdlePhix - " + gameVersion;
			const std::string gameFontFilePath = "assets/sui_generis_rg.ttf";

			const sf::VideoMode videoMode = sf::VideoMode(800, 600);
			const sf::Color clearColor = sf::Color(sf::Color::Black);
			const sf::Color gameTextColor = sf::Color(sf::Color::White);

			unsigned int framerateLimit = 60;
			float deltaTime;
			
			sf::RenderWindow renderWindow;
			sf::Font gameFont;
			/// <summary>
			/// Instance of SFML Clock used to measure time. Used to get
			/// a <see cref="deltaTime">delta time</see>.
			/// </summary>
			sf::Clock clock;

			Player player;

			// Resource bla, will most likely be moved soon
			/// <summary>
			/// SFML Text drawable to display the amount of player resources.
			/// </summary>
			sf::Text resourceText;
	};
}

#endif

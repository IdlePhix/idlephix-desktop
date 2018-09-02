#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>

/// <summary>
/// Namespace for the IdlePhix game. Contains all the classes required for the game.
/// </summary>
namespace IdlePhix
{
	/// <summary>
	/// Main game class used to initialize the game, create a window and perform the main loop.
	/// </summary>
	class Game
	{
		public:
			/// <summary>
			/// TODO
			/// </summary>
			Game();

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~Game() { }

			/// <summary>
			/// Event loop.
			/// </summary>
			void processEvents();
			/// <summary>
			/// TODO.
			/// </summary>
			void update(float deltaTime);
			/// <summary>
			/// TODO.
			/// </summary>
			void draw();
			/// <summary>
			/// Game main loop.
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
	};
}

#endif

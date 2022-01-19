#include <SFML/Graphics.hpp>
#pragma once

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

class Game
{
public:
	sf::RenderWindow window;
	Game();
	void gameLoop();
	void gameInitialization();
	void update();
	
	//class EnemyBase* enemy;
	class Level* level;

	sf::Texture background_t;
	sf::Sprite background_s;

	sf::Font font;
	sf::Text timeText;
	sf::Text timeValue;
	sf::Text scoreText;
	sf::Text scoreValue;

	sf::Text gameOverText;
	sf::Text nextText;

	void addText(sf::Text& text, const sf::String& string, sf::Vector2f pos, int font_size);
};


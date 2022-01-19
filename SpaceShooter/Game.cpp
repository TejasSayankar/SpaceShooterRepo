#include "Game.h"
#include "Player.h"
#include "Projectile.h"
#include "EnemyBase.h"
#include "Level.h"
#include "MovingEnemy.h"
#include "Shooter1.h"
#include "Shooter2.h"
#include "Particle.h"
#include <iostream>
#include <string.h>


Game::Game()
{
	gameInitialization();

	background_t.loadFromFile("Assets/background.png");
	background_t.setSmooth(true);
	background_s.setTexture(background_t);
	background_s.setScale(1.5, 1.5);
	if (!font.loadFromFile("Assets/arial.ttf"))
	{
		std::cout << "font not loaded" << std::endl;
	}
}

void Game::gameLoop()
{
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			

			/*if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					player->movement(player->UpVector);
				}
				if (event.key.code == sf::Keyboard::S)
				{
					player->movement(player->DownVector);
				}
			}*/

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					if (level->player->isDisabled)
					{
						level->player->begin();
						level->initialize();
					}
					else
					{
						level->player->fire();
					}
					
				}
			}


		}
		window.clear();
		if (level->levelClock.getElapsedTime().asSeconds() > 5 && level->player->isDisabled)
		{
			//menu
			window.draw(gameOverText);
			window.draw(nextText);
			window.draw(scoreText);
			window.draw(scoreValue);
		}
		else
		{
			
			//window.draw(player->charShape);
			window.draw(background_s);
			for (int i = 0; i < 10; i++)
			{
				if (level->particle[i]->isSpawned)
				{
					window.draw(level->particle[i]->shape);
				}
				
			}


			if (!level->player->isDisabled)
			{
				window.draw(level->player->sprite);
				for (int i = 0; i < 10; i++) {
					if (level->player->projectile[i]->isFired)
					{
						//window.draw(player->projectile[i]->shape);
						window.draw(level->player->projectile[i]->sprite);
					}
				}
			}
			
			//window.draw(enemy->charShape);
			for (int i = 0; i < 15; i++)
			{
				if (level->enemy[i]->isSpawned)
				{
					window.draw(level->enemy[i]->sprite);
					/*if (level->enemy[i]->canFire)
					{*/
					for (int j = 0; j < 10; j++)
					{
						if (level->enemy[i]->projectile[j]->isFired)
						{
							//window.draw(enemy->projectile[i]->shape);
							window.draw(level->enemy[i]->projectile[j]->sprite);
						}
					}
					/*}*/

				}
			}
			//window.draw(enemy->sprite);
			

			//for (int i = 0; i < 10; i++) {
			//	if (enemy->projectile[i]->isFired)
			//	{
			//		//window.draw(enemy->projectile[i]->shape);
			//		window.draw(enemy->projectile[i]->sprite);
			//	}
			//}
			window.draw(timeText);
			window.draw(timeValue);
			window.draw(scoreText);
			window.draw(scoreValue);
			
		}

		window.display();
		update();
	}
}

void Game::update()
{
	if (level->levelClock.getElapsedTime().asSeconds() > 5 && level->player->isDisabled)
	{
		//menu
		addText(gameOverText, "Game Over", sf::Vector2f(450, 250),120);
		addText(scoreText, "Score: ", sf::Vector2f(650, 450),50);
		addText(scoreValue, std::to_string((int)level->score), sf::Vector2f(850, 450),50);
		addText(nextText, "Press Space to Play Again", sf::Vector2f(450, 700),50);
	}
	else
	{
		level->Levelloop();
		addText(timeText, "Time: ", sf::Vector2f(50, 20),24);
		addText(timeValue, std::to_string((int)level->timePassed), sf::Vector2f(130, 20),24);
		addText(scoreText, "Score: ", sf::Vector2f(WINDOW_WIDTH - 180, 20),24);
		addText(scoreValue, std::to_string((int)level->score), sf::Vector2f(WINDOW_WIDTH - 80, 20),24);
		//enemy->update();
	}
	
}

void Game::addText(sf::Text& text, const sf::String& string, sf::Vector2f pos, int font_size)
{
	text.setFont(font);
	text.setString(string);
	text.setCharacterSize(font_size);
	text.setFillColor(sf::Color::Yellow);
	text.setStyle(sf::Text::Bold);
	text.setPosition(pos);
}

void Game::gameInitialization()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Shooter");
	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	
	level = new Level();
	//enemy = new EnemyBase();

}

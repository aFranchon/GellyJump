/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

	#include <memory>

	#include <SFML/Graphics.hpp>

	#include "Scene.hpp"
	#include "MapLoader.hpp"

	#include "Player.hpp" 
	#include "Shoot.hpp"

	#include "Wall.hpp"

class Game : public IScene{
	public:
		Game() = default;
		~Game() = default;

		void init(sf::RenderWindow &window);
		void reset();
		void refresh();
		void handleEvent(const sf::Event event);

		void activate();
		void desactivate();

		void setChangeScene(const std::function<void()> &func);

	private:
		sf::RenderWindow *_window;
		MapLoader _loader;

		Player _player;
		Shoot _shoot;

		std::function<void()> _loadMenu;

		std::vector<std::shared_ptr<IEnvironement>> _environement;//will be a vector of walls
};

#endif /* !GAME_HPP_ */
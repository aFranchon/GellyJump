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
	#include "EndLevelTrigger.hpp"

class Game : public IScene{
	public:
		Game() = default;
		~Game() = default;

		void init(sf::RenderWindow &window);
		void reset();
		void refresh();
		void handleEvent(const sf::Event &event);

		void activate();
		void desactivate();

		void setChangeScene(const std::function<void()> &func);
		void setChangeLose(const std::function<void(const std::string &print)> &func);
		void setChangeWin(const std::function<void(const std::string &print)> &func);

	private:
		sf::RenderWindow *_window;
		MapLoader _loader;

		Player _player;
		Shoot _shoot;

		std::function<void()> _loadMenu;
		std::function<void(const std::string &print)> _loadLose;
		std::function<void(const std::string &print)> _loadWin;

		bool _ended = false;

		std::vector<std::shared_ptr<IEnvironement>> _environement;
};

#endif /* !GAME_HPP_ */
/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

	#include <SFML/Graphics.hpp>

	#include "Player/Player.hpp" 
	#include "Player/Actions/Shoot.hpp"

class Game {
	public:
		Game() = default;
		~Game() = default;

		void init(sf::RenderWindow &window);
		void refresh();
		void handleEvent(const sf::Event event);

	private:
		sf::RenderWindow *_window;

		Player _player;
		Shoot _shoot;
};

#endif /* !GAME_HPP_ */
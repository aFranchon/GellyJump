/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

    #include <SFML/Graphics.hpp>
    #include "Game.hpp"
    #include "Menu.hpp"

class Core {
	public:
		Core() = default;
		~Core() = default;

		void run();
		void createWindow();

		void loadGame();
		void loadMenu();

	protected:
	private:
		void handleEvent();

		bool _isPlay = false;

		std::vector<std::shared_ptr<IScene>> _scenes;

		sf::RenderWindow _window;
};

#endif /* !CORE_HPP_ */
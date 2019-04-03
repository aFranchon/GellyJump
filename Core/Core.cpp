/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Core
*/

#include "Core.hpp"

void Core::createWindow()
{
	_window.create(sf::VideoMode(1500, 900), "Game");
}

void Core::handleEvent()
{
	sf::Event event;
	while (_window.pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed)
			exit (0);
		_menu.handleEvent(event);
	}
}

void Core::run()
{
	_menu.init(_window);

	while (_window.isOpen())
	{
		_window.clear();
		handleEvent();
		_menu.refresh();
		_window.display();
	}
}
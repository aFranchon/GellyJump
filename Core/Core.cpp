/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Core
*/

#include "Core.hpp"

void Core::createWindow()
{
	_window.create(sf::VideoMode(1500, 900), "GellyJump");
}



void Core::handleEvent()
{
	sf::Event event;
	while (_window.pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed)
			exit (0);
		if (!_isPlay)
			_menu.handleEvent(event);
		else
			_game.handleEvent(event);
	}
}

void Core::run()
{
	_menu.init(_window, _isPlay); 
	_game.init(_window);
	while (_window.isOpen())
	{
		_window.clear();
		handleEvent();
		if (!_isPlay)
			_menu.refresh();
		else
			_game.refresh();
		_window.display();
	}
}
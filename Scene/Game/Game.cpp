/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** *
*/

#include <iostream>

#include "Game.hpp"

void Game::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		_shoot.setActive(true);
		_shoot.setStart(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*_window)));
	}

	if (event.type == sf::Event::MouseMoved) {
		_shoot.setEnd(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*_window)));
	}

	if (event.type == sf::Event::MouseButtonReleased) {
		_shoot.setActive(false);
		_player.setMovements(_shoot.getLeft() / 250, _shoot.getTop() / 100);
	}
}

void Game::init(sf::RenderWindow &window)
{
	_window = &window;
	_player.init(50, 46, "Ressources/game/player.png");
	_player.initAnimator(50, 46, 0.5, 2, 5);
	_player.addStateAnimator(10, 0);
	_player.setPosition(_window->getSize().x / 2, _window->getSize().y / 2);
}

void Game::refresh()
{
	_player.refresh();
	_shoot.draw(*_window);
	_player.draw(*_window);
}
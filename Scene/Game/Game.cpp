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
		_shoot.setStart(static_cast<sf::Vector2f>(_window->mapPixelToCoords(sf::Mouse::getPosition(*_window))));
	}

	if (event.type == sf::Event::MouseMoved) {
		_shoot.setEnd(static_cast<sf::Vector2f>(_window->mapPixelToCoords(sf::Mouse::getPosition(*_window))));
	}

	if (event.type == sf::Event::MouseButtonReleased) {
		_shoot.setActive(false);
		_player.setMovements(_shoot.getLeft() / 250, _shoot.getTop() / 100);
	}
	
	if (event.type == sf::Event::KeyPressed)
		if (event.key.code == sf::Keyboard::Escape) {
			_loadMenu();
		}
}

void Game::init(sf::RenderWindow &window)
{
	_window = &window;

	_player.init(50, 46, "Ressources/game/player.png");
	_player.initAnimator(50, 46, 0.5, 2, 5);
	_player.addStateAnimator(10, 0);
	_player.setPosition(_window->getSize().x / 2, _window->getSize().y / 2);

	Wall *wallHor = new Wall;
	wallHor->init(1000, 50, "Ressources/game/wall.png");

	for (int i = -10000; i < 10000; i += 1000) {
		wallHor->addPosition(i, -10000);
		wallHor->addPosition(i, 10000);
	}
	wallHor->addPosition(0, -1000);
	wallHor->addPosition(-1000, 0);
	wallHor->addPosition(50, 50);
	wallHor->addPosition(1000, 500);
	wallHor->addPosition(500, 1000);

	_environement.push_back(std::shared_ptr<Wall>(wallHor));

	Wall *wallVert = new Wall;
	wallVert->init(1000, 50, "Ressources/game/wall.png");
	wallVert->rotate(90);
	for (int i = -10000; i < 10000; i += 1000) {
		wallVert->addPosition(-10000, i);
		wallVert->addPosition(10000, i);
	}
	_environement.push_back(std::shared_ptr<Wall>(wallVert));
}

void Game::refresh()
{
	_player.refresh(_environement);
	auto view = _window->getView();
	view.setCenter(_player.getPosition());
	_window->setView(view);
	for (auto &elem : _environement) {
		for (int i = 0; i < elem->getPositions().size(); i++) {
			elem->setPosition(i);
			elem->draw(*_window);
		}
	}
	_player.draw(*_window);
	_shoot.draw(*_window);
}

void Game::activate()
{
	_isActive = true;
	
	auto view = _window->getView();
	view.setCenter(_player.getPosition());
	view.zoom(2);
	_window->setView(view);
}

void Game::desactivate()
{
	_isActive = false;
}

void Game::setChangeScene(const std::function<void ()> &func) {_loadMenu = func;}
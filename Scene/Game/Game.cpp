/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** *
*/

#include <iostream>

#include "MapLoader.hpp"
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
	MapLoader loader;
	loader.loadFile("Ressources/maps/map1.txt");

	_player.init(50, 46, "Ressources/game/player.png");
	_player.initAnimator(50, 46, 0.5, 2, 5);
	_player.addStateAnimator(10, 0);
	_player.setPosition(loader.getPosByChar('P', 50)[0]);

	Wall *walls = new Wall;
	walls->init(50, 50, "Ressources/game/wall.png");

	walls->addPosition(loader.getPosByChar('X', 50));
	_environement.push_back(std::shared_ptr<Wall>(walls));
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
/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** *
*/

#include <iostream>

#include "Game.hpp"

void Game::handleEvent(const sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			_loadMenu();
		}
		if (event.key.code == sf::Keyboard::R) {
			reset();
		}
	}

	if (_ended)
		return;

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
}

void Game::reset()
{
	_player.setPosition(_loader.getPosByChar('P', 50)[0]);
	_environement[0]->resetPosition(_loader.getPosByChar('S', 50));
	_environement[1]->resetPosition(_loader.getPosByChar('X', 50));

	_ended = false;
}

void Game::init(sf::RenderWindow &window)
{
	//change this to do levels
	_window = &window;
	_loader.loadFile("Ressources/maps/map1.txt");

	_player.init(50, 46, "Ressources/game/player.png");
	_player.initAnimator(50, 46, 0.5, 2, 5);
	_player.addStateAnimator(5, 0);
	_player.addStateAnimator(5, 5);

	EndLevelTrigger *end = new EndLevelTrigger;
	end->init(50, 50, "Ressources/game/door.png");
	_environement.push_back(std::shared_ptr<EndLevelTrigger>(end));

	Wall *walls = new Wall;
	walls->init(50, 50, "Ressources/game/wall.png");
	_environement.push_back(std::shared_ptr<Wall>(walls));

	reset();
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
	
	if (_ended)
		return;
	
	if (_player.hasWin()) {
		_loadWin("to set later\n");
		_ended = true;
		return;
	}

	if (_player.isDead()) {
		_loadLose();
		_ended = true;
		return;
	}
}

void Game::activate()
{
	_isActive = true;
	
	auto view = _window->getView();
	view.setCenter(_player.getPosition());
	_window->setView(view);
}

void Game::desactivate()
{
	_isActive = false;
}

void Game::setChangeScene(const std::function<void ()> &func) {_loadMenu = func;}
void Game::setChangeLose(const std::function<void ()> &func) {_loadLose = func;}
void Game::setChangeWin(const std::function<void (const std::string &print)> &func) {_loadWin = func;}
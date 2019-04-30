/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Core
*/

#include "Core.hpp"

void Core::createWindow()
{
	_window.create(sf::VideoMode::getFullscreenModes()[0], "GellyJump", sf::Style::Fullscreen);
}

void Core::handleEvent()
{
	sf::Event event;
	while (_window.pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed)
			exit (0);
		for (auto &elem : _scenes)
			if (elem->isActive())
				elem->handleEvent(event);
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Escape)
				_isPlay = false;
	}
}

void Core::loadGame()
{
	_scenes[0]->desactivate();
	_scenes[1]->activate();
	auto view = _window.getView();
	_window.setView(view);
}

void Core::loadMenu()
{
	_scenes[1]->desactivate();
	_scenes[0]->activate();
	auto view = _window.getView();
	_window.setView(view);
}

void Core::run()
{
	Menu *menu = new Menu();
	menu->init(_window, _isPlay);
	std::function<void()> changeForGame = [&]() {loadGame();};
	menu->setChangeScene(changeForGame);
	_scenes.push_back(std::shared_ptr<IScene>(menu));

	Game *game = new Game();
	game->init(_window);
	game->desactivate();
	std::function<void()> changeForMenu = [&]() {loadMenu();};
	game->setChangeScene(changeForMenu);
	_scenes.push_back(std::shared_ptr<IScene>(game));
	while (_window.isOpen())
	{
		_window.clear();
		handleEvent();
		for (auto &elem : _scenes)
			if (elem->isActive())
				elem->refresh();
		_window.display();
	}
}
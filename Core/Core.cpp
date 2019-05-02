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
	_scenes[2]->desactivate();
	_scenes[3]->desactivate();
	_scenes[0]->activate();
	auto view = _window.getView();
	_window.setView(view);
}

void Core::loadMenu(int value) {(void)value;loadMenu();}

void Core::loadWin(const std::string &print)
{
	_scenes[2]->setText(print);
	_scenes[2]->activate();
}

void Core::loadLose(const std::string &print)
{
	_scenes[3]->setText(print);
	_scenes[3]->activate();
}

void Core::resetGame(int value)
{
	(void)value;
	_scenes[1]->reset();
	_scenes[3]->desactivate();
}

void Core::nextLevel(int value)
{
	(void)value;
	//later
}

void Core::run()
{
	Menu *menu = new Menu();
	menu->init(_window);
	std::function<void()> changeForGame = [&]() {loadGame();};
	menu->setChangeScene(changeForGame);
	_scenes.push_back(std::shared_ptr<IScene>(menu));

	Game *game = new Game();
	game->init(_window);
	game->desactivate();
	std::function<void()> changeForMenu = [&]() {loadMenu();};
	game->setChangeScene(changeForMenu);
	std::function<void(const std::string &print)> openWin = [&](const std::string &print) {loadWin(print);};
	game->setChangeWin(openWin);
	std::function<void(const std::string &print)> openLose = [&](const std::string &print) {loadLose(print);};
	game->setChangeLose(openLose);
	_scenes.push_back(std::shared_ptr<IScene>(game));

	Win *win = new Win();
	win->init(_window);
	win->desactivate();
	std::function<void(int value)> changeForMenuWin = [&](int value) {loadMenu(value);};
	std::function<void(int value)> changeForNextLevel = [&](int value) {nextLevel(value);};
	win->setMenuFunc(changeForMenuWin);
	win->setNextLevelFunc(changeForNextLevel);
	_scenes.push_back(std::shared_ptr<IScene>(win));

	Lose *lose = new Lose();
	lose->init(_window);
	lose->desactivate();
	std::function<void(int value)> changeResetGame = [&](int value) {resetGame(value);};
	lose->setMenuFunc(changeForMenuWin);
	lose->setResetFunc(changeResetGame);
	_scenes.push_back(std::shared_ptr<IScene>(lose));

	while (_window.isOpen())
	{
		_window.clear(sf::Color::Green);
		handleEvent();
		for (auto &elem : _scenes)
			if (elem->isActive())
				elem->refresh();
		_window.display();
	}
}
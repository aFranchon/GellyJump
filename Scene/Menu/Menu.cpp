/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Menu
*/

#include <iostream>

#include "Menu.hpp"

void Menu::initMainMenu()
{
	std::string string = "Ressources/menu/boutton.png";
	std::string stringFont = "Ressources/fonts/manaspc.ttf";

	Button playButton;

	playButton.init(100, 100, string, stringFont);
	playButton.setActivated(true);
	sf::Vector2f pos = {_window->getSize().x / 2 - playButton.getRect().width / 2, 200};//warning convert int to flaot
	playButton.setPosition(pos);
	std::string text = "Play";
	playButton.setText(text);

	_mainButtons.push_back(std::make_shared<Button>(playButton));

	Button optionButton;

	optionButton.init(100, 100, string, stringFont);
	optionButton.setActivated(true);
	pos = {_window->getSize().x / 2 - optionButton.getRect().width / 2, 400};//warning convert int to flaot
	optionButton.setPosition(pos);
	text = "Options";
	optionButton.setText(text);

	_mainButtons.push_back(std::make_shared<Button>(optionButton));

	Button quitButton;

	quitButton.init(100, 100, string, stringFont);
	quitButton.setActivated(true);
	pos = {_window->getSize().x / 2 - quitButton.getRect().width / 2, 600};//warning convert int to flaot
	quitButton.setPosition(pos);
	text = "Quit";
	quitButton.setText(text);
	void(*function_type)() = &Menu::quit;
	quitButton.setAction(function_type);

	_mainButtons.push_back(std::make_shared<Button>(quitButton));
}

void Menu::initOptionMenu()
{
	Button newButton;
	std::string string = "Ressources/menu/boutton.png";
	std::string stringFont = "Ressources/fonts/manaspc.ttf";

	newButton.init(100, 100, string, stringFont);
	newButton.setActivated(false);
	sf::Vector2f pos = {400, 400};
	newButton.setPosition(pos);
	std::string text = "Back";
	newButton.setText(text);

	_optionButtons.push_back(std::make_shared<Button>(newButton));
}

void Menu::linkButtons()
{
	_mainButtons[1]->setHide(_mainButtons);
	_mainButtons[1]->setShow(_optionButtons);

	for (auto &elem : _mainButtons)
		_buttons.push_back(elem);

	_optionButtons[0]->setHide(_optionButtons);
	_optionButtons[0]->setShow(_mainButtons);

	for (auto &elem : _optionButtons)
		_buttons.push_back(elem);

}

void Menu::quit()
{
	exit(0);
}

void Menu::init(sf::RenderWindow &window)
{
	_window = &window;

	initMainMenu();
	initOptionMenu();
	
	linkButtons();
} 

void Menu::handleEvent(const sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for (auto &elem : _buttons)
			if (elem->isActivated())
				elem->onClick(sf::Mouse::getPosition(*_window));
	}

	if (event.type == sf::Event::MouseButtonReleased) {
		for (auto &elem : _buttons) {
			if (elem->isActivated())
				elem->onRelease(sf::Mouse::getPosition(*_window));
		}
	}
}

void Menu::refresh()
{
	for (auto &elem : _buttons)
		elem->draw(*_window);
}
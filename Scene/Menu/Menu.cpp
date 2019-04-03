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
	Button newButton;
	std::string string = "Ressources/boutton.png";

	newButton.init(100, 100, string);
	newButton.setActivated(true);
	sf::Vector2f pos = {200, 200};
	newButton.setPosition(pos);
	std::string text = "Options";
	newButton.setText(text);

	_mainButtons.push_back(std::make_shared<Button>(newButton));
}

void Menu::initOptionMenu()
{
	Button newButton;
	std::string string = "Ressources/boutton.png";

	newButton.init(100, 100, string);
	newButton.setActivated(false);
	sf::Vector2f pos = {400, 400};
	newButton.setPosition(pos);
	std::string text = "Back";
	newButton.setText(text);

	_optionButtons.push_back(std::make_shared<Button>(newButton));
}

void Menu::linkButtons()
{
	_mainButtons[0]->setHide(_mainButtons);
	_mainButtons[0]->setShow(_optionButtons);

	for (auto &elem : _mainButtons)
		_buttons.push_back(elem);

	_optionButtons[0]->setHide(_optionButtons);
	_optionButtons[0]->setShow(_mainButtons);

	for (auto &elem : _optionButtons)
		_buttons.push_back(elem);

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
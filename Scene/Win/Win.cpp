/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Win
*/

#include <iostream>
#include "Win.hpp"

void Win::init(sf::RenderWindow &window)
{
	_window = &window;
	//laisser de la place pour un background

	_menu.init();
	_menu.setActivated(true);
	sf::Vector2f pos = {static_cast<float>(_window->getSize().x / 3), static_cast<float>((_window->getSize().y / 4) * 3)};
	_menu.setPosition(pos);
	std::string text = "Menu";
	_menu.setText(text);

	_nextLevel.init();
	_nextLevel.setActivated(true);
	pos = {static_cast<float>((_window->getSize().x / 3) * 2), static_cast<float>((_window->getSize().y / 4) * 3)};
	_nextLevel.setPosition(pos);
	text = "Next Level";
	_nextLevel.setText(text);
}

void Win::handleEvent(const sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::R) {
			desactivate();
		}
	}

	if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		_menu.onClick(sf::Mouse::getPosition(*_window));
		_nextLevel.onClick(sf::Mouse::getPosition(*_window));
	}

	if (event.type == sf::Event::MouseButtonReleased) {
		_menu.onRelease(sf::Mouse::getPosition(*_window));
		_nextLevel.onRelease(sf::Mouse::getPosition(*_window));
	}
}

void Win::refresh()
{
	_menu.draw(*_window);
	_nextLevel.draw(*_window);
}

void Win::setText(const std::string &print)
{
	_text.setString(print);
}

void Win::activate()
{
	_isActive = true;
}

void Win::desactivate()
{
	_isActive = false;
}
/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Win
*/

#include <iostream>
#include "Win.hpp"

void Win::init(sf::RenderWindow &window, const std::string &font)
{
	_window = &window;
	//laisser de la place pour un background

	_menu.init();
	_menu.setActivated(true);
	std::string text = "Menu";
	_menu.setText(text);

	_nextLevel.init();
	_nextLevel.setActivated(true);
	text = "Next Level";
	_nextLevel.setText(text);

	if (!_font.loadFromFile(font))
		throw;
	_text.setFont(_font);
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
	_window->draw(_text);
}

void Win::setText(const std::string &print)
{
	_text.setCharacterSize(80);
	_text.setString(print);
	_text.setColor(sf::Color::White);
}

void Win::activate()
{
	sf::Vector2f pos = {static_cast<float>(_window->getSize().x / 3 + (_window->getView().getCenter().x - _window->getView().getSize().x / 2)),
	static_cast<float>((_window->getSize().y / 4) * 3 + (_window->getView().getCenter().y - _window->getView().getSize().y / 2))};
	_menu.setPosition(pos);

	pos = {static_cast<float>((_window->getSize().x / 3) * 2 + (_window->getView().getCenter().x - _window->getView().getSize().x / 2)),
	static_cast<float>((_window->getSize().y / 4) * 3 + (_window->getView().getCenter().y - _window->getView().getSize().y / 2))};
	_nextLevel.setPosition(pos);
	
	_text.setOrigin(_text.getLocalBounds().left + _text.getLocalBounds().width/2.0f, _text.getLocalBounds().top  + _text.getLocalBounds().height/2.0f);
	pos = {static_cast<float>((_window->getSize().x / 2) + (_window->getView().getCenter().x - _window->getView().getSize().x / 2)),
	static_cast<float>((_window->getSize().y / 4) + (_window->getView().getCenter().y - _window->getView().getSize().y / 2))};
	_text.setPosition(pos);

	_isActive = true;
}

void Win::desactivate()
{
	_isActive = false;
}
/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Button
*/

#include <iostream>

#include "Button.hpp"

void Button::init(int height, int width, std::string &texture)
{	
	_rect.top = 0;
	_rect.left = 0;
	_rect.height = height;
	_rect.width = width;

	if (!_texture.loadFromFile(texture, _rect))
		throw;

	_sprite.setTexture(_texture);
	_sprite.setTextureRect(_rect);
}

void Button::onClick(sf::Vector2i mouse)
{
	if (	_sprite.getPosition().x < mouse.x && _sprite.getPosition().x + _rect.width > mouse.x &&
		_sprite.getPosition().y < mouse.y && _sprite.getPosition().y + _rect.height > mouse.y) {
			_rect.top += _rect.height;
	} else {
			_rect.top = 0;
			_rect.left = 0;
	}
}

void Button::onRelease(sf::Vector2i mouse)
{
	if (	_sprite.getPosition().x < mouse.x && _sprite.getPosition().x + _rect.width > mouse.x &&
		_sprite.getPosition().y < mouse.y && _sprite.getPosition().y + _rect.height > mouse.y &&
		(_rect.top != 0 || _rect.left != 0)) {
			_rect.top += _rect.height;
			for (auto &elem : _toHide)
				elem->setActivated(false);
			for (auto &elem : _toShow)
				elem->setActivated(true);
			for (auto &elem : _action)
				elem();

	} else {
			_rect.top = 0;
			_rect.left = 0;
	}
}

void Button::draw(sf::RenderWindow &window)
{
	if (_isActivated) {
		window.draw(_sprite);
		window.draw(_text);
	}
}

void Button::setPosition(sf::Vector2f &position) 
{
	_sprite.setPosition(position);
	_text.setPosition(_sprite.getPosition().x + 20, _sprite.getPosition().y + 20);//faire en fonction de la taille du sprite et tout et tout
}

void Button::setTexture(sf::Texture &texture) {_texture = texture;}
void Button::setText(std::string text) {_text.setString(text);}
void Button::setRect(sf::IntRect &rect) {_rect = rect;}
void Button::setHide(Button &button) {_toHide.push_back(std::make_shared<Button>(button));}

void Button::setHide(std::vector<std::shared_ptr<Button>> &buttons) 
{
	for (auto &elem : buttons)
		_toHide.push_back(elem);
}

void Button::setShow(Button &button) {_toShow.push_back(std::make_shared<Button>(button));}

void Button::setShow(std::vector<std::shared_ptr<Button>> &buttons) 
{
	for (auto &elem : buttons)
		_toShow.push_back(elem);
}

void Button::setAction(function_type &action) {_action.push_back(action);}
void Button::setAction(std::vector<function_type> &actions) {_action.insert(_action.end(), actions.begin(), actions.end());}

sf::Vector2f Button::getPosition() const {return _sprite.getPosition();}
sf::Texture Button::getTexture() const {return _texture;}
sf::Text Button::getText() const {return _text;}
sf::IntRect Button::getRect() const {return _rect;}
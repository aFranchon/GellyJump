/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Button
*/

#include <iostream>

#include "Button.hpp"

Button::Button(const int height, const int width, const std::string &texture, const std::string &font)
{
	init(height, width, texture, font);
}

void Button::init(const int height, const int width, const std::string &texture, const std::string &font)
{
	sf::IntRect rect;
	rect.top = 0;
	rect.left = 0;
	rect.height = height;
	rect.width = width;
	_rects.push_back(rect);

	sf::Sprite sprite;
	sprite.setOrigin(rect.width / 2, rect.height / 2);
	_sprites.push_back(sprite);

	sf::Texture textureButton;
	if (!textureButton.loadFromFile(texture, rect))
		throw;
	_textures.push_back(textureButton);

	sf::Font fontButton;
	if (!fontButton.loadFromFile(font))
		throw;
	_fonts.push_back(fontButton);

	sf::Text text;
	_texts.push_back(text);
}

void Button::onClick(sf::Vector2i mouse)
{
	if (_sprites[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse))) {
		_rects[0].top += _rects[0].height;
	} else {
		_rects[0].top = 0;
		_rects[0].left = 0;
	}
}

int Button::onRelease(sf::Vector2i mouse)
{
	if (_sprites[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse)) && (_rects[0].top != 0 || _rects[0].left != 0)) {
		_rects[0].top += _rects[0].height;
		for (auto &elem : _toHide)
			elem->setActivated(false);
		for (auto &elem : _toShow)
			elem->setActivated(true);
		for (auto &elem : _action) {
			elem(0);
		}
	} else {
		_rects[0].top = 0;
		_rects[0].left = 0;
	}
	return 0;
}

void Button::onMove(sf::Vector2i mouse)
{
	(void)mouse;
}

void Button::draw(sf::RenderWindow &window)
{
	if (_sprites[0].getTexture() == nullptr) {
		_sprites[0].setTexture(_textures[0]);
		_sprites[0].setPosition(_sprites[0].getPosition());
	}

	if (_texts[0].getFont() == nullptr) {
		_texts[0].setFont(_fonts[0]);
		sf::FloatRect textRect = _texts[0].getLocalBounds();
		_texts[0].setOrigin(_texts[0].getLocalBounds().left + _texts[0].getLocalBounds().width/2.0f, _texts[0].getLocalBounds().top  + _texts[0].getLocalBounds().height/2.0f);
		_texts[0].setPosition(_sprites[0].getPosition());
	}

	if (_isActivated) {
		window.draw(_sprites[0]);
		window.draw(_texts[0]);
	}
}

void Button::setPosition(sf::Vector2f &position) 
{
	_sprites[0].setPosition(position);
	
	sf::FloatRect textRect = _texts[0].getLocalBounds();
	_texts[0].setOrigin(_texts[0].getLocalBounds().left + _texts[0].getLocalBounds().width/2.0f, _texts[0].getLocalBounds().top  + _texts[0].getLocalBounds().height/2.0f);
	_texts[0].setPosition(_sprites[0].getPosition());
}

void Button::setTexture(sf::Texture &texture) {_textures[0] = texture;}
void Button::setText(std::string &text) {_texts[0].setString(text);}
void Button::setRect(sf::IntRect &rect) {_rects[0] = rect;}

sf::Vector2f Button::getPosition() const {return _sprites[0].getPosition();}
sf::Texture Button::getTexture() const {return _textures[0];}
sf::Text Button::getText() const {return _texts[0];}
sf::IntRect Button::getRect() const {return _rects[0];}
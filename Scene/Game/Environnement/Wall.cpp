/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Wall
*/

#include "Wall.hpp"

void Wall::init(const int &height, const int &width, const std::string &texture)
{
	_wallRect.top = 0;
	_wallRect.left = 0;
	_wallRect.height = height;
	_wallRect.width = width;

	if (!_wallTexture.loadFromFile(texture))
		throw;
	_wallSprite.setTexture(_wallTexture);
}

void Wall::draw(sf::RenderWindow &window) {_wallRenderer.draw(window, _wallSprite);}

void Wall::setPosition(const sf::Vector2f &pos) {_wallSprite.setPosition(pos);}
void Wall::setPosition(const float &x, const float &y) {_wallSprite.setPosition(x, y);}

const sf::Sprite Wall::getSprite() const {return _wallSprite;}
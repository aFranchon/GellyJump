/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Wall
*/

#include "Wall.hpp"

void Wall::init(const int &width, const int &height, const std::string &texture)
{
	_wallRect.top = 0;
	_wallRect.left = 0;
	_wallRect.height = height;
	_wallRect.width = width;

	if (!_wallTexture.loadFromFile(texture))
		throw;
	_wallSprite.setTexture(_wallTexture);
	_wallSprite.setTextureRect(_wallRect);
	_tag = "Wall";
}

void Wall::draw(sf::RenderWindow &window) {_wallRenderer.draw(window, _wallSprite);}
void Wall::rotate(int rotation) {_wallSprite.setRotation(rotation);}

void Wall::addPosition(const sf::Vector2f &pos) {_positions.push_back(pos);}
void Wall::addPosition(const float &x, const float &y) {_positions.push_back(sf::Vector2f(x, y));}
void Wall::addPosition(const std::vector<sf::Vector2f> &pos) 
{
	for (auto &elem : pos)
		_positions.push_back(elem);
}

void Wall::setPosition(const int &i) {_wallSprite.setPosition(_positions[i]);}
void Wall::setActive(const bool &active) {_wallRenderer.setActive(active);}

sf::Sprite Wall::getSprite() const {return _wallSprite;}
const bool Wall::isActive() const {return _wallRenderer.isActive();}
const std::vector<sf::Vector2f> &Wall::getPositions() const {return _positions;}
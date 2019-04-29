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
	_tag = "Wall";
}

void Wall::draw(sf::RenderWindow &window) {_wallRenderer.draw(window, _wallSprite);}

void Wall::addPosition(const sf::Vector2f &pos) {_positions.push_back(pos);}
void Wall::addPosition(const float &x, const float &y) {_positions.push_back(sf::Vector2f(x, y));}
void Wall::setPosition(const int &i) {_wallSprite.setPosition(_positions[i]);}
void Wall::setActive(const bool &active) {_wallRenderer.setActive(active);}

sf::Sprite Wall::getSprite() const {return _wallSprite;}
const bool Wall::isActive() const {return _wallRenderer.isActive();}
const std::vector<sf::Vector2f> &Wall::getPositions() const {return _positions;}
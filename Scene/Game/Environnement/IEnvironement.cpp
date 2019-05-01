/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** IEnvironement
*/

#include "IEnvironement.hpp"
void IEnvironement::draw(sf::RenderWindow &window) {_wallRenderer.draw(window, _wallSprite);}
void IEnvironement::rotate(int rotation) {_wallSprite.setRotation(rotation);}

void IEnvironement::addPosition(const sf::Vector2f &pos) {_positions.push_back(pos);}
void IEnvironement::addPosition(const float &x, const float &y) {_positions.push_back(sf::Vector2f(x, y));}
void IEnvironement::addPosition(const std::vector<sf::Vector2f> &pos) 
{
	for (auto &elem : pos)
		_positions.push_back(elem);
}

void IEnvironement::resetPosition(const sf::Vector2f &pos) {_positions.clear();_positions.push_back(pos);}
void IEnvironement::resetPosition(const float &x, const float &y) {_positions.clear();_positions.push_back(sf::Vector2f(x, y));}
void IEnvironement::resetPosition(const std::vector<sf::Vector2f> &pos) 
{
	_positions.clear();
	for (auto &elem : pos)
		_positions.push_back(elem);
}

void IEnvironement::setPosition(const int &i) {_wallSprite.setPosition(_positions[i]);}
void IEnvironement::setActive(const bool &active) {_wallRenderer.setActive(active);}

sf::Sprite IEnvironement::getSprite() const {return _wallSprite;}
const bool IEnvironement::isActive() const {return _wallRenderer.isActive();}
const std::vector<sf::Vector2f> &IEnvironement::getPositions() const {return _positions;}
/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Shoot
*/

#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include "Shoot.hpp"

void Shoot::draw(sf::RenderWindow &window)
{
	if (!_isActive)
		return;
	sf::Vertex line[] = {
		sf::Vertex(_start, sf::Color::Green),
		sf::Vertex(_end, sf::Color::Red)
	};
	
	window.draw(line, 2, sf::Lines);
}

bool Shoot::isActive() const {return _isActive;}
float Shoot::getTop() const {return _end.y - _start.y;}
float Shoot::getLeft() const {return _end.x - _start.x;}

void Shoot::setStart(const sf::Vector2f &start, const sf::Vector2f &view) {_start = sf::Vector2f(start.x + view.x, start.y + view.y);}

void Shoot::setEnd(const sf::Vector2f &end, const sf::Vector2f &view) {_end = sf::Vector2f(end.x + view.x, end.y + view.y);;}
void Shoot::setActive(bool active) {_isActive = active;}
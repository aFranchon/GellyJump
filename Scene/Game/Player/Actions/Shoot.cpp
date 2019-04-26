/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Shoot
*/

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

void Shoot::setStart(const sf::Vector2f &start) {_start = start;}
void Shoot::setEnd(const sf::Vector2f &end) {_end = end;}
void Shoot::setActive(bool active) {_isActive = active;}
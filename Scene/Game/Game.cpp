/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** *
*/

#include "Game.hpp"

void Game::handleEvent(sf::Event event)
{
	//stop
}

void Game::init(sf::RenderWindow &window)
{
	_window = &window;
	_player.init(50, 46, "Ressources/game/player.png");
	_player.initAnimator(50, 46, 0.5, 2, 5);
	_player.addStateAnimator(10, 0);
}

void Game::refresh()
{
	_player.refresh();
	_player.draw(*_window);
}
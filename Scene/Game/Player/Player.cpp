/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Player
*/

#include <iostream>
#include "Player.hpp"

void Player::init(const int height, const int width, const std::string &texture)
{
	_playerRect.top = 0;
	_playerRect.left = 0;
	_playerRect.height = height;
	_playerRect.width = width;

	if (!_playerTexture.loadFromFile(texture))
		throw;
	_playerSprite.setTexture(_playerTexture);
}

void Player::addStateAnimator(int numberOfChanges, int startOfState) {_animator.addState(numberOfChanges, startOfState);}
void Player::initAnimator(int width, int height, float animTime, int row, int col, int currentState) 
{_animator.init(width, height, animTime, row, col, currentState);}

void Player::refresh()
{
	_animator.refresh(_playerRect);
	_playerSprite.setTextureRect(_playerRect);
}

void Player::draw(sf::RenderWindow &window) {_playerRenderer.draw(window, _playerSprite);}
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

	_move.setSlowDown(1.005);
	_jump.setSlowDown(1.01);
}

void Player::addStateAnimator(int numberOfChanges, int startOfState) {_animator.addState(numberOfChanges, startOfState);}
void Player::initAnimator(int width, int height, float animTime, int row, int col, int currentState) 
{_animator.init(width, height, animTime, row, col, currentState);}

void Player::refresh()
{
	_animator.refresh(_playerRect);
	_playerSprite.setTextureRect(_playerRect);

	float x = _playerSprite.getPosition().x;
	float y = _playerSprite.getPosition().y;
	_move.move(x);
	_jump.jump(y);
	//_physics.fall(y);
	_playerSprite.setPosition(x, y);

}

void Player::draw(sf::RenderWindow &window) {_playerRenderer.draw(window, _playerSprite);}

sf::Vector2f Player::getPosition() const {return _playerSprite.getPosition();}

void Player::setPosition(const sf::Vector2f &pos) {_playerSprite.setPosition(pos);}
void Player::setPosition(const float &x, const float &y) {_playerSprite.setPosition(x, y);}

void Player::setMovements(const float &x, const float &y)
{
	_move.setSpeed(x);
	_jump.setSpeed(y);
}
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
	_physics.setWeight(1);
	_physics.setFallingIncrease(1);
	_physics.setFalling(true);
}

void Player::addStateAnimator(int numberOfChanges, int startOfState) {_animator.addState(numberOfChanges, startOfState);}
void Player::initAnimator(int width, int height, float animTime, int row, int col, int currentState) 
{_animator.init(width, height, animTime, row, col, currentState);}

void Player::refresh(const std::vector<std::shared_ptr<IEnvironement>> &environements)
{
	_animator.refresh(_playerRect);
	_playerSprite.setTextureRect(_playerRect);

	sf::Vector2f pos = _playerSprite.getPosition();
	if (!_move.getJustSet() && checkCollision(environements, sf::Vector2f(_move.getNext(pos.x), pos.y)))
		_move.hit();
	_move.move(pos.x);
	if (checkCollision(environements, sf::Vector2f(pos.x, _jump.getNext(pos.y))))
		_jump.hit();
	else 
		_jump.jump(pos.y);
	if (checkCollision(environements, sf::Vector2f(pos.x, _physics.getNext(pos.y)))) {
		_physics.hit();
		_jump.setSpeed(_physics.getIncrease() * -1);
	} else
		_physics.fall(pos.y);
	_playerSprite.setPosition(pos);
}

bool Player::checkCollision(const std::vector<std::shared_ptr<IEnvironement>> &environements, const sf::Vector2f &pos)
{
	sf::Vector2f temp = _playerSprite.getPosition();

	_playerSprite.setPosition(pos);
	for (auto &elem : environements) {
		for (int i = 0; i < elem->getPositions().size(); i++) {
			elem->setPosition(i);
			if (elem->getTag() == "Wall" && _playerSprite.getGlobalBounds().intersects(elem->getSprite().getGlobalBounds()))
				return true;
		}
	}
	return false;
}

void Player::draw(sf::RenderWindow &window) {_playerRenderer.draw(window, _playerSprite);}

const sf::Vector2f Player::getPosition() const {return _playerSprite.getPosition();}
const bool Player::isActive() const {return _playerRenderer.isActive();}

void Player::setPosition(const sf::Vector2f &pos) {_playerSprite.setPosition(pos);}
void Player::setPosition(const float &x, const float &y) {_playerSprite.setPosition(x, y);}
void Player::setActive(const bool &active) {_playerRenderer.setActive(active);}

void Player::setMovements(const float &x, const float &y)
{
	_move.setSpeed(x);
	_jump.setSpeed(y);
	_physics.reset();
}
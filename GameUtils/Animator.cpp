/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Animator
*/

#include <iostream>
#include <unistd.h>

#include "Animator.hpp"

void Animator::init(int height, int width, float animTime, int row, int col, int currentState)
{
	_width = width;
	_height = height;
	_animTime = animTime;
	_currentState = currentState;
	_row = row;
	_col = col;
}

void Animator::refresh(sf::IntRect &rect)
{
	std::pair<int, int> currentState = _animState[_currentState];

	if (_clock.getSeconds() <= _animTime)
		return;
	rect.top = 0;
	rect.left = 0;
	_clock.reset();
	_currentChange++;
	if (_currentChange >= currentState.first) {
		_currentChange = 0;
	}
	if (_isVert) {
		for (auto i = 0; i < _currentChange + currentState.second; i++) {
			rect.top += _height;
			if (rect.top >= _height * _col) {
				rect.top = 0;
				rect.left += _width;
			}
		}
	} else {
		for (auto i = 0; i < _currentChange + currentState.second; i++) {
			rect.left += _width;
			if (rect.left >= _width * _col) {
				rect.left = 0;
				rect.top += _height;
			}
		}
	}
}

void Animator::changeState(int state) 
{
	_currentState = state;
	_currentChange = 0;
}

void Animator::addState(int numberOfChanges, int startOfState) {_animState.push_back(std::pair<int, int>(numberOfChanges, startOfState));}
void Animator::setSize(int width, int height) {_width = width; _height = height;}
void Animator::setRow(int row) {_row = row;}
void Animator::setCol(int col) {_col = col;}
/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Animator
*/

#include "Animator.hpp"

void Animator::init(int width, int height, float animTime, int currentState, int row, int col)
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
	int width;
	int height;

	_currentChange++;
	if (_currentChange == currentState.first)
		_currentChange = 0;
	if (_isVert) {
		for (auto i = 0; i <= _currentChange; i++) {
			height += _height;
			if (height >= _height * _col) {
				height = 0;
				width += _width;
			}
		}
	} else {
		for (auto i = 0; i <= _currentChange; i++) {
			width += _width;
			if (width >= _width * _col) {
				width = 0;
				height += _height;
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
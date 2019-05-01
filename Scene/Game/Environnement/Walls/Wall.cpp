/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Wall
*/

#include "Wall.hpp"

void Wall::init(const int &width, const int &height, const std::string &texture)
{
	_envRect.top = 0;
	_envRect.left = 0;
	_envRect.height = height;
	_envRect.width = width;

	if (!_envTexture.loadFromFile(texture))
		throw;
	_envSprite.setTexture(_envTexture);
	_envSprite.setTextureRect(_envRect);
	_tag = "Wall";
}
/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Wall
*/

#include "Wall.hpp"

void Wall::init(const int &width, const int &height, const std::string &texture)
{
	_wallRect.top = 0;
	_wallRect.left = 0;
	_wallRect.height = height;
	_wallRect.width = width;

	if (!_wallTexture.loadFromFile(texture))
		throw;
	_wallSprite.setTexture(_wallTexture);
	_wallSprite.setTextureRect(_wallRect);
	_tag = "Wall";
}
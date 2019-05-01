/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** MapLoader
*/

#include <fstream>
#include <iostream>

#include "MapLoader.hpp"

const std::vector<sf::Vector2f>MapLoader::getPosByChar(const char &toGet, const int &tileSize)
{
	std::vector<sf::Vector2f> pos;

	for (auto i = 0; i < _map.size(); i++)
		for (auto j = 0; j < _map[i].size(); j++)
			if (_map[i][j] == toGet)
				pos.push_back(sf::Vector2f(j * tileSize, i * tileSize));
	
	return pos;
}

void MapLoader::loadFile(const std::string &fileName) 
{
	std::ifstream myFile;
	std::string line;
	
	myFile.open(fileName);
	while (myFile.is_open() && getline(myFile, line))
		_map.push_back(line);
	myFile.close();
}
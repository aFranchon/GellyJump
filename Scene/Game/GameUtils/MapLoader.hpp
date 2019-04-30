/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** MapLoader
*/

#ifndef MAPLOADER_HPP_
    #define MAPLOADER_HPP_

    #include <string>
    #include <vector>

    #include <SFML/Graphics.hpp>

class MapLoader {
	public:
		MapLoader() = default;
		~MapLoader() = default;

		void loadFile(const std::string &fileName);

		const std::vector<sf::Vector2f> getPosByChar(const char &toGet, const int &tileSize);

	protected:
	private:
		std::vector<std::string> _map;
};

#endif /* !MAPLOADER_HPP_ */
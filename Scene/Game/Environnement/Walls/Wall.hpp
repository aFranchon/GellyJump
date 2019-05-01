/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Wall
*/

#ifndef WALL_HPP_
    #define WALL_HPP_

    #include "SpriteRenderer.hpp"
    #include "IEnvironement.hpp"

class Wall : public IEnvironement {
	public:
		Wall() = default;
		Wall(const int &height, const int &width, const std::string &texture) {init(height, width, texture);};
		~Wall() = default;

		void init(const int &height, const int &width, const std::string &texture);

	protected:
	private:
};

#endif /* !WALL_HPP_ */
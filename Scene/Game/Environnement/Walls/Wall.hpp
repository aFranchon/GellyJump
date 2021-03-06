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

		void init(const int &width, const int &height, const std::string &texture)
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

	protected:
	private:
};

#endif /* !WALL_HPP_ */
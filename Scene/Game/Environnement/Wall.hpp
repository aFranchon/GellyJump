/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Wall
*/

#ifndef WALL_HPP_
    #define WALL_HPP_

    #include "SpriteRenderer.hpp"

class Wall {
	public:
		Wall() = default;
		Wall(const int &height, const int &width, const std::string &texture) {init(height, width, texture);};
		~Wall() = default;

		void init(const int &height, const int &width, const std::string &texture);

		void draw(sf::RenderWindow &window);

		//setters
		void setPosition(const sf::Vector2f &pos);
		void setPosition(const float &x, const float &y);

		//getters
		const sf::Sprite getSprite() const;

	protected:
	private:
		SpriteRenderer _wallRenderer;

		sf::Texture _wallTexture;
		sf::IntRect _wallRect;
		sf::Sprite _wallSprite;
};

#endif /* !WALL_HPP_ */
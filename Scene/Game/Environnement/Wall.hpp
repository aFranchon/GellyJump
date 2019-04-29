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

		void draw(sf::RenderWindow &window);

		//setters
		void addPosition(const sf::Vector2f &pos);
		void addPosition(const float &x, const float &y);
		void setPosition(const int &i);
		void setDisplay(const bool &isDisplay);
		void setActive(const bool &active);

		//getters
		sf::Sprite getSprite() const;
		const bool isActive() const;
		const std::vector<sf::Vector2f> &getPositions() const;

	protected:
	private:
		SpriteRenderer _wallRenderer;

		sf::Texture _wallTexture;
		sf::IntRect _wallRect;
		sf::Sprite _wallSprite;
		std::vector<sf::Vector2f> _positions;
};

#endif /* !WALL_HPP_ */
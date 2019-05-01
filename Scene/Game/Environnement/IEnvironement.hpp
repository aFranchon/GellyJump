/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** IEnvironement
*/

#ifndef IENVIRONEMENT_HPP_
    #define IENVIRONEMENT_HPP_

    #include "SpriteRenderer.hpp"

class IEnvironement {
	public:
		virtual ~IEnvironement() {};

		virtual void draw(sf::RenderWindow &window);

		//getters
		void addPosition(const sf::Vector2f &pos);
		void addPosition(const float &x, const float &y);
		void addPosition(const std::vector<sf::Vector2f> &pos);
		void resetPosition(const sf::Vector2f &pos);
		void resetPosition(const std::vector<sf::Vector2f> &pos);
		void resetPosition(const float &x, const float &y);
		void setPosition(const int &i);
		void setActive(const bool &active);
		void setTag(const std::string &tag) {_tag = tag;};
		void rotate(int rotation);

		//setters
		sf::Sprite getSprite() const;
		const bool isActive() const;
		const std::vector<sf::Vector2f> &getPositions() const;
		const std::string &getTag() const {return _tag;};
		
	protected:
		std::string _tag;
		SpriteRenderer _wallRenderer;

		sf::Texture _wallTexture;
		sf::IntRect _wallRect;
		sf::Sprite _wallSprite;
		std::vector<sf::Vector2f> _positions;
	private:
};

#endif /* !IENVIRONEMENT_HPP_ */
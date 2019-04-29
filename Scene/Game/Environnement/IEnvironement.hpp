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

		virtual void draw(sf::RenderWindow &window) = 0;

		//getters
		virtual void addPosition(const sf::Vector2f &pos) = 0;
		virtual void addPosition(const float &x, const float &y) = 0;
		virtual void setPosition(const int &i) = 0;
		virtual void setActive(const bool &active) = 0;
		void setTag(const std::string &tag) {_tag = tag;};

		//setters
		virtual sf::Sprite getSprite() const = 0;
		virtual const bool isActive() const = 0;
		virtual const std::vector<sf::Vector2f> &getPositions() const = 0;
		const std::string &getTag() const {return _tag;};
		
	protected:
		std::string _tag;
	private:
};

#endif /* !IENVIRONEMENT_HPP_ */
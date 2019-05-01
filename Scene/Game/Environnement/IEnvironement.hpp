/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** IEnvironement
*/

#ifndef IENVIRONEMENT_HPP_
    #define IENVIRONEMENT_HPP_

	#include "Player.hpp"

class Player;

class IEnvironement {
	public:
		virtual ~IEnvironement() {};

		void draw(sf::RenderWindow &window);
		virtual void onCollsion(Player &player) {};
        virtual void onCollsion(IEnvironement &environement) {};

		//setting on positions
        void addPosition(const sf::Vector2f &pos);
        void addPosition(const float &x, const float &y);
        void addPosition(const std::vector<sf::Vector2f> &pos);
        void resetPosition(const sf::Vector2f &pos);
        void resetPosition(const std::vector<sf::Vector2f> &pos);
        void resetPosition(const float &x, const float &y);

		//getters
        sf::Sprite getSprite() const;
        const bool isActive() const;
        const std::vector<sf::Vector2f> &getPositions() const;
        const std::string &getTag() const {return _tag;};

        //setters
		void setPosition(const int &i);
		void setActive(const bool &active);
		void setTag(const std::string &tag) {_tag = tag;};
		void rotate(int rotation);

	protected:
		std::string _tag;
		SpriteRenderer _envRenderer;

		sf::Texture _envTexture;
		sf::IntRect _envRect;
		sf::Sprite _envSprite;
		std::vector<sf::Vector2f> _positions;
	private:
};

#endif /* !IENVIRONEMENT_HPP_ */
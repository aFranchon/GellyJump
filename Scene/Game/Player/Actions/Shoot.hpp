/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Shoot
*/

#ifndef SHOOT_HPP_
    #define SHOOT_HPP_

    #include <SFML/Graphics.hpp>

class Shoot {
	public:
		Shoot() = default;
		~Shoot() = default;

		void setStart();

		void draw(sf::RenderWindow &window);
		
		//getters
		bool isActive() const;
		float getTop() const;
		float getLeft() const;
		
		//setters
		void setStart(const sf::Vector2f &start, const sf::Vector2f &view = sf::Vector2f(0, 0));
		void setEnd(const sf::Vector2f &end, const sf::Vector2f &view = sf::Vector2f(0, 0));
		void setActive(bool active);

	protected:
	private:
		sf::Vector2f _start;
		sf::Vector2f _end;
		
		bool _isActive = false;
};

#endif /* !SHOOT_HPP_ */

/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Animator
*/

#ifndef ANIMATOR_HPP_
    #define ANIMATOR_HPP_

    #include <SFML/Graphics/Texture.hpp>
    #include <SFML/Graphics/Rect.hpp>
    #include <SFML/Graphics/Sprite.hpp>
    #include <ctime>

    #include "Clock.hpp"

class Animator {
	public:
		Animator() = default;
		~Animator() = default;

		void init(int height, int width, float animTime, int row = 1, int col = 1, int currentState = 0);
		void addState(int numberOfChanges, int startOfState);

		void refresh(sf::IntRect &rect);

		//setters
		void setSize(int width, int height);
		void setRow(int row);
		void setCol(int col);
		void changeState(int state);

	protected:
	private:
		std::vector<std::pair<int, int>> _animState;

		int _width;
		int _height;
		float _animTime;
		int _currentState;

		Clock<> _clock;

		int _currentChange = 0;

		int _row;
		int _col;
		bool _isVert = false;
};

#endif /* !ANIMATOR_HPP_ */
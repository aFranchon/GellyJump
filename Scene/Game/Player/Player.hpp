/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "Animator.hpp"
    #include "SpriteRenderer.hpp"

    #include "Jump.hpp"
    #include "Move.hpp"
    #include "Physics.hpp"

class Player {
	public:
		Player() = default;
		~Player() = default;

		void init(const int height, const int width, const std::string &texture);
		void initAnimator(int width, int height, float animTime, int row = 1, int col = 1, int currentState = 0);
		void addStateAnimator(int numberOfChanges, int startOfState);

		void refresh();
		void draw(sf::RenderWindow &window);

		//getters
		sf::Vector2f getPosition() const;

		//setters
		void setPosition(const sf::Vector2f &pos);
		void setPosition(const float &x, const float &y);
		void setMovements(const float &x, const float &y);

	protected:
	private:
		Animator _animator;
		SpriteRenderer _playerRenderer;

		sf::Texture _playerTexture;
		sf::IntRect _playerRect;
		sf::Sprite _playerSprite;

		//physics
		Jump _jump;
		Move _move;
		Physics _physics;
};

#endif /* !PLAYER_HPP_ */
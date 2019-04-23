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

class Player {
	public:
		Player() = default;
		~Player() = default;

		void init();

	protected:
	private:
		Animator _animator;
		SpriteRenderer _playerRenderer;

		sf::Texture _animatorTexture;
		sf::IntRect _animatorRect;
		sf::Sprite _animator;
};

#endif /* !PLAYER_HPP_ */
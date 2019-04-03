/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include <SFML/Graphics/Texture.hpp>
    #include <SFML/Graphics/Rect.hpp>
    #include <SFML/Graphics/Sprite.hpp>

class Player {
	public:
		Player() = default;
		~Player() = default;

	protected:
	private:
		sf::Texture _playerTexture;
		sf::IntRect _playerRect;
		sf::Sprite _player;

};

#endif /* !PLAYER_HPP_ */
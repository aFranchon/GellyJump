/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** SpriteRenderer
*/

#ifndef SPRITERENDERER_HPP_
    #define SPRITERENDERER_HPP_

    #include <SFML/Graphics.hpp>
    #include <SFML/Graphics/Sprite.hpp>

class SpriteRenderer {
	public:
		SpriteRenderer() = default;
		~SpriteRenderer() = default;

		void draw(sf::RenderWindow &window, sf::Sprite &sprite)
		{
			if (_isActive)
				window.draw(sprite);
		}

		//setters
		bool isActive() const {return _isActive;};

		//getters
		void setActive(bool isDisplay) {_isActive = isDisplay;};

	protected:
	private:
		bool _isActive = true;
};

#endif /* !SPRITERENDERER_HPP_ */
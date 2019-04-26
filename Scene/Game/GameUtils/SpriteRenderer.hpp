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
			if (_isDisplay)
				window.draw(sprite);
		}

		//setters
		bool isDisplay() const {return _isDisplay;};

		//getters
		void setDisplay(bool isDisplay) {_isDisplay = isDisplay;};

	protected:
	private:
		bool _isDisplay = true;
};

#endif /* !SPRITERENDERER_HPP_ */
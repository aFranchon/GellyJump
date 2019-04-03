/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** UI
*/

#ifndef UI_HPP_
    #define UI_HPP_
    
    #include <vector>
    #include <SFML/Graphics/RenderWindow.hpp>
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/Graphics/Texture.hpp>
    #include <SFML/Graphics/Text.hpp>
    #include <SFML/Graphics/Rect.hpp>
    #include <SFML/Window/Mouse.hpp>

class UI {
	public:
		~UI() = default;

		//will draw only if isActivated
		void draw(sf::RenderWindow &window) {};

		//getters
		bool isActivated() const {return _isActivated;};

		//setters
		void setActivated(bool activated) {_isActivated = activated;};

	protected:
		bool _isActivated = true;
	private:
};

#endif /* !UI_HPP_ */
/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_

    #include <memory>

    #include "UI.hpp"

class Button : public UI {
	public:
		Button() = default;
		Button(const int height = 100, const int width = 100, const std::string &texture = "Ressources/menu/boutton.png",
		const std::string &font = "Ressources/fonts/manaspc.ttf");
		~Button() = default;

		void draw(sf::RenderWindow &window);
		void init(const int height, const int width, const std::string &texture, const std::string &font);

		void onClick(sf::Vector2i);
		void onRelease(sf::Vector2i);
		void onMove(sf::Vector2i) {};

		//setters
		void setPosition(sf::Vector2f &position);
		void setTexture(sf::Texture &texture);
		void setText(std::string &text);
		void setRect(sf::IntRect &rect);

		//getters
		sf::Vector2f getPosition() const;
		sf::Texture getTexture() const;
		sf::Text getText() const;
		sf::IntRect getRect() const;

	protected:
	private:
};

#endif /* !BUTTON_HPP_ */

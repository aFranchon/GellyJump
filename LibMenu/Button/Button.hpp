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
		Button(const int height = 100, const int width = 100, const std::string &texture = "Ressources/menu/boutton.png",
		const std::string &font = "Ressources/fonts/manaspc.ttf");
		~Button() = default;

		void init(const int height = 100, const int width = 100, const std::string &texture = "Ressources/menu/boutton.png",
		const std::string &font = "Ressources/fonts/manaspc.ttf");

		void onClick(sf::Vector2i mouse);
		void onMove(sf::Vector2i mouse);
		int onRelease(sf::Vector2i mouse);
		void draw(sf::RenderWindow &window);

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

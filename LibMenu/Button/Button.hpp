/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_

    #include <memory>

    #include "../UI.hpp"

class Button : public UI {
	public:
		typedef void(*function_type)();
		Button() = default;
		~Button() = default;

		void init(int height, int width, std::string &texture);

		void onClick(sf::Vector2i);
		void onRelease(sf::Vector2i);

		void draw(sf::RenderWindow &window);

		//setters
		void setPosition(sf::Vector2f &position);
		void setTexture(sf::Texture &texture);
		void setText(std::string text);
		void setRect(sf::IntRect &rect);
		void setHide(Button &button);
		void setHide(std::vector<std::shared_ptr<Button>> &buttons);
		void setShow(Button &button);
		void setShow(std::vector<std::shared_ptr<Button>> &buttons);
		void setAction(function_type &action);
		void setAction(std::vector<function_type> &actions);

		//getters
		sf::Vector2f getPosition() const;
		sf::Texture getTexture() const;
		sf::Text getText() const;
		sf::IntRect getRect() const;

	protected:
	private:
		//actions to be called when released
		std::vector<function_type> _action;

		//Buttons to hide
		std::vector<std::shared_ptr<UI>> _toHide;

		//Buttons to show
		std::vector<std::shared_ptr<UI>> _toShow;
		
		//SFML button
		sf::Texture _texture;
		sf::IntRect _rect;
		sf::Sprite _sprite;
		sf::Text _text;
};

#endif /* !BUTTON_HPP_ */

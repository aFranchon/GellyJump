/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Slider
*/

#ifndef SLIDER_HPP_
    #define SLIDER_HPP_

    #include "UI.hpp"

class Slider : public UI {
	public:
		Slider() = delete;
		Slider(	int heightSlider = 30, int widthSlider = 300, const std::string &textureSlider = "Ressources/menu/boutton.png", 
			int heightButton = 30, int widthButton = 30, const std::string &textureButton = "Ressources/menu/bouttonSlider.png",
			const std::string &font = "Ressources/fonts/manaspc.ttf", const int value = 100);
		~Slider();

		//will draw only if isActivated
		void init(	int heightSlider, int widthSlider, const std::string &textureSlider, 
				int heightButton, int widthButton, const std::string &textureButton,
				const std::string &font, const int value);

		void onClick(sf::Vector2i);
		void onRelease(sf::Vector2i);
		void onMove(sf::Vector2i);
		void draw(sf::RenderWindow &window);
		
		//methods to set UI elements to hide/show
		void setHide(std::shared_ptr<UI> &button);
		void setHide(std::vector<std::shared_ptr<UI>> &buttons);
		void setShow(std::shared_ptr<UI> &button);
		void setShow(std::vector<std::shared_ptr<UI>> &buttons);

		//methods to add actions to an UI element
		void setAction(function_type &action) {_action.push_back(action);};
		void setAction(std::vector<function_type> &actions);


		//setters
		void setActivated(bool activated);
		void setPosition(sf::Vector2f &position);
		void setTexture(sf::Texture &texture);
		void setText(std::string &text);
		void setRect(sf::IntRect &rect);

		//getters
		bool isActivated() const;
		sf::Vector2f getPosition() const;
		sf::Texture getTexture() const;
		sf::Text getText() const;
		sf::IntRect getRect() const;

	protected:
	private:
		bool _isActivated = true;

		//actions to be called when released
		std::vector<function_type> _action;

		//Buttons to hide
		std::vector<std::shared_ptr<UI>> _toHide;

		//Buttons to show
		std::vector<std::shared_ptr<UI>> _toShow;

		//value for the slider
		int _value;

		//SFML
		sf::Texture _textureSlider;
		sf::IntRect _rectSlider;
		sf::Sprite _spriteSlider;

		sf::Texture _textureButton;
		sf::IntRect _rectButton;
		sf::Sprite _spriteButton;
		
		sf::Text _text;
		sf::Font _font;
};

#endif /* !SLIDER_HPP_ */
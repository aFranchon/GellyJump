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
		Slider(	int heightSlider = 30, int widthSlider = 300, const std::string &textureSlider = "Ressources/menu/slider.png", 
			int heightButton = 30, int widthButton = 30, const std::string &textureButton = "Ressources/menu/buttonSlider.png",
			const std::string &font = "Ressources/fonts/manaspc.ttf", const int value = 100);
		~Slider() = default;

		//will draw only if isActivated
		void init(	int heightSlider, int widthSlider, const std::string &textureSlider, 
					int heightButton, int widthButton, const std::string &textureButton,
					const std::string &font, const int value);

		void onClick(sf::Vector2i mouse);
		int onRelease(sf::Vector2i mouse);
		void onMove(sf::Vector2i mouse);
		void draw(sf::RenderWindow &window);

		//setters
		void setPosition(sf::Vector2f &position);
		void setText(const std::string &text);
		void setValue(int value);
		void setMaxMinValues(int min, int max);

		//getters
		sf::Vector2f getPosition() const;
		int getValue() const;
	private:
		//value for the slider
		int _minValue = 0;
		int _maxValue = 100;

		bool _isClicked = false;
};

#endif /* !SLIDER_HPP_ */
/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** UI
*/

#ifndef UI_HPP_
    #define UI_HPP_
    
    #include <SFML/Graphics.hpp>
    #include <memory>

class UI {
	public:
		typedef void(*function_type)();

		virtual void draw(sf::RenderWindow &window) = 0;
		virtual void onClick(sf::Vector2i) = 0;
		virtual void onRelease(sf::Vector2i) = 0;
		virtual void onMove(sf::Vector2i) = 0;

		virtual void setActivated(bool activated) {_isActivated = activated;};
		virtual bool isActivated() const {return _isActivated;};

		void setHide(std::shared_ptr<UI> button) {_toHide.push_back(button);}

		void setHide(std::vector<std::shared_ptr<UI>> buttons) 
		{
			for (auto &elem : buttons)
				_toHide.push_back(elem);
		}

		void setShow(std::shared_ptr<UI> button) {_toShow.push_back(button);}

		void setShow(std::vector<std::shared_ptr<UI>> buttons) 
		{
			for (auto &elem : buttons)
				_toShow.push_back(elem);
		}

		protected:
			//Buttons to hide
			std::vector<std::shared_ptr<UI>> _toHide;

			//Buttons to show
			std::vector<std::shared_ptr<UI>> _toShow;

			bool _isActivated = false;

			//Vectors of SFML elements
			std::vector<sf::Texture> _textures;
			std::vector<sf::IntRect> _rects;
			std::vector<sf::Sprite> _sprites;
			std::vector<sf::Font> _fonts;
			std::vector<sf::Text> _texts;
};

#endif /* !UI_HPP_ */
/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

    #include <memory>

    #include "Scene.hpp"
    #include "Button.hpp"
    #include "Slider.hpp"

class Menu : public IScene{
	public:
		Menu() = default;
		~Menu() = default;

		void init(sf::RenderWindow &window);
		void handleEvent(const sf::Event event);
		void refresh();

		static void quit();

	protected:
	private:
		void initMainMenu();
		void initOptionMenu();
		void linkButtons();

		sf::RenderWindow * _window;
		std::vector<std::shared_ptr<UI>> _buttons;
		std::vector<std::shared_ptr<UI>> _mainButtons;
		std::vector<std::shared_ptr<UI>> _optionButtons;
};

#endif /* !MENU_HPP_ */
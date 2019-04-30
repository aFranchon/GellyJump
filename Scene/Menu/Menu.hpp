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
		typedef void function_type(int);
		Menu() = default;
		~Menu() = default;

		void init(sf::RenderWindow &window, bool &isPlay);
		void handleEvent(const sf::Event event);
		void refresh();
		void setChangeScene(const std::function<void()> &func);

		void activate();
		void desactivate();

	private:
		void initMainMenu();
		void initOptionMenu();
		void linkButtons();

		sf::RenderWindow * _window;
		bool *isPlay;
		std::function<void()> _changeScene;
		std::vector<std::shared_ptr<UI>> _buttons;
		std::vector<std::shared_ptr<UI>> _mainButtons;
		std::vector<std::shared_ptr<UI>> _optionButtons;
};

#endif /* !MENU_HPP_ */
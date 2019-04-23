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

		static int quit();
		static int fps();
		static int volume();
		static int play();

		void doNothing(int nothing);
		void setFPS(int fps);
		void setVolume(int volume);
		void playGame(int i);

	private:
		void initMainMenu();
		void initOptionMenu();
		void linkButtons();

		sf::RenderWindow * _window;
		bool *isPlay;
		std::vector<std::shared_ptr<UI>> _buttons;
		std::vector<std::shared_ptr<UI>> _mainButtons;
		std::vector<std::shared_ptr<UI>> _optionButtons;
		std::vector<std::function<void(Menu&, int)>> _tab;
};

#endif /* !MENU_HPP_ */
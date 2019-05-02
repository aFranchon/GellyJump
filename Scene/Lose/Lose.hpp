/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Lose
*/

#ifndef LOSE_HPP_
    #define LOSE_HPP_
    
    #include "Button.hpp"

    #include "Scene.hpp"

class Lose : public IScene {
	public:
		Lose() = default;
		~Lose() = default;

		void init(sf::RenderWindow &window, const std::string &font = "Ressources/fonts/manaspc.ttf");
		void handleEvent(const sf::Event &event);
		void refresh();

		void setText(const std::string &print);
		void setMenuFunc(const std::function<void(int value)> &func);
		void setResetFunc(const std::function<void(int value)> &func);

		void activate();
		void desactivate();

	protected:
	private:
		sf::RenderWindow *_window;

		sf::Text _text;
		sf::Font _font;

		Button _menu;
		Button _restart;
	protected:
	private:
};

#endif /* !LOSE_HPP_ */

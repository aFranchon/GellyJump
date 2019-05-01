/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Win
*/

#ifndef WIN_HPP_
    #define WIN_HPP_

    #include "Button.hpp"

    #include "Scene.hpp"

class Win : public IScene {
	public:
		Win() = default;
		~Win() = default;

		void init(sf::RenderWindow &window, const std::string &font = "Ressources/fonts/manaspc.ttf");
		void handleEvent(const sf::Event &event);
		void refresh();

		void setText(const std::string &print);

		void activate();
		void desactivate();

	protected:
	private:
		sf::RenderWindow *_window;

		sf::Text _text;
		sf::Font _font;

		Button _menu;
		Button _nextLevel;
};

#endif /* !WIN_HPP_ */
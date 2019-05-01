/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Scene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

    #include <SFML/Window/Event.hpp>

    #include "UI.hpp"

class IScene {
	public:
		~IScene() {};

		virtual void refresh() = 0;
		virtual void handleEvent(const sf::Event &event) = 0;

		virtual void activate() = 0;
		virtual void desactivate() = 0;

		virtual void setText(const std::string &print) {};

		const bool isActive() const {return _isActive;};

	protected:
		bool _isActive = true;
	private:
};

#endif /* !SCENE_HPP_ */
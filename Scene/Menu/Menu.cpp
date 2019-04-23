/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Menu
*/

#include <iostream>

#include "Menu.hpp"

void Menu::initMainMenu()
{
	std::string string = "Ressources/menu/boutton.png";
	std::string stringFont = "Ressources/fonts/manaspc.ttf";

	Button *playButton = new Button(100, 100, string, stringFont);

	playButton->setActivated(true);
	sf::Vector2f pos = {static_cast<float>(_window->getSize().x / 2), 200};
	playButton->setPosition(pos);
	std::string text = "Play";
	playButton->setText(text);

	_mainButtons.push_back(std::shared_ptr<UI>(playButton));

	Button *optionButton = new Button(100, 100, string, stringFont);

	optionButton->setActivated(true);
	pos = {static_cast<float>(_window->getSize().x / 2), 400};
	optionButton->setPosition(pos);
	text = "Options";
	optionButton->setText(text);

	_mainButtons.push_back(std::shared_ptr<UI>(optionButton));

	Button *quitButton = new Button(100, 100, string, stringFont);

	quitButton->setActivated(true);
	pos = {static_cast<float>(_window->getSize().x / 2), 600};
	quitButton->setPosition(pos);
	text = "Quit";
	quitButton->setText(text);
	void(*function_type)(int) = &quit;
	quitButton->setAction(function_type);

	_mainButtons.push_back(std::shared_ptr<UI>(quitButton));
}

void Menu::initOptionMenu()
{

	Slider *sliderSound = new Slider();

	sliderSound->setActivated(false);
	sf::Vector2f pos = {static_cast<float>(_window->getSize().x / 2), 200};
	sliderSound->setPosition(pos);
	sliderSound->setText("Sound");
	sliderSound->setMaxMinValues(0, 100);

	_optionButtons.push_back(std::shared_ptr<UI>(sliderSound));

	Slider *sliderFps = new Slider();

	sliderFps->setActivated(false);
	pos = {static_cast<float>(_window->getSize().x / 2), 400};
	sliderFps->setPosition(pos);
	sliderFps->setText("FPS");
	sliderFps->setMaxMinValues(0, 100);

	_optionButtons.push_back(std::shared_ptr<UI>(sliderFps));

	Button *backButton = new Button();

	backButton->setActivated(false);
	pos = {static_cast<float>(_window->getSize().x / 2), 600};
	backButton->setPosition(pos);
	std::string text = "Back";
	backButton->setText(text);
	
	_optionButtons.push_back(std::shared_ptr<UI>(backButton));
}

void Menu::quit(int i)
{
	exit(0);
}

void Menu::linkButtons()
{
	_mainButtons[1]->setHide(_mainButtons);
	_mainButtons[1]->setShow(_optionButtons);

	for (auto &elem : _mainButtons)
		_buttons.push_back(elem);

	_optionButtons[2]->setHide(_optionButtons);
	_optionButtons[2]->setShow(_mainButtons);

	for (auto &elem : _optionButtons)
		_buttons.push_back(elem);
}

void Menu::init(sf::RenderWindow &window)
{
	_window = &window;

	initMainMenu();
	initOptionMenu();
	
	linkButtons();
} 

void Menu::handleEvent(const sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for (auto &elem : _buttons)
			if (elem->isActivated())
				elem->onClick(sf::Mouse::getPosition(*_window));
	}

	if (event.type == sf::Event::MouseButtonReleased) {
		for (auto &elem : _buttons) {
			if (elem->isActivated())
				elem->onRelease(sf::Mouse::getPosition(*_window));
		}
	}

	if (event.type == sf::Event::MouseMoved) {
		for (auto &elem : _buttons) {
			if (elem->isActivated())
				elem->onMove(sf::Mouse::getPosition(*_window));
		}
	}
}

void Menu::refresh()
{
	for (auto &elem : _buttons)
		elem->draw(*_window);
}
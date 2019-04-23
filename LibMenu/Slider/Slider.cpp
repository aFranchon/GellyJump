/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Slider
*/

#include <iostream>

#include "Slider.hpp"

Slider::Slider(	int heightSlider, int widthSlider, const std::string &textureSlider, 
		int heightButton, int widthButton, const std::string &textureButton,
		const std::string &font, const int value)
{
	init(	heightSlider, widthSlider, textureSlider,
		heightButton, widthButton, textureButton,
		font, value);
}

void Slider::init(	int heightSlider, int widthSlider, const std::string &textureSlider, 
			int heightButton, int widthButton, const std::string &textureButton,
			const std::string &font, const int value)
{

	sf::IntRect rectSlider;
	rectSlider.top = 0;
	rectSlider.left = 0;
	rectSlider.height = heightSlider;
	rectSlider.width = widthSlider;
	_rects.push_back(rectSlider);

	sf::Sprite spriteSlider;
	spriteSlider.setOrigin(_rects[0].width / 2, _rects[0].height / 2);
	_sprites.push_back(spriteSlider);

	sf::Texture textureSliderTmp;
	if (!textureSliderTmp.loadFromFile(textureSlider, _rects[0]))
		throw;
	_textures.push_back(textureSliderTmp);

	sf::IntRect rectButton;
	rectButton.top = 0;
	rectButton.left = 0;
	rectButton.height = heightButton;
	rectButton.width = widthButton;
	_rects.push_back(rectButton);

	sf::Sprite spriteButton;
	spriteButton.setOrigin(_rects[1].width / 2, _rects[1].height / 2);
	_sprites.push_back(spriteButton);

	sf::Texture textureButtonTmp;
	if (!textureButtonTmp.loadFromFile(textureButton, _rects[1]))
		throw;
	_textures.push_back(textureButtonTmp);

	sf::Font fontSlider;
	if (!fontSlider.loadFromFile(font))
		throw;
	_fonts.push_back(fontSlider);

	sf::Text text;
	_texts.push_back(text);

	_value = value;
}

void Slider::onClick(sf::Vector2i mouse)
{
	if (_sprites[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse))) {
		_sprites[1].setPosition(mouse.x, _sprites[0].getPosition().y);
		_rects[1].top += _rects[1].height;
		_isClicked = true;
	} else {
		_rects[1].top = 0;
		_rects[1].left = 0;
		_isClicked = false;
	}
}

int Slider::onRelease(sf::Vector2i mouse)
{
	if (_sprites[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse)) && (_rects[0].top != 0 || _rects[0].left != 0)) {
		_rects[0].top += _rects[0].height;
		for (auto &elem : _toHide)
			elem->setActivated(false);
		for (auto &elem : _toShow)
			elem->setActivated(true);
		for (auto &elem : _action)
			return elem();
	} else {
		_rects[0].top = 0;
		_rects[0].left = 0;
	}
	_isClicked = false;
	return 0;
}

void Slider::onMove(sf::Vector2i mouse)
{
	if (!_isClicked)
		return;
	if (mouse.x <= _sprites[0].getPosition().x - _rects[0].width / 2) {
		_value = _minValue;
		_sprites[1].setPosition(_sprites[0].getPosition().x - _rects[0].width / 2, _sprites[0].getPosition().y);
	} else if (mouse.x >= _sprites[0].getPosition().x + _rects[0].width / 2) {
		_value = _maxValue;
		_sprites[1].setPosition(_sprites[0].getPosition().x + _rects[0].width / 2, _sprites[0].getPosition().y);
	} else {
		_sprites[1].setPosition(mouse.x, _sprites[0].getPosition().y);
		_value = (mouse.x - _sprites[0].getPosition().x) / _rects[0].width * _maxValue;
	}
}

void Slider::draw(sf::RenderWindow &window)
{
	if (_sprites[0].getTexture() == nullptr) {
		_sprites[0].setTexture(_textures[0]);
		_sprites[0].setPosition(_sprites[0].getPosition());
	}

	if (_sprites[1].getTexture() == nullptr) {
		_sprites[1].setTexture(_textures[1]);
		_sprites[1].setPosition(_sprites[1].getPosition());
	}

	if (_texts[0].getFont() == nullptr) {
		_texts[0].setFont(_fonts[0]);
		sf::FloatRect textRect = _texts[0].getLocalBounds();
		_texts[0].setOrigin(	_texts[0].getLocalBounds().left + _texts[0].getLocalBounds().width/2.0f,
		 			_texts[0].getLocalBounds().top  + _texts[0].getLocalBounds().height/2.0f);
		_texts[0].setPosition(_texts[0].getPosition());
	}

	if (_isActivated) {
		for (auto &elem : _sprites)
			window.draw(elem);
		window.draw(_texts[0]);
	}
}

void Slider::setPosition(sf::Vector2f &position) 
{
	_sprites[0].setPosition(position);

	_sprites[1].setPosition(_sprites[0].getPosition().x - _rects[0].width / 2 + ((_value / _maxValue) * _rects[0].width), _sprites[0].getPosition().y);

	sf::FloatRect textRect = _texts[0].getLocalBounds();
	_texts[0].setOrigin(	_texts[0].getLocalBounds().left + _texts[0].getLocalBounds().width/2.0f,
				_texts[0].getLocalBounds().top  + _texts[0].getLocalBounds().height/2.0f);
	_texts[0].setPosition(_sprites[0].getPosition().x, _sprites[0].getPosition().y - _rects[0].height);
}

void Slider::setText(const std::string &text) {_texts[0].setString(text);}
void Slider::setValue(int value) {_value = value;}

void Slider::setMaxMinValues(int min, int max)
{
	_maxValue = max;
	_minValue = min;
}

sf::Vector2f Slider::getPosition() const {return _sprites[0].getPosition();}
int Slider::getValue() const {return _value;}
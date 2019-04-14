/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Slider
*/

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
	_rectButton.top = 0;
	_rectButton.left = 0;
	_rectButton.height = heightButton;
	_rectButton.width = widthButton;

	_spriteButton.setOrigin(_rectButton.width / 2, _rectButton.height / 2);

	if (!_texture.loadFromFile(textureButton, _rectButton))
		throw;

	_rectSlider.top = 0;
	_rectSlider.left = 0;
	_rectSlider.height = heightSlider;
	_rectSlider.width = widthSlider;

	_spriteButton.setOrigin(_rectSlider.width / 2, _rectSlider.height / 2);

	if (!_texture.loadFromFile(textureButton, _rectSlider))
		throw;

	if (!_font.loadFromFile(font))
		throw;

	_value = value;
}

void Slider::onClick(sf::Vector2i mouse)
{
}

void Slider::onRelease(sf::Vector2i mouse)
{
}

void Slider::onMove(sf::Vector2i mouse)
{
}

void Slider::draw(sf::RenderWindow &window)
{
	if (_sprite.getTexture() == nullptr) {
		_sprite.setTexture(_texture);
		_sprite.setPosition(_sprite.getPosition());
	}

	if (_text.getFont() == nullptr) {
		_text.setFont(_font);
		sf::FloatRect textRect = _text.getLocalBounds();
		_text.setOrigin(_text.getLocalBounds().left + _text.getLocalBounds().width/2.0f, _text.getLocalBounds().top  + _text.getLocalBounds().height/2.0f);
		_text.setPosition(_sprite.getPosition());
	}

	if (_isActivated) {
		window.draw(_sprite);
		window.draw(_text);
	}
}

void Slider::setPosition(sf::Vector2f &position) 
{
	_spriteSlider.setPosition(position);

	_spriteButton.setPosition(_spriteSlider.getPosition().x + , _spriteSlider.getPosition().y);

	sf::FloatRect textRect = _text.getLocalBounds();
	_text.setOrigin(_text.getLocalBounds().left + _text.getLocalBounds().width/2.0f, _text.getLocalBounds().top  + _text.getLocalBounds().height/2.0f);
	_text.setPosition(_spriteButton.getPosition().x, _spriteButton.getPosition().y - _rectSlider.height);
}

void Slider::setTexture(sf::Texture &texture) {_texture = texture;}
void Slider::setText(std::string &text) {_text.setString(text);}
void Slider::setRect(sf::IntRect &rect) {_rect = rect;}
void Slider::setActivated(bool isActivated) {_isActivated = isActivated;}

sf::Vector2f Slider::getPosition() const {return _sprite.getPosition();}
sf::Texture Slider::getTexture() const {return _texture;}
sf::Text Slider::getText() const {return _text;}
sf::IntRect Slider::getRect() const {return _rect;}
bool Slider::isActivated() const {return _isActivated;}

void Slider::setHide(std::shared_ptr<UI> &Slider) {_toHide.push_back(Slider);}

void Slider::setHide(std::vector<std::shared_ptr<UI>> &Sliders) 
{
	for (auto &elem : Sliders)
		_toHide.push_back(elem);
}

void Slider::setShow(std::shared_ptr<UI> &Slider) {_toShow.push_back(Slider);}

void Slider::setShow(std::vector<std::shared_ptr<UI>> &Sliders) 
{
	for (auto &elem : Sliders)
		_toShow.push_back(elem);
}

void Slider::setAction(std::vector<function_type> &actions)
{
	for (auto &elem : actions)
		_action.push_back(elem);
}
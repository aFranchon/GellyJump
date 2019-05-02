/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** StaticMurderer
*/

#ifndef STATICMURDERER_HPP_
    #define STATICMURDERER_HPP_

     #include "IEnvironement.hpp"

class StaticMurderer : public IEnvironement {
	public:
		StaticMurderer() = default;
		~StaticMurderer() = default;

		void init(const int &width, const int &height, const std::string &texture)
		{
			_envRect.top = 0;
			_envRect.left = 0;
			_envRect.height = height;
			_envRect.width = width;

			if (!_envTexture.loadFromFile(texture))
				throw;
			_envSprite.setTexture(_envTexture);
			_envSprite.setTextureRect(_envRect);
			_tag = "Murderer";
		};

		//overload of the Environement's onCollision method
		void onCollsion(Player &player)
		{
			player.setDead(true);
		};

	protected:
	private:
};

#endif /* !STATICMURDERER_HPP_ */
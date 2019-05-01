/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** EndLevelTrigger
*/

#ifndef ENDLEVELTRIGGER_HPP_
    #define ENDLEVELTRIGGER_HPP_

	#include <iostream>
    #include "IEnvironement.hpp"

class EndLevelTrigger : public IEnvironement {
	public:
		EndLevelTrigger() = default;
		~EndLevelTrigger() = default;

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
			_tag = "End";
		};

		//overload of the Environement's onCollision method
        void onCollsion(Player &player)
        {
            player.setWin();
        };

	protected:
	private:
};

#endif /* !ENDLEVELTRIGGER_HPP_ */
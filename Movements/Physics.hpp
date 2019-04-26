/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Physics
*/

#ifndef PHYSICS_HPP_
    #define PHYSICS_HPP_

class Physics {
	public:
		Physics() = default;
		~Physics() = default;

		//getters
		bool isFalling() const {return _isFalling;};

		//setters
		void setFalling(const bool &isFalling) {_isFalling = isFalling;};
		void setWeight(const float &weight) {_weight = weight;};

		void fall(float &position)
		{
			if (!_isFalling)
				return;
			
			position += _weight;
		}

	protected:
	private:
		bool _isFalling = false;

		float _weight;
};

#endif /* !PHYSICS_HPP_ */
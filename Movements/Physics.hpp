/*
** EPITECH PROJECT, 2019
** GellyJump
** File description:
** Physics
*/

#ifndef PHYSICS_HPP_
    #define PHYSICS_HPP_

    #include <iostream>

class Physics {
	public:
		Physics() = default;
		~Physics() = default;

		//getters
		bool isFalling() const {return _isFalling;};

		//setters
		void setFalling(const bool &isFalling) {_isFalling = isFalling;};
		void setFallingIncrease(const float &fallingIncrease) {_fallingIncrease = fallingIncrease;};
		void setWeight(const float &weight) {_weight = weight;};

		void fall(float &position)
		{
			//faire en sorte que ça augmente (à l'inverse de move/jump)
			if (!_isFalling)
				return;
			
			if (_increase < 1)
				_increase += 0.01;

			position += _weight * (_fallingIncrease * _increase);
		}

		float getNext(const float &position) {
			float ret = position;
			if (!_isFalling)
				return ret;
			
			if (_increase < 1)
				_increase += 0.01;

			ret += _weight * (_fallingIncrease * _increase);
			return ret;
		};

		void hit() {
			if (_increase > 0.1)
				_increase -= 0.4;
			else
				_increase = 0;
			_increase *= -1;
		}

	protected:
	private:
		bool _isFalling = false;

		float _weight;
		float _fallingIncrease;
		float _increase = 0;
};

#endif /* !PHYSICS_HPP_ */
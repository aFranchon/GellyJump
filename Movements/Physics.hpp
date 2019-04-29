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
			//faire en sorte que ça augmente (à l'inverse de move/jump)
			if (!_isFalling)
				return;
			
			position += _weight;
		}

		float getNext(const float &position) {
			float ret = position;
			if (!_isFalling)
				return ret;
			
			ret += _weight;
			return ret;
		};

		void hit() {
			//reset augmentation
		}

	protected:
	private:
		bool _isFalling = false;

		float _weight;
};

#endif /* !PHYSICS_HPP_ */
/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Move
*/

#ifndef MOVE_HPP_
    #define MOVE_HPP_

class Move {
	public:
		Move() = default;
		Move(const float &slowDown) : _slowDown(slowDown) {};
		~Move() = default;

		//Getters
		float getSpeed() const {return _speed;};
		const bool &getJustSet() const {return _justSet;}

		//Setters
		void setSpeed(const float speed) 
		{
			_speed += speed;
			_justSet = true;
		};
		void setSlowDown(const float slowDown) {_slowDown = slowDown;};

		//move method
		//Move GameActor depending on his _direction and _speed
		void move(float &position) 
		{
			if (_speed <= 0.001 && _speed >= -0.001)
				return;
			
			position += _speed;
			_speed /= _slowDown;
			_justSet = false;
		};

		float getNext(const float &position) {
			float ret = position;
			if (_speed <= 0.001 && _speed >= -0.001)
				return ret;
			
			ret += _speed;
			return ret;
		};

		void hit() {
			_speed *= -1;
			_speed /= _slowDown * 3;
		}

	protected:
	private:
		float _speed = 0;
		float _slowDown = 1;
		bool _justSet = false;

};

#endif /* !MOVE_HPP_ */
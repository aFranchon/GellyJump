/*
** EPITECH PROJECT, 2019
** Projet1
** File description:
** Jump
*/

#ifndef JUMP_HPP_
    #define JUMP_HPP_

    #include <iostream>

class Jump {
	public:
		Jump() = default;
		Jump(const float &slowDown) : _slowDown(slowDown) {};
		~Jump() = default;

		//Getters
		float getSpeed() const {return _speed;};

		//Setters
		void setSpeed(const float speed) {_speed += speed;};
		void setSlowDown(const float slowDown) {_slowDown = slowDown;};

		//move method
		//Move GameActor depending on his _direction and _speed
		void jump(float &position) 
		{
			if (_speed <= 0.001 && _speed >= -0.001)
				return;
			
			position += _speed;
			_speed /= _slowDown;
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
			if (_speed > 0)
				_speed /= _slowDown * 800;
			else
				_speed /= _slowDown * 3;
		}

	protected:
	private:
		float _speed = 0;
		float _slowDown = 1;
};

#endif /* !JUMP_HPP_ */
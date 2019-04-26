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

		//Init method
		void init(const float &slowDown);

		//Getters
		float getSpeed() const {return _speed;};

		//Setters
		void setSpeed(const float speed) {_speed += speed;};
		void setSlowDown(const float slowDown) {_slowDown = slowDown;};

		//move method
		//Move GameActor depending on his _direction and _speed
		void move(float &position) 
		{
			if (_speed <= 0.001 && _speed >= -0.001)
				return;
			
			position += _speed;
			_speed /= _slowDown;
		};


	protected:
	private:
		float _speed = 0;
		std::size_t _slowDown = 1;

};

#endif /* !MOVE_HPP_ */
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
		~Move() = default;

		//Init method
		//Params = infos about GameActor
		void init();

		//Getters
		int getDirection() const {return _direction;};
		float getSpeed() const {return _speed;};

		//Setters
		void setDirection(const int direction) {_direction = direction;};
		void setSpeed(const float speed) {_speed = speed;};

		//move method
		//Move GameActor depending on his _direction and _speed
		void move(int &position) {position += _direction * _speed;};


	protected:
	private:
		int _direction = 0;
		float _speed = 0;

};

#endif /* !MOVE_HPP_ */
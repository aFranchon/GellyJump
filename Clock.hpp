/*
 EPITECH PROJECT, 2019
 Untitled (Workspace)
 File description:
 Clock
*/

#ifndef CLOCKH
    #define CLOCKH

	#include <chrono>

template<typename Clock_t = std::chrono::steady_clock>
class Clock
{
	public:
	using TimePoint = decltype(Clock_t::now());

	Clock() : m_start(Clock_t::now()) {}
	~Clock() = default;

	void reset() {m_start = Clock_t::now();}
	float getSeconds() const {return std::chrono::duration_cast<std::chrono::duration<float>>(Clock_t::now() - m_start).count();}

	private:
		TimePoint m_start;
};

#endif /* !SHOOT_HPP_ */

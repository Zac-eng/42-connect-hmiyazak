#include "Zombie.hpp"

int	main(void) {
	Zombie	*jiangshi_leader = zombieHorde(100, "JIANGSHI");
	Zombie	*jiangshi_alive = jiangshi_leader;
	Zombie	*next_jiangshi;

	while (jiangshi_alive != NULL) {
		next_jiangshi = jiangshi_alive->get_next();
		delete jiangshi_alive;
		jiangshi_alive = next_jiangshi;
	}
	return (0);
}

#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie *new_zombie = newZombie(name);
	new_zombie->announce();
	delete new_zombie;
}

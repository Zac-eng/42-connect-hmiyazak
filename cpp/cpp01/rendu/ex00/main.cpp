#include "Zombie.hpp"

int	main() {
	Zombie *tom = newZombie("TOM");
	tom->announce();
	randomChump("JELLY");
	delete tom;
	return (0);
}
__attribute((destructor)) static void destructor() {
	system("leaks -q zombie");
}

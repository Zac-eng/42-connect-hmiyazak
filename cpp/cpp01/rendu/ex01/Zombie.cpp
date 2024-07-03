#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
	this->next = NULL;
}

Zombie::~Zombie() {
	std::cout << this->name << std::endl;
}

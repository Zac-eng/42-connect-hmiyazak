#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
    std::cout << "ScavTrap: default constructor called" << std::endl;
    this->setHP(100);
    this->setEP(50);
    this->setDamage(20);
}

ScavTrap::ScavTrap(ScavTrap& object) {
    std::cout << "ScavTrap: copy constructor called" << std::endl;
    this->setName(object.getName());
    this->setHP(100);
    this->setEP(50);
    this->setDamage(20);
}

ScavTrap::ScavTrap(std::string init_name) {
    std::cout << "ScavTrap: constructor with name string is called" << std::endl;
    this->setName(init_name);
    this->setHP(100);
    this->setEP(50);
    this->setDamage(20);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& object) {
    std::cout << "ScavTrap: copy assignment operator called" << std::endl;
    this->setName(object.getName());
    this->setHP(100);
    this->setEP(50);
    this->setDamage(20);
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << std::endl;
    this->consumeEP();
}

void ScavTrap::takeDamage(unsigned int amount) {
    std::cout << "ScavTrap " << this->getName() << " was attacked, took " << amount << " points of damage!" << std::endl;
    this->setHP(this->getHP() - amount);
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->getName() << " was repaired, be cured for " << amount << " points!" << std::endl;
    this->setHP(this->getHP() + amount);
    this->consumeEP();
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " is now GUARD GATE MODE." << std::endl;
}

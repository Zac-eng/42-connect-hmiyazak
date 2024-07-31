#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
    std::cout << "FragTrap: default constructor called" << std::endl;
    this->setHP(100);
    this->setEP(100);
    this->setDamage(30);
}

FragTrap::FragTrap(FragTrap& object) {
    std::cout << "FragTrap: copy constructor called" << std::endl;
    this->setName(object.getName());
    this->setHP(100);
    this->setEP(100);
    this->setDamage(30);
}

FragTrap::FragTrap(std::string init_name) {
    std::cout << "FragTrap: constructor with name string is called" << std::endl;
    this->setName(init_name);
    this->setHP(100);
    this->setEP(100);
    this->setDamage(30);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: destructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& object) {
    std::cout << "FragTrap: copy assignment operator called" << std::endl;
    this->setName(object.getName());
    this->setHP(100);
    this->setEP(100);
    this->setDamage(30);
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << std::endl;
    this->consumeEP();
}

void FragTrap::takeDamage(unsigned int amount) {
    std::cout << "FragTrap " << this->getName() << " was attacked, took " << amount << " points of damage!" << std::endl;
    this->setHP(this->getHP() - amount);
}

void FragTrap::beRepaired(unsigned int amount) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->getName() << " was repaired, be cured for " << amount << " points!" << std::endl;
    this->setHP(this->getHP() + amount);
    this->consumeEP();
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getName() << ", high fives guys!!." << std::endl;
}

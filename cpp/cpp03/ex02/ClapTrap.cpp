#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
    std::cout << "ClapTrap: default constructor called" << std::endl;
    this->name = "DEFAULT";
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& object) {
    std::cout << "ClapTrap: copy constructor called" << std::endl;
    this->name = object.getName();
    this->hit_point = object.getHP();
    this->energy_point = object.getEP();
    this->attack_damage = object.getDamage();
}

ClapTrap::ClapTrap(std::string init_name) {
    std::cout << "ClapTrap: constructor with name string is called" << std::endl;
    this->name = init_name;
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap: destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& object) {
    std::cout << "ClapTrap: copy assignment operator called" << std::endl;
    this->name = object.getName();
    this->hit_point = object.getHP();
    this->energy_point = object.getEP();
    this->attack_damage = object.getDamage();
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->consumeEP();
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " was attacked, took " << amount << " points of damage!" << std::endl;
    this->hit_point -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " was repaired, be cured for " << amount << " points!" << std::endl;
    this->hit_point += amount;
    this->consumeEP();
}

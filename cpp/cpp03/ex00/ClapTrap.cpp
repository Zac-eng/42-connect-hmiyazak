#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
    std::cout << "default constructor called" << std::endl;
    this->name = "DEFAULT";
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap& object) {
    std::cout << "copy constructor called" << std::endl;
    this->name = object.name;
    this->hit_point = object.hit_point;
    this->energy_point = object.energy_point;
    this->attack_damage = object.attack_damage;
}

ClapTrap::ClapTrap(std::string init_name) {
    std::cout << "constructor with name string is called" << std::endl;
    this->name = init_name;
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
}

ClapTrap::~ClapTrap() {
    std::cout << "destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& object) {
    std::cout << "copy assignment operator called" << std::endl;
    this->name = object.name;
    this->hit_point = object.hit_point;
    this->energy_point = object.energy_point;
    this->attack_damage = object.attack_damage;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->hit_point <= 0 || this->energy_point <= 0) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_point -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " was attacked, took " << amount << " points of damage!" << std::endl;
    this->hit_point -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hit_point <= 0 || this->energy_point <= 0) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " was repaired, be cured for " << amount << " points!" << std::endl;
    this->hit_point += amount;
    this->energy_point -= 1;
}

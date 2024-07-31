#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): hit_point(FragTrap::getHP()), energy_point(ScavTrap::getEP()), attack_damage(FragTrap::getDamage()) {
    std::cout << "DiamondTrap: default constructor called" << std::endl;
    this->name = "DEFAULT";
    ClapTrap::setName("DEFAULT_clap_name");
}

DiamondTrap::DiamondTrap(DiamondTrap& object): hit_point(FragTrap::getHP()), energy_point(ScavTrap::getEP()), attack_damage(FragTrap::getDamage()) {
    this->setName(object.getName());
    this->setHP(100);
    this->setEP(100);
    this->setDamage(30);
    std::cout << "DiamondTrap: copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string init_name): hit_point(FragTrap::getHP()), energy_point(ScavTrap::getEP()), attack_damage(FragTrap::getDamage()) {
    this->name = init_name;
    ClapTrap::setName(init_name + std::string("_clap_name"));
    std::cout << "DiamondTrap: constructor with name string is called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap: destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& object) {
    std::cout << "FragTrap: copy assignment operator called" << std::endl;
    this->setName(object.getName());
    this->setHP(100);
    this->setEP(100);
    this->setDamage(30);
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "DiamondTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << std::endl;
    this->consumeEP();
}

void DiamondTrap::takeDamage(unsigned int amount) {
    std::cout << "DiamondTrap " << this->getName() << " was attacked, took " << amount << " points of damage!" << std::endl;
    this->setHP(this->getHP() - amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "DiamondTrap " << this->getName() << " was repaired, be cured for " << amount << " points!" << std::endl;
    this->setHP(this->getHP() + amount);
    this->consumeEP();
}

void DiamondTrap::whoAmI() {

}

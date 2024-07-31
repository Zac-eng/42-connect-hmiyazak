#include "Animal.hpp"

Animal::Animal(void) {
    std::cout << "Animal: default constructor called" << std::endl;
    this->type = "UMA";
}

Animal::Animal(Animal& object) {
    std::cout << "Animal: copy constructor called" << std::endl;
    this->type = object.getType();
}

Animal::~Animal() {
    std::cout << "Animal: destructor called" << std::endl;
}

Animal& Animal::operator = (const Animal& object) {
    std::cout << "Animal: copy assignment operator called" << std::endl;
    this->type = object.getType();
    return *this;
}

void Animal::makeSound(void) const {
    std::cout << "Mmm..." << std::endl;
}

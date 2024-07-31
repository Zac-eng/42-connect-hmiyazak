#include "Dog.hpp"

Dog::Dog(void) {
    std::cout << "Dog: default constructor called" << std::endl;
    this->setType("Dog");
}

Dog::Dog(Dog& object) {
    std::cout << "Dog: copy constructor called" << std::endl;
    this->setType(object.getType());
}

Dog::~Dog() {
    std::cout << "Dog: destructor called" << std::endl;
}

Dog& Dog::operator = (Dog& object) {
    std::cout << "Dog: copy assignment operator called" << std::endl;
    this->setType(object.getType());
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Woof!!!" << std::endl;
}

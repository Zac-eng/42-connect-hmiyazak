#include "Cat.hpp"

Cat::Cat(void) {
    std::cout << "Cat: default constructor called" << std::endl;
    this->setType("Cat");
}

Cat::Cat(Cat& object) {
    std::cout << "Cat: copy constructor called" << std::endl;
    this->setType(object.getType());
}

Cat::~Cat() {
    std::cout << "Cat: destructor called" << std::endl;
}

Cat& Cat::operator = (Cat& object) {
    std::cout << "Cat: copy assignment operator called" << std::endl;
    this->setType(object.getType());
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Meow!!!" << std::endl;
}

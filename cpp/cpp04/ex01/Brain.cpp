#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain: default constructor called" << std::endl;
    for (int i = 0; i < IDEA_CAP; i++) {
        ideas[i] = "";
    }
}

Brain::Brain(Brain& object) {
    const std::string *idea_array = object.getIdea();

    std::cout << "Brain: copy constructor called" << std::endl;
    for (int i = 0; i < IDEA_CAP; i++) {
        ideas[i] = idea_array[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain: destructor called" << std::endl;
}

Brain& Brain::operator = (const Brain& object) {
    const std::string *idea_array = object.getIdea();

    for (int i = 0; i < IDEA_CAP; i++) {
        ideas[i] = idea_array[i];
    }
    return *this;
}

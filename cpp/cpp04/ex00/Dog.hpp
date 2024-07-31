#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class Dog: public Animal {

public:
    Dog(void);
    Dog(Dog& object);
    ~Dog();
    Dog& operator = (Dog& object);
    void makeSound(void) const;

};

#endif
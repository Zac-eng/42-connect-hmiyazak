#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {

private:
    Brain* brain;

public:
    Cat(void);
    Cat(Cat& object);
    ~Cat();
    Cat& operator = (Cat& object);
    void makeSound(void) const;

};

#endif

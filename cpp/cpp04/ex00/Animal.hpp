#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {

private:
    std::string type;

public:
    Animal(void);
    Animal(Animal& object);
    ~Animal();
    Animal& operator = (const Animal& object);
    inline std::string getType(void) const;
    inline void setType(const std::string& new_type);
    virtual void makeSound(void) const;

};

inline std::string Animal::getType(void) const {
    return this->type;
}

inline void Animal::setType(const std::string& new_type) {
    this->type = new_type;
}

#endif

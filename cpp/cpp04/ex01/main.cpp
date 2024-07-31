#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    const int ARRAY_LEN = 10;
    Animal* animal_array[ARRAY_LEN];
    for (int i = 0; i < ARRAY_LEN; i++) {
        if (i % 2 == 0) {
            animal_array[i] = new Cat();
        } else {
            animal_array[i] = new Dog();
        }
    }
    for (int i = 0; i < ARRAY_LEN; i++) {
        delete animal_array[i];
    }
    return 0;
}

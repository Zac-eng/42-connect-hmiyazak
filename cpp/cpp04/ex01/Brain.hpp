#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

const int IDEA_CAP = 100;

class Brain {

private:
    std::string ideas[IDEA_CAP];

public:
    Brain(void);
    Brain(Brain& object);
    ~Brain();
    Brain& operator = (const Brain& object);
    inline const std::string* getIdea(void) const;

};

inline const std::string* Brain::getIdea(void) const {
    return &this->ideas[0];
}

#endif

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {

public:
    FragTrap(void);
    FragTrap(FragTrap& object);
    FragTrap(std::string init_name);
    ~FragTrap();
    FragTrap& operator = (const FragTrap& object);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);   
    void beRepaired(unsigned int amount);
    void highFivesGuys(void);
};

#endif

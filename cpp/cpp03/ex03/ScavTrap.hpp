#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {

public:
    ScavTrap(void);
    ScavTrap(ScavTrap& object);
    ScavTrap(std::string init_name);
    ~ScavTrap();
    ScavTrap& operator = (const ScavTrap& object);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);   
    void beRepaired(unsigned int amount);
    void guardGate();
};

#endif

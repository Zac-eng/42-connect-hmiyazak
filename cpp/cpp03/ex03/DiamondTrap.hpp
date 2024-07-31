#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

private:
    std::string name;
    int hit_point;
    int energy_point;
    int attack_damage;

public:
    DiamondTrap(void);
    DiamondTrap(DiamondTrap& object);
    DiamondTrap(std::string init_name);
    ~DiamondTrap();
    DiamondTrap& operator = (const DiamondTrap& object);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);   
    void beRepaired(unsigned int amount);
    void whoAmI();

};


#endif

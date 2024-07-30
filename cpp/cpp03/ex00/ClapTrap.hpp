#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {

private:
    std::string name;
    int hit_point;
    int energy_point;
    int attack_damage;

public:
    ClapTrap(void);
    ClapTrap(ClapTrap& object);
    ClapTrap(std::string init_name);
    ~ClapTrap();
    ClapTrap& operator = (const ClapTrap& object);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif

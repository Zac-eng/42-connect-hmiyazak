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
    ClapTrap(const ClapTrap& object);
    ClapTrap(std::string init_name);
    ~ClapTrap();
    ClapTrap& operator = (const ClapTrap& object);
    inline std::string getName(void) const;
    inline int getHP(void) const;
    inline int getEP(void) const;
    inline int getDamage(void) const;
    inline void setName(std::string name);
    inline void setHP(int hp);
    inline void setEP(int ep);
    inline void setDamage(int damage);
    inline bool canMove(void) const;
    inline void consumeEP(void);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

inline std::string ClapTrap::getName(void) const {
    return this->name;
}

inline int ClapTrap::getHP(void) const {
    return this->hit_point;
}

inline int ClapTrap::getEP(void) const {
    return this->energy_point;
}

inline int ClapTrap::getDamage(void) const {
    return this->attack_damage;
}

inline void ClapTrap::setName(std::string new_name) {
    this->name = new_name;
}

inline void ClapTrap::setHP(int new_hp) {
    this->hit_point = new_hp;
}

inline void ClapTrap::setEP(int new_ep) {
    this->energy_point = new_ep;
}

inline void ClapTrap::setDamage(int new_damage) {
    this->attack_damage = new_damage;
}

inline bool ClapTrap::canMove(void) const {
    return (this->hit_point > 0 && this->energy_point > 0);
}

inline void ClapTrap::consumeEP(void) {
    this->energy_point -= 1;
}

#endif

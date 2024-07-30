#include "ClapTrap.hpp"

int main() {
    ClapTrap clap_trap("1st");
    ClapTrap clap_trap_dup(clap_trap);
    ClapTrap clap_trap_another;
    clap_trap_another = clap_trap;

    clap_trap.attack("dup");
    clap_trap_dup.takeDamage(5);
    clap_trap_dup.beRepaired(5);
    clap_trap_dup.attack("1st");
    clap_trap.takeDamage(2);
    clap_trap.beRepaired(4);
    clap_trap_another.attack("1st");
    clap_trap.takeDamage(10);
    for (int i = 0; i < 10; i++) {
        clap_trap_another.takeDamage(4);
        clap_trap_another.beRepaired(2);
    }
    return 0;
}

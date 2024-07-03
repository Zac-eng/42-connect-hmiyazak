#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

	public:
		HumanB(std::string name);
		void	attack(void) {
			std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
		}
		void	setWeapon(Weapon* new_weapon) {
			_weapon = new_weapon;
		}

	private:
		std::string	_name;
		Weapon		*_weapon;

};

#endif

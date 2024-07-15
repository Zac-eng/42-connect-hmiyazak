#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void) {
			std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
		}

	private:
		std::string	_name;
		Weapon		&_weapon;

};

#endif

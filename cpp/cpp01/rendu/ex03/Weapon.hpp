#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {

	public:
		Weapon(std::string type);
		const std::string&	getType(void) {
			return (_type);
		}
		void			setType(std::string new_type) {
			_type = new_type;
		}

	private:
		std::string	_type;

};

#endif

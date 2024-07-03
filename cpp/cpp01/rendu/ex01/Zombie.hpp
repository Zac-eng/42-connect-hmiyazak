#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {

	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const {
			std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
		};
		Zombie*	get_next(void) const {
			return (next);
		}
		void	set_next(Zombie *next_zombie) {
			next = next_zombie;
		}

	private:
		std::string	name;
		Zombie		*next;
};

Zombie* zombieHorde(int N, std::string name);

#endif
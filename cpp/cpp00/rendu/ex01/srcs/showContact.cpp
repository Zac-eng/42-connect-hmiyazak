#include "Contact.hpp"

static void display_in_ten(std::string str);

void	Contact::showContact(void) {
	display_in_ten(this->_firstName);
	std::cout << '|';
	display_in_ten(this->_lastName);
	std::cout << '|';
	display_in_ten(this->_nickname);
	std::cout << '|';
	display_in_ten(this->_phoneNumber);
	std::cout << '|';
	display_in_ten(this->_darkestSecret);
	std::cout << std::endl;
}

void	Contact::showAbstruct(int index) {
	display_in_ten(std::to_string(index));
	std::cout << '|';
	display_in_ten(this->_firstName);
	std::cout << '|';
	display_in_ten(this->_lastName);
	std::cout << '|';
	display_in_ten(this->_nickname);
	std::cout << std::endl;
}

static void display_in_ten(std::string str)
{
	int	length;

	length = str.length();
	if (length < 10) {
		for (int i = 0; length + i < 10; i++) {
			std::cout << '.';
		}
	}
	if (length <= 10) {
		std::cout << str;
	}
	else {
		for (int i = 0; i < 9; i++) {
			std::cout << str[i];
		}
		std::cout << '.';
	}
}

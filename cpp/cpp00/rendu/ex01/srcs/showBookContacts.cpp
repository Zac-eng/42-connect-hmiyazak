#include "PhoneBook.hpp"

void  PhoneBook::showBookContacts(void) {
	std::string const	header = "     index|first name| last name|  nickname";
	std::string			index_str;
	int					index;

	std::cout << header << std::endl;
	for (int i = 0; i < contact_count_; i++) {
		this->contacts_[i]->showAbstruct(i);
	}
	std::cout << "Which contact do you want to see? Tell me its index" << std::endl;
	std::cin >> index_str;
	try {
		index = std::stoi(index_str);
	} catch (const std::invalid_argument& _) {
		std::cout << "Please input valid index" << std::endl;
		return ;
	}
	if (index > this->contact_count_) {
		std::cout << "Please input valid index" << std::endl;
		return ;
	}
	this->contacts_[index]->showContact();
}

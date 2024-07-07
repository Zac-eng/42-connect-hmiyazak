#include "PhoneBook.hpp"
#include "Contact.hpp"

void  PhoneBook::addContact(std::string fname, std::string lname, std::string nname, \
            				std::string phone_number, std::string secret) {
	Contact	*newConact = new Contact(fname, lname, nname, phone_number, secret);
	if (this->contact_count_ == 8) {
		delete this->contacts_[next_index_];
	}
	this->contacts_[next_index_] = newConact;
	this->next_index_ = (this->next_index_ + 1) % 8;
	if (this->contact_count_ < 8) {
		this->contact_count_ += 1;
	}
}

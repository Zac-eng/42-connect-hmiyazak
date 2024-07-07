#include "PhoneBook.hpp"

int main(void)
{
  std::string command;
  PhoneBook   phone_book = PhoneBook();
  std::string contact_info[5];

  while (true)
  {
    std::cout << "Please input the command, ADD, SEARCH, or EXIT" << std::endl;
    std::cin >> command;
    if (command == "ADD")
    {
      std::cout << "Please input the contact information, first name, last name, nickname, phone number, and darkest sectret" << std::endl;
      std::cout << "First name: " << std::endl;
      std::cin >> contact_info[0];
      std::cout << "Last name: " << std::endl;
      std::cin >> contact_info[1];
      std::cout << "Nickname: " << std::endl;
      std::cin >> contact_info[2];
      std::cout << "Phone number: " << std::endl;
      std::cin >> contact_info[3];
      std::cout << "Darkest secret: " << std::endl;
      std::cin >> contact_info[4];
      phone_book.addContact(contact_info[0], contact_info[1], contact_info[2], contact_info[3], contact_info[4]);
    }
    else if (command == "SEARCH")
      phone_book.showBookContacts();
    else if (command == "EXIT")
        break ;
    else
        continue ;
  }
  exit(0);
}

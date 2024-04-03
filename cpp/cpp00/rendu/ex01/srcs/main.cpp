#include "book.h"

int main()
{
  std::string command;
  PhoneBook   phone_book;

  phone_book.next_index_ = 0;
  phone_book.contact_count_ = 3;
  phone_book.contacts_[0].first_name_="Haruto";
  phone_book.contacts_[0].last_name_="Miyazaki";
  phone_book.contacts_[0].nick_name_="Miyazaki";
  phone_book.contacts_[1].first_name_="Haruto";
  phone_book.contacts_[1].last_name_="Miyazaki";
  phone_book.contacts_[1].nick_name_="Miyazaki";
  phone_book.contacts_[2].first_name_="Haruto";
  phone_book.contacts_[2].last_name_="Miyazaki";
  phone_book.contacts_[2].nick_name_="Miyazaki";
  while (true)
  {
    std::cin >> command;
    if (command == "ADD")
      add_func(&phone_book);
    else if (command == "SEARCH")
      search_func(&phone_book);
    else if (command == "EXIT")
        break ;
    else
        continue ;
  }
  exit(0);
}

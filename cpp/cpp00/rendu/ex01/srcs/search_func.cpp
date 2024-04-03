#include "book.h"

static void display_index(int index);
static void display_contact(Contact *contact);
static void display_in_ten(std::string str);

void  search_func(PhoneBook *phone_book)
{
  std::string const header = "index     |first name|last name |nickname  ";

  std::cout << header << std::endl;
  for (int i = 0; i < phone_book->contact_count_; i++)
  {
    display_index(i);
    display_contact(&phone_book->contacts_[i]);
  }
}

static void display_index(int index)
{
  display_in_ten(std::to_string(index));
  std::cout << "|";
}

static void display_contact(Contact *contact)
{
  display_in_ten(contact->first_name_);
  std::cout << "|";
  display_in_ten(contact->last_name_);
  std::cout << "|";
  display_in_ten(contact->nick_name_);
  std::cout << std::endl;
}

static void display_in_ten(std::string str)
{
  int index = 0;
  while (str[index] && index < 9)
  {
    std::cout << str[index];
    index++;
  }
  if (str[index])
  {
    if (str[index + 1])
      std::cout << '.';
    else
      std::cout << str[index];
  } else {
    while (index < 10)
    {
      std::cout << ' ';
      index++;
    }
  }
}

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

class PhoneBook {
  public:
    PhoneBook(void);
    ~PhoneBook(void);
    void  addContact(std::string fname, std::string lname, std::string nname, \
                    std::string phone_number, std::string secret);
    void  showBookContacts(void);

  private:
    Contact     *contacts_[8];
    int         next_index_;
    int         contact_count_;
};

#endif

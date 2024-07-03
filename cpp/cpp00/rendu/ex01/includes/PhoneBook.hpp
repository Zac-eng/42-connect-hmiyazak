#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

class PhoneBook {
  public:
    Contact     contacts_[8];
    int         next_index_;
    int         contact_count_;
};

#endif

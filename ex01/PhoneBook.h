#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.h"
#include <cctype>
#include <cstdlib>

class PhoneBook {
	private:
		Contact cs[8];
		size_t cursor;

	public:
		PhoneBook();
		void add();
		void search();
};

#endif

#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		Contact();
		bool setFirstName(const std::string&);
		bool setLastName(const std::string&);
		bool setNickname(const std::string&);
		bool setPhoneNumber(const std::string&);
		bool setDarkestSecret(const std::string&);
		void print_simple();
		std::ostream& operator>>(std::ostream&);
		bool is_empty();
};

#endif

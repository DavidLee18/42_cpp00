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
		bool setMember(std::string&, const std::string&);
		void print_simple_field(const std::string&) const;

	public:
		Contact();
		bool setFirstName(const std::string&);
		bool setLastName(const std::string&);
		bool setNickname(const std::string&);
		bool setPhoneNumber(const std::string&);
		bool setDarkestSecret(const std::string&);
		void print_simple() const;
		std::ostream& operator>>(std::ostream&) const;
		bool is_empty() const;
};

#endif

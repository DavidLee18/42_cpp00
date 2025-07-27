#include "Contact.h"

Contact::Contact(): first_name(), last_name(), nickname(), phone_number(), darkest_secret() {}

bool Contact::setMember(std::string& field, const std::string& to) {
	if (field.empty()) {
        return false;
    }
    field = to;
    return true;
}

bool Contact::setFirstName(const std::string& firstName) { return setMember(first_name, firstName); }

bool Contact::setLastName(const std::string& lastName) { return setMember(last_name, lastName); }

bool Contact::setNickname(const std::string& nickname) { return setMember(this->nickname, nickname); }

bool Contact::setPhoneNumber(const std::string& phoneNumber) { return setMember(phone_number, phoneNumber); }

bool Contact::setDarkestSecret(const std::string& darkestSecret) { return setMember(darkest_secret, darkestSecret); }

void Contact::print_simple_field(const std::string& s) const {
	std::cout << std::setw(10) << std::right;
    if (s.length() > 10)
        std::cout << s.substr(0, 9) + ".";
    else
        std::cout << s;
}

void Contact::print_simple() const {
	print_simple_field(first_name);
    std::cout << "|";
    print_simple_field(last_name);
    std::cout << "|";
    print_simple_field(nickname);
    std::cout << std::endl;
}

std::ostream& Contact::operator>>(std::ostream &o) const {
    o << "First Name: " << first_name << std::endl;
    o << "Last Name: " << last_name << std::endl;
    o << "Nickname: " << nickname << std::endl;
    o << "Phone Number: " << phone_number << std::endl;
    o << "Darkest Secret: " << darkest_secret << std::endl;
    return o;
}

bool Contact::is_empty() const {
	return (
		first_name.empty()
		|| last_name.empty()
		|| nickname.empty()
		|| phone_number.empty()
		|| darkest_secret.empty()
	);
}

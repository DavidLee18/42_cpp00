#include "Contact.h"

Contact::Contact() {
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    darkest_secret = "";
}

bool Contact::setFirstName(const std::string& firstName) {
    if (firstName.empty()) {
        return false;
    }
    first_name = firstName;
    return true;
}

bool Contact::setLastName(const std::string& lastName) {
    if (lastName.empty()) {
        return false;
    }
    last_name = lastName;
    return true;
}

bool Contact::setNickname(const std::string& nickname) {
    if (nickname.empty()) {
        return false;
    }
    this->nickname = nickname;
    return true;
}

bool Contact::setPhoneNumber(const std::string& phoneNumber) {
    if (phoneNumber.empty()) {
        return false;
    }
    phone_number = phoneNumber;
    return true;
}

bool Contact::setDarkestSecret(const std::string& darkestSecret) {
    if (darkestSecret.empty()) {
        return false;
    }
    darkest_secret = darkestSecret;
    return true;
}

void Contact::print_simple() {
    std::cout << std::setw(10) << std::right;
    if (first_name.length() > 10) {
        std::cout << first_name.substr(0, 9) + ".";
    } else {
        std::cout << first_name;
    }
    std::cout << "|";

    std::cout << std::setw(10) << std::right;
    if (last_name.length() > 10) {
        std::cout << last_name.substr(0, 9) + ".";
    } else {
        std::cout << last_name;
    }
    std::cout << "|";

    std::cout << std::setw(10) << std::right;
    if (nickname.length() > 10) {
        std::cout << nickname.substr(0, 9) + ".";
    } else {
        std::cout << nickname;
    }
    std::cout << std::endl;
}

std::ostream& Contact::operator>>(std::ostream &o) {
    o << "First Name: " << first_name << std::endl;
    o << "Last Name: " << last_name << std::endl;
    o << "Nickname: " << nickname << std::endl;
    o << "Phone Number: " << phone_number << std::endl;
    o << "Darkest Secret: " << darkest_secret << std::endl;
    return o;
}

bool Contact::is_empty() {
	return (
		first_name.empty()
		|| last_name.empty()
		|| nickname.empty()
		|| phone_number.empty()
		|| darkest_secret.empty()
	);
}

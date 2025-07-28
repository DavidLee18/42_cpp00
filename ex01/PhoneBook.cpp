#include "PhoneBook.h"
#define SAFE_GETLINE(label, func) { \
	while (true) { \
		std::cout << label; \
		std::getline(std::cin, input); \
		if (cs[cursor].func(input)) { \
			break; \
		} \
		if (std::cin.eof()) { \
			std::exit(1); \
		} \
		std::cerr << "invalid input. try again" << std::endl; \
	} \
	input.clear(); \
}

PhoneBook::PhoneBook(): cursor(0) {}

void PhoneBook::add() {
	std::string input;
	SAFE_GETLINE("First Name: ", setFirstName)
	SAFE_GETLINE("Last Name: ", setLastName)
	SAFE_GETLINE("Nickname: ", setNickname)
	SAFE_GETLINE("Phone Number: ", setPhoneNumber)
	SAFE_GETLINE("Darkest Secret: ", setDarkestSecret)
	cursor = (cursor + 1) % 8;
}

void PhoneBook::search() {
	for (size_t i = 0; i < 8 && !cs[i].is_empty(); i++)
	{
		std::cout << std::setw(10) << std::right;
		std::cout << i << "|";
		cs[i].print_simple();
	}
	std::string input;
	while (true) {
		std::cout << "enter the index of which you want to inspect: ";
		size_t i;
		if((std::cin >> i) && i < 8 && !cs[i].is_empty())
		{
			cs[i] >> std::cout;
			break;
		}
		if (std::cin.eof())
			std::exit(1);
		std::cerr << "invalid input. try again" << std::endl;
	}
}

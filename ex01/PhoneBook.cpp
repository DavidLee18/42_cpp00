#include "PhoneBook.h"

PhoneBook::PhoneBook() {
	cursor = 0;
}

void PhoneBook::add() {
	std::string input;

	while (true) {
		std::cout << "First Name: ";
		std::getline(std::cin, input);
		if (cs[cursor].setFirstName(input))
			break;
		std::cerr << "invalid input. try again" << std::endl;
	}
	input.clear();
	while (true) {
		std::cout << "Last Name: ";
		std::getline(std::cin, input);
		if (cs[cursor].setLastName(input))
			break;
		std::cerr << "invalid input. try again" << std::endl;
	}
	input.clear();
	while (true) {
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		if (cs[cursor].setNickname(input))
			break;
		std::cerr << "invalid input. try again" << std::endl;
	}
	input.clear();
	while (true) {
		std::cout << "Phone Number: ";
		std::getline(std::cin, input);
		if (cs[cursor].setPhoneNumber(input))
			break;
		std::cerr << "invalid input. try again" << std::endl;
	}
	input.clear();
	while (true) {
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, input);
		if (cs[cursor].setDarkestSecret(input))
			break;
		std::cerr << "invalid input. try again" << std::endl;
	}
	input.clear();
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
		if(std::cin >> i && i < 8)
		{
			cs[i] >> std::cout;
			break;
		}
		std::cerr << "invalid input. try again" << std::endl;
	}
}

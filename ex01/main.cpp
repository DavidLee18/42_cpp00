#include "PhoneBook.h"

int main() {
	PhoneBook p;
	std::string input;
	while (true) {
		std::cout << "PhoneBook > ";
		std::getline(std::cin, input);
		if (input == "ADD")
			p.add();
		else if (input == "SEARCH")
			p.search();
		else if (input == "EXIT")
			break;
		else
			std::cerr << "PhoneBook: unknown command, try again" << std::endl;
	}
	return 0;
}

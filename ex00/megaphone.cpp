#include <cctype>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string word;
		for (int i = 1; i < argc; i++) {
			word = argv[i];
			for (size_t j = 0; j < word.length(); j++) {
				if (std::islower((unsigned char)word[j]))
					std::cout << (char)std::toupper((unsigned char)word[j]);
				else
					std::cout << word[j];
			}
		}
		std::cout << std::endl;
	}
	return 0;
}

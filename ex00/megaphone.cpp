#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++) {
				if(std::isalpha(static_cast<unsigned char>(argv[i][j]))
				&& std::islower(static_cast<unsigned char>(argv[i][j])))
					std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
				else
					std::cout << argv[i][j];
			}
		}
		std::cout << std::endl;
	}
	return 0;
}

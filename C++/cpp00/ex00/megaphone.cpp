#include <iostream>


std::string to_upper(std::string input)
{
	int i;

	i = 0;
	while (i < input.length())
	{
		if (input[i] <= 122 && input[i] >= 97)
			input[i] = input[i] - 32;
		i++;
	}
	return (input);
}

int main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < argc)
		{
			std::cout << to_upper(argv[i]);
			i++;
	 	}
		std::cout << std::endl;
	}
	return (0);
}
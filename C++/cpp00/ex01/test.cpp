#include <iostream>

int main(int argc, char **argv)
{
	int i;
    std::string holder[2];
    std::cout << "the awsome phone terimnal" << std::endl;
    std::getline( std::cin, holder[0]);
     std::cout << "the awsome phone terimnal" << std::endl;
    std::getline( std::cin, holder[1]);
     std::cout << holder[0] + "and " + holder[1] << std::endl;
	
	return (0);
}
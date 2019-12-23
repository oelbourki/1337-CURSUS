#include <iostream>
#include <sstream>
#include <iomanip>
#include<string.h>
#include "contact.hpp"
// int main(int argc, char **argv)
// {
// 	std::string table[8];
// 	std::string phrase = "firstname,secondename,phone";
// 	std::stringstream ss(phrase);
// 	std::string holder;
// 	char del = ',';
// 	while (getline(ss, holder, del))
// 		std::cout << holder << std::endl;
// 	return (0);
// }
contact::contact(std::string *table)
{
	this->table[0] = table[0];
	this->table[1] = table[1];
	this->table[2] = table[2];
	this->table[3] = table[3];
	this->table[4] = table[4];
	this->table[5] = table[5];
	this->table[6] = table[6];
	this->table[7] = table[7];
	this->table[8] = table[8];
	this->table[9] = table[9];
	this->table[10] = table[10];
}
void contact::set(std::string *table)
{
	this->table[0] = table[0];
	this->table[1] = table[1];
	this->table[2] = table[2];
	this->table[3] = table[3];
	this->table[4] = table[4];
	this->table[5] = table[5];
	this->table[6] = table[6];
	this->table[7] = table[7];
	this->table[8] = table[8];
	this->table[9] = table[9];
	this->table[10] = table[10];
}
contact::contact()
{
	int i;

	i = 0;
	this->table[i++] = "";
	this->table[i++] = "";
	this->table[i++] = "";
	this->table[i++] = "";
	this->table[i++] = "";
	this->table[i++] = "";
	this->table[i++] = "";
	this->table[i++] = "";
	this->table[i++] = "";
	this->table[i++] = "";
	this->table[i++] = "";
}
void contact::print_table()
{
	int i = 0;
	while (i < 11)
	{
		std::cout << this->table[i] << std::endl;
		i++;
	}
}

void	get_contact(contact *user)
{
	int i;
	i = 0;
	std::string table[11];
	std::cout << "enter first name" << std::endl;
	std::getline( std::cin, table[i++]);
	std::cout << "enter last name" << std::endl;
	std::getline( std::cin, table[i++]);
	std::cout << "enter nickname" << std::endl;
	std::getline( std::cin, table[i++]);
	std::cout << "enter login" << std::endl;
	std::getline( std::cin, table[i++]);
	std::cout << "enter postal address" << std::endl;
	std::getline( std::cin, table[i++]);
	std::cout << "enter email address" << std::endl;
	std::getline( std::cin, table[i++]);
	std::cout << "enter phone number" << std::endl;
	std::getline( std::cin, table[i++]);
	std::cout << "enter birthday date" << std::endl;
	std::getline( std::cin, table[i++]);
	std::cout << "enter favorite meal" << std::endl;
	std::getline( std::cin, table[i++]);
	std::cout << "enter underwear color" << std::endl;
	std::getline( std::cin, table[i++]);
	std::cout << "enter darkest secret." << std::endl;
	std::getline( std::cin, table[i++]);
	user->set(table);
}

void contact::search(int j)
{
	std::string dot = ".";
	std::string space[3];
	space[0] = "0123456789|";
	space[1] = "0123456789|";
	space[2] = "0123456789|";
	std::cout << j ;
	std::cout << "         |" ;
	if (this->table[0].length() > 10)
		this->table[0].replace(9,this->table[0].length() - 1, dot);
	space[0].replace(0,this->table[0].length() - 1,this->table[0]);
	if (this->table[1].length() > 10)
		this->table[1].replace(9,this->table[1].length() - 1, dot);
	space[1].replace(0,this->table[1].length() - 1,this->table[1]);
	if (this->table[2].length() > 10)
		this->table[2].replace(9,this->table[2].length() - 1, dot);
	space[2].replace(0,this->table[2].length() - 1,this->table[2]);
	std::cout << space[0] + space[1] + space[2];
	
}
void	do_search(int i, contact *user)
{
	int j(0);

	while (j < i)
	{
		user[j].search(j);
		std::cout << "\n";
		j++;
	}
	
}
int main(int argc, char **argv)
{
	int state = 1;
	int i(0);
	int index(0);
	contact user[8];
	std::string command;
	std::cout << "the awsome phone terimnal" << std::endl;
	while (state)
	{
		std::cout << "prompt>>";
		std::cin >> command;
		std::cin.ignore();
		if (i > 8)
			std::cout << "only 8" << std::endl;
		else if (command == "ADD" && i < 8)
			get_contact(&user[i++]);
		else if (command == "SEARCH")
		{
			do_search(i, user);
			std::cin >> index;
			if (index >= 0 && index < 9)
				user[index].print_table();
			else
				std::cout << "index not available" << std::endl;
		}
		else if (command == "EXIT")
			state = 0;
	}
	return (0);
}
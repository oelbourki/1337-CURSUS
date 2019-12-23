#include "Peon.hpp"


Peon::Peon(std::string name)
{
    std::cout << "Some random victim called " + name + " just popped !" << std::endl;
    this->name = name;
    std::cout << "Zog zog." << std::endl;
}
Peon::Peon()
{

}
Peon::~Peon()
{
   std::cout << "Bleuark..." << std::endl;
   std::cout << "Victim " + this->name + " just died for no apparent reason !" << std::endl;
}

void Peon::getPolymorphed() const
{
   std::cout << this->name + " has been turned into a pink pony !" << std::endl; 
}
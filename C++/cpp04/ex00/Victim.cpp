#include "Victim.hpp"


Victim::Victim(std::string name)
{
    std::cout << "Some random victim called " + this->name + " just popped !" << std::endl;
    this->name = name;
}
Victim::Victim()
{

}
Victim::~Victim()
{
    std::cout << "Victim " + this->name + " just died for no apparent reason !" << std::endl;
}

void Victim::getPolymorphed() const
{
   std::cout << this->name + " has been turned into a cute little sheep !" << std::endl; 
}

std::string     Victim::get_name()
{
    return (this->name);
}

std::ostream& operator<< (std::ostream& out, Victim& _Victim)
{
    out <<  "I'm " << _Victim.get_name() << " and I like otters !\n";
    return (out);
}


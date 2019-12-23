#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name + ", " + this->title + ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->name + ", " + this->title + ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & wiz)
{
   *this = wiz;
}
Sorcerer & Sorcerer::operator=(const Sorcerer & wiz)
{
    this->name = name;
    this->title = title;
    return *this;
}

void Sorcerer::polymorph(Victim const & victim) const
{
    victim.getPolymorphed();
}

void Sorcerer::polymorph(Peon const & peon) const
{
    peon.getPolymorphed();
}
// ostream & Sorcerer::operator<<(ostream &out, const Sorcerer &c);
// {
//     std::cout << "I am " + this->name + ", TITLE, and I like ponies !" << std::endl;
// }


std::string Sorcerer::operator<<(const Sorcerer &c)
{
    std::string x =  "I am " + this->name + ", TITLE, and I like ponies !\n";
    return x;
}




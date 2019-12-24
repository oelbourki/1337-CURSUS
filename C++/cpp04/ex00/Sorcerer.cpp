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

std::string     Sorcerer::get_name()
{
    return (this->name);
}

std::string     Sorcerer::get_title()
{
    return (this->title);
}

std::ostream& operator<< (std::ostream& out, Sorcerer& _Sorcerer)
{
    out <<  "I am " + _Sorcerer.get_name() + ", " +  _Sorcerer.get_title() + ", and I like ponies !\n";
    return (out);
}




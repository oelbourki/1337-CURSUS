#include <iostream>
#include "Human.hpp"


Human::Human()
{
    //this->einstein = new Brain;
}

Human::~Human()
{
   // delete this->einstein;
}

std::string    Human::identify() const
{
    return this->einstein.identify();
}

const Brain& Human::getBrain() const
{
    return this->einstein;
}
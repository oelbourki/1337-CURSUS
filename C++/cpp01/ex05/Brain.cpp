#include "Brain.hpp"
#include <iostream>
#include <sstream>
Brain::Brain(int weight,int fats,int iq)
{
    this->fats = fats;
    this->iq = iq;
}
Brain::Brain()
{
    this->weight = 0;
    this->fats = 0;
    this->iq = 0;
}
 
Brain::~Brain()
{
}

std::string    Brain::identify() const
{
    std::stringstream hexStr;
    hexStr << std::hex << this;
    return hexStr.str();
}
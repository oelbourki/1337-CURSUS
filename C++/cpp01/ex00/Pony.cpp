#include "pony.hpp"

Pony::Pony(std::string color, std::string name, std::string clane, int height, int weight)
{
    this->color = color;
    this->name = name;
    this->clane = clane;
    this->height = height;
    this->weight = weight;
}

void    Pony::set(std::string color, std::string name, std::string clane, int height, int weight)
{
    this->color = color;
    this->name = name;
    this->clane = clane;
    this->height = height;
    this->weight = weight;
}

Pony::Pony(void)
{
    this->color = "";
    this->name = "";
    this->clane = "";
    this->height = 0;
    this->weight = 0;
}

void Pony::print_song()
{
    std::cout << "i am the little pony " + this->name + " i am " + this->color + " and my clane is " + this->clane;
    std::cout << " my height is ";
    std::cout << this->height;
    std::cout << " my weight is ";
    std::cout << this->weight;
    std::cout << " hopa hopa" << std::endl;
}
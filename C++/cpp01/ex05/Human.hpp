#include <iostream>
#include "Brain.hpp"

class Human
{
    private:
        //const Brain *einstein;
        const Brain einstein;
    public:
        Human();
        ~Human();
        std::string    identify() const;
        const Brain& getBrain() const;
};
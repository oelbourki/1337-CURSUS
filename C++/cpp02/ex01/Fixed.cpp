#include "Fixed.hpp"


void Fixed::operator=(Fixed const &a)
{
    std::cout << "Assignation operator called" << std::endl; 
    this->store = a.store;
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->store = 0;
}
Fixed::~Fixed()
{
   std::cout << "Default destructor called" << std::endl; 
}
Fixed::Fixed(Fixed const &f)
{
    std::cout << "Copy constructor called" << std::endl; 
    this->store = f.store;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl; 
    return (this->store);
}
void Fixed::setRawBits( int const raw)
{
    std::cout << "setRawBits member function called" << std::endl; 
    this->store = raw;
}


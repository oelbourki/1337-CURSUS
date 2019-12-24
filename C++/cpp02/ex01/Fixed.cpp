#include "Fixed.hpp"

#include <cmath>


void Fixed::operator=(Fixed const &a)
{
    std::cout << "Assignation operator called" << std::endl;

    this->store = a.store;
    this->flag = a.get_flag();
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
    this->flag = f.get_flag();
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

Fixed::Fixed(int const &val)
{
    this->store = val;
    this->flag = 1;
}
Fixed::Fixed(float const &val)
{
    int go = 1 << this->frac; 
    this->store = roundf(val * go);
    this->flag = 0;
}

float Fixed::toFloat( void ) const
{
    int go = 1 << this->frac;
    if (this->flag == 1)
        return static_cast<float>(this->store);
    else
        return (static_cast<float>(this->store) / go);
}
int Fixed::toInt( void ) const
{
    if (this->flag == 1)
        return static_cast<int>(this->store);
    else
        return static_cast<int>(this->store / (1 << this->frac));
}

std::ostream& operator<< (std::ostream& out, const Fixed& _Fixed)
{
     if (_Fixed.get_flag() == 0)
        out << _Fixed.toFloat();
     else 
         out << _Fixed.toInt();
    return (out);
}

bool Fixed::get_flag() const
{
    return (this->flag);
}
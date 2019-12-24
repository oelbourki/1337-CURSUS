#include "Fixed.hpp"

#include <cmath>
#include <limits.h>
bool cmpf(float A, float B, float epsilon = 0.005f)
{ 
    return (fabs(A - B) < epsilon);
}
Fixed Fixed::operator=(Fixed const &a)
{
  //  std::cout << "Assignation operator called" << std::endl;

    this->store = a.store;
    this->flag = a.get_flag();
    return *this;
}

Fixed::Fixed()
{
  //  std::cout << "Default constructor called" << std::endl;
    this->store = 0;
}
Fixed::~Fixed()
{
 //  std::cout << "Default destructor called" << std::endl; 
}
Fixed::Fixed(Fixed const &f)
{
  //  std::cout << "Copy constructor called" << std::endl; 
    this->store = f.store;
    this->flag = f.get_flag();
}

int Fixed::getRawBits( void ) const
{
  //  std::cout << "getRawBits member function called" << std::endl; 
    return (this->store);
}
void Fixed::setRawBits( int const raw)
{
   // std::cout << "setRawBits member function called" << std::endl; 
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

int Fixed::get_store() const
{
    return (this->store);
}

Fixed Fixed::operator*(Fixed const &a)
{
    float b;
    float b1;
    if (this->flag == 1 && a.get_flag() == 1)
    {
        this->store = this->toInt() * a.toInt();
    }
    if (this->flag == 0)
        b1 = this->toFloat();
    else 
        b1 = this->toInt();
    if (a.get_flag() == 0)
        b = a.toFloat();
    else 
        b = a.toInt();
    Fixed f(b1 * b);
    if (this->flag == 0 || a.get_flag() == 0)
        f.flag = 0;
    else 
        f.flag = 1;
    return (f);
}



Fixed Fixed::operator/(Fixed const &a)
{
    float b;
    float b1;
    if (this->flag == 1 && a.get_flag() == 1)
    {
        this->store = this->toInt() / a.toInt();
    }
    if (this->flag == 0)
        b1 = this->toFloat();
    else 
        b1 = this->toInt();
    if (a.get_flag() == 0)
        b = a.toFloat();
    else 
        b = a.toInt();
    Fixed f(b1 / b);
    if (this->flag == 0 || a.get_flag() == 0)
        f.flag = 0;
    else 
        f.flag = 1;
    return (f);
}



Fixed Fixed::operator+(Fixed const &a)
{
    float b;
    float b1;
    if (this->flag == 1 && a.get_flag() == 1)
    {
        this->store = this->toInt() + a.toInt();
    }
    if (this->flag == 0)
        b1 = this->toFloat();
    else 
        b1 = this->toInt();
    if (a.get_flag() == 0)
        b = a.toFloat();
    else 
        b = a.toInt();
    Fixed f(b1 + b);
    if (this->flag == 0 || a.get_flag() == 0)
        f.flag = 0;
    else 
        f.flag = 1;
    return (f);
}

Fixed Fixed::operator-(Fixed const &a)
{
    float b;
    float b1;
    if (this->flag == 1 && a.get_flag() == 1)
    {
        this->store = this->toInt() - a.toInt();
    }
    if (this->flag == 0)
        b1 = this->toFloat();
    else 
        b1 = this->toInt();
    if (a.get_flag() == 0)
        b = a.toFloat();
    else 
        b = a.toInt();
    Fixed f(b1 - b);
    if (this->flag == 0 || a.get_flag() == 0)
        f.flag = 0;
    else 
        f.flag = 1;
    return (f);
}


bool Fixed::operator<(Fixed const &a)
{
    float b;
    float b1;
    if (this->flag == 0)
        b1 = this->toFloat();
    else 
        b1 = this->toInt();
    if (a.get_flag() == 0)
        b = a.toFloat();
    else 
        b = a.toInt();
    if (b1 < b)
        return (true);
    else 
        return (false);
}
bool Fixed::operator>(Fixed const &a)
{
    float b;
    float b1;
    if (this->flag == 0)
        b1 = this->toFloat();
    else 
        b1 = this->toInt();
    if (a.get_flag() == 0)
        b = a.toFloat();
    else 
        b = a.toInt();
    if (b1 > b)
        return (true);
    else 
        return (false);
}
bool Fixed::operator>=(Fixed const &a)
{
    float b;
    float b1;
    if (this->flag == 0)
        b1 = this->toFloat();
    else 
        b1 = this->toInt();
    if (a.get_flag() == 0)
        b = a.toFloat();
    else 
        b = a.toInt();
    if (b1 > b || cmpf(b1,b))
        return (true);
    else 
        return (false);
}
bool Fixed::operator<=(Fixed const &a)
{
    float b;
    float b1;
    if (this->flag == 0)
        b1 = this->toFloat();
    else 
        b1 = this->toInt();
    if (a.get_flag() == 0)
        b = a.toFloat();
    else 
        b = a.toInt();
    if (b1 > b || cmpf(b1,b))
        return (true);
    else 
        return (false);
}

// bool Fixed::operator==(Fixed const &a)
// {
//     float b;
//     float b1;
//     if (this->flag == 0)
//         b1 = this->toFloat();
//     else 
//         b1 = this->toInt();
//     if (a.get_flag() == 0)
//         b = a.toFloat();
//     else 
//         b = a.toInt();
//     if (cmpf(b1,b))
//         return (true);
//     else 
//         return (false);
// }


bool Fixed::operator==(Fixed const &a)
{
    float b;
    float b1;
    if (this->flag == 0)
        b1 = this->toFloat();
    else 
        b1 = this->toInt();
    if (a.get_flag() == 0)
        b = a.toFloat();
    else 
        b = a.toInt();
    if (!cmpf(b1,b))
        return (true);
    else 
        return (false);
}

Fixed &Fixed::min(Fixed const &a,Fixed const &b)
{
    Fixed h(a);
    Fixed h1(b);
    return (min(h,h1));
}
Fixed &Fixed::min(Fixed &a,Fixed &b)
{
     if (a <= b)
        return (a);
    else 
        return (b);
}
Fixed &Fixed::max(Fixed const &a,Fixed const &b)
{
    Fixed h(a);
    Fixed h1(b);
    return (max(h,h1));
}
Fixed &Fixed::max(Fixed &a,Fixed &b)
{
     if (a >= b)
        return (a);
    else 
        return (b);
}

Fixed    Fixed::operator++()
{
    float b1;
    int b;
    if (this->flag == 0)
    {
        b1 = this->toFloat();
        Fixed f (b1 + eps);
        this->store = f.store;
        this->flag = f.flag;
        return (*this);

    }
    else 
    {
        b = this->toInt();
        Fixed f (b + eps);
        this->store = f.store;
        this->flag = f.flag;
        return (*this);
    }
}
Fixed    Fixed::operator++(int)
{
    float b1;
    int b;
    if (this->flag == 0)
    {
        b1 = this->toFloat();
        Fixed x = *this;
        Fixed f (b1 + eps);
        this->store = f.store;
        this->flag = f.flag;
        return (x);

    }
    else 
    {
        b = this->toInt();
        Fixed x = *this;
        Fixed f (b + eps);
        this->store = f.store;
        this->flag = f.flag;
        return (x);
    }
}
Fixed    Fixed::operator--()
{
    float b1;
    int b;
    if (this->flag == 0)
    {
        b1 = this->toFloat();
        Fixed f (b1 - eps);
        this->store = f.store;
        this->flag = f.flag;
        return (*this);

    }
    else 
    {
        b = this->toInt();
        Fixed f (b - eps);
        this->store = f.store;
        this->flag = f.flag;
        return (*this);
    }
}
bool nearlyEqual(float a, float b, float epsilon) {
    float absA = abs(a);
    float absB = abs(b);
    float diff = abs(a - b);

    if (a == b) { // shortcut, handles infinities
        return true;
    } else if (a == 0 || b == 0 || diff < std::numeric_limits<float>::min()) {
        // a or b is zero or both are extremely close to it
        // relative error is less meaningful here
        return diff < (epsilon * std::numeric_limits<float>::min());
    } else { // use relative error
        return diff / (absA + absB) < epsilon;
    }
}
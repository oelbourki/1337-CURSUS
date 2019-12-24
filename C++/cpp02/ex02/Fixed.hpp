#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#define eps 0.00390625f

// class Fixed
// {
//     private:
//         int store;
//         static const int frac = 8;
//         bool flag;
//     public:
//         Fixed(int &val);
//         Fixed(float &val);
//         Fixed(void);
//         ~Fixed();
//         Fixed(Fixed const &f);
//         int get_store() const;
//         Fixed operator=(Fixed const &a);
//         bool operator<(Fixed const &a);
//         bool operator>(Fixed const &a);
//         bool operator>=(Fixed const &a);
//         bool operator<=(Fixed const &a);
//         bool operator!=(Fixed const &a);
//         bool operator==(Fixed const &a);
//         Fixed operator*(Fixed const &a);
//         Fixed operator/(Fixed const &a);
//         Fixed operator+(Fixed const &a);
//         Fixed operator-(Fixed const &a);
//         Fixed    operator++();
//         Fixed    operator--();
//         int getRawBits( void ) const;
//         void setRawBits( int const raw);
//         float toFloat( void ) const;
//         int toInt( void ) const;
//         bool get_flag() const;
// };


class Fixed
{
    private:
        int store;
        static const int frac = 8;
        bool flag;
    public:
        Fixed(int const &val);
        Fixed(float const &val);
        Fixed();
        ~Fixed();
        Fixed(Fixed const &f);
        int getRawBits( void ) const;
        void setRawBits( int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        bool get_flag() const;
        int get_store() const;
        Fixed operator=(Fixed const &a);
        bool operator<(Fixed const &a);
        bool operator>(Fixed const &a);
        bool operator>=(Fixed const &a);
        bool operator<=(Fixed const &a);
        bool operator!=(Fixed const &a);
        bool operator==(Fixed const &a);
        Fixed operator*(Fixed const &a);
        Fixed operator/(Fixed const &a);
        Fixed operator+(Fixed const &a);
        Fixed operator-(Fixed const &a);
        Fixed    operator++();
        Fixed    operator++(int);
        Fixed    operator--();
        static Fixed &min(Fixed const &a,Fixed const &b);
        static Fixed &min(Fixed &a,Fixed &b);
        static Fixed &max(Fixed const &a,Fixed const &b);
        static Fixed &max(Fixed &a,Fixed &b);
};


std::ostream& operator<< (std::ostream& out, const Fixed& _Fixed);
Fixed &min(Fixed const &a,Fixed const &b);
Fixed &min(Fixed &a,Fixed &b);
Fixed &max(Fixed const &a,Fixed const &b);
Fixed &max(Fixed &a,Fixed &b);
#endif
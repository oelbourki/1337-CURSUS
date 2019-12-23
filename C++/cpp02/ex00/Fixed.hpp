#include <iostream>



class Fixed
{
    private:
        int store;
        static const int frac = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed const &f);
        Fixed& operator=(Fixed const &a);
        int getRawBits( void ) const;
        void setRawBits( int const raw); 
};
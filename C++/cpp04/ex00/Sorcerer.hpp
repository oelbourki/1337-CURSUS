#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"
class Sorcerer {
    public:
    Sorcerer(std::string name, std::string title);
    Sorcerer();
    Sorcerer(Sorcerer const & wiz);
    Sorcerer & operator=(const Sorcerer & wiz);
    void polymorph(Victim const &) const;
    std::string     get_name();
    std::string     get_title();
    ~Sorcerer();
    private:
    std::string name;
    std::string title;
};
std::ostream& operator<< (std::ostream& out, Sorcerer& _Sorcerer);
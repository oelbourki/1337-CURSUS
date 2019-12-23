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
    void polymorph(Peon const &) const;
    std::string operator<<(const Sorcerer &c);
    ~Sorcerer();

    private:
    std::string name;
    std::string title;
};


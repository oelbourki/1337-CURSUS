
#ifndef VICTIM_HPP
#define VICTIM_HPP
#include <iostream>
class Victim {
	public:
        Victim(std::string name);
		Victim();
		~Victim();
        virtual void getPolymorphed() const;
		std::string get_name();
	protected:
	private:
        std::string name;
};
std::ostream& operator<< (std::ostream& out, Victim& _Victim);
#endif


#ifndef PEON_HPP
#define PEON_HPP
#include "Victim.hpp"
class Peon : virtual public Victim {
	public:
		Peon(std::string name);
		Peon();
		~Peon();
 		void getPolymorphed() const;
		std::string get_name();
	protected:
	private:
        std::string name;
};

#endif 


#ifndef PEON_HPP
#define PEON_HPP
#include "Victim.hpp"
class Peon : public Victim {
	public:
		Peon(std::string name);
		Peon();
		~Peon();
 		void getPolymorphed() const;

	protected:
	private:
        std::string name;
};

#endif 

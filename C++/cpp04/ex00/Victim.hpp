
#ifndef VICTIM_HPP
#define VICTIM_HPP
#include <iostream>
class Victim {
	public:
        Victim(std::string name);
		Victim();
		~Victim();
        void getPolymorphed() const;

	protected:
	private:
        std::string name;
};

#endif

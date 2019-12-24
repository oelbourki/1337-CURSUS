#pragma once
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		~PlasmaRifle();
        PlasmaRifle(PlasmaRifle const &a);
        PlasmaRifle(std::string const & name, int apcost, int damage);
        void PlasmaRifle::attack() const;
};

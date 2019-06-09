#ifndef MIMITURRET_HPP
#define MIMITURRET_HPP
#include "Turret.hpp"

class MimiTurret: public Turret {
public:
	static const int Price;
    MimiTurret(float x, float y);
	void CreateBullet() override;
};
#endif // MACHINEGUNTURRET_HPP

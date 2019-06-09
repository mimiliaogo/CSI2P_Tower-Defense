#ifndef MIMIBULLET_HPP
#define MIMIBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class MimiBullet : public Bullet {
public:
	explicit MimiBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};
#endif // FIREBULLET_HPP


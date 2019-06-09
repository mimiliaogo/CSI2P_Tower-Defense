#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "MimiBullet.hpp"
#include "Group.hpp"
#include "MimiTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int MimiTurret::Price = 30;
MimiTurret::MimiTurret(float x, float y) :
	// TODO 2 (2/8): You can imitate the 2 files: 'MachineGunTurret.hpp', 'MachineGunTurret.cpp' to create a new turret.
	Turret("play/tower-base.png", "play/turret-7.png", x, y, 800, Price, 0.3) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void MimiTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x);
	Engine::Point normalized = diff.Normalize();
	// Change bullet position to the front of the gun barrel.
	getPlayScene()->BulletGroup->AddNewObject(new MimiBullet(Position + normalized * 36, diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}


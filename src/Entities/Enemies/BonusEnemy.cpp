#include "BonusEnemy.hpp"

void BonusEnemy::draw() {
    if (HitBox::drawHitbox) this->hitBox.draw();
    DrawTexturePro(ImageManager::SpriteSheet, textureSource, 
            Rectangle{this->position.first + 15, this->position.second + 15, 30, 30}, 
            Vector2{15, 15}, this->aimAngle, WHITE);
}

void BonusEnemy::update(std::pair<float, float> pos, HitBox target) {
    this->cooldown--;

    if (!loop) {
        this->angle += 1.5;
        this->aimAngle += 1.5;
        if (this->angle >= 180) {
            loop = true;
        }
    } else {
        this->angle -= 1.5;
        this->aimAngle -= 1.5;
        if (this->angle <= 45) {
            loop = false;
        }
    }

    this->position.first += 2 * cos(angle * M_PI / 180);
    this->position.second += 2 * sin(angle * M_PI / 180);
    this->hitBox.box.x = this->position.first;
    this->hitBox.box.y = this->position.second;

    if (this->cooldown <= 0) {
        this->attack(target);
        this->cooldown = GetRandomValue(120, 300);
    }
}

void BonusEnemy::attack(HitBox target) {
    // Calculate angle to player
    float dx = target.box.x - this->position.first;
    float dy = target.box.y - this->position.second;
    float angleToPlayer = atan2(dy, dx) * 180 / M_PI;

    // Fire two shots: one offset left, one offset right
    float offset = 15.0f;
    Projectile::projectiles.push_back(Projectile(this->position.first + 15, this->position.second + 15, 1));
    Projectile::projectiles.push_back(Projectile(this->position.first + 15, this->position.second + 15, 1));
    PlaySound(SoundManager::shoot);
}
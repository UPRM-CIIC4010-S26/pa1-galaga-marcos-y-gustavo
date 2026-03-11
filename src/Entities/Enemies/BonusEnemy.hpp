#pragma once
#include "Enemy.hpp"

class BonusEnemy : public Enemy {
    private:
        float angle = 45;
        float aimAngle = 225;
        bool loop = false;
        Rectangle textureSource;

    public:
        BonusEnemy(float x, float y) : Enemy(x, y) { 
            this->cooldown = GetRandomValue(120, 300);
            this->scoreValue = 200; 
            this->health = 2; 
            textureSource = (GetRandomValue(0, 1) == 0) ? Rectangle{57, 1, 13, 16} : Rectangle{73, 1, 13, 16};
        }

        void draw() override;
        void update(std::pair<float, float> pos, HitBox target) override;
        void attack(HitBox target) override;
};
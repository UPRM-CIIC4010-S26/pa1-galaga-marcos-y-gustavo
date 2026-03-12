#pragma once
#include "Enemy.hpp"

class BonusEnemy : public Enemy {
    private:
        float angle;
        float aimAngle;
        bool loop = false;
        Rectangle textureSource;

    public:
        BonusEnemy(float x, float y) : Enemy(x, y) { 
            this->angle = GetRandomValue(200, 340);
            this->aimAngle = angle;

            this->cooldown = GetRandomValue(120, 300);
            this->scoreValue = 200; 
            this->health = 2; 
            textureSource = (GetRandomValue(0, 1) == 0) ? Rectangle{57, 198, 13, 16} : Rectangle{75, 198, 13, 16};
        }

        ~BonusEnemy() {}

        void draw() override;
        void update(std::pair<float, float> pos, HitBox target) override;
        void attack(HitBox target) override;
};
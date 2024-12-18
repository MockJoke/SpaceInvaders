#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../Entity/EntityConfig.h"
#include "../Projectile/IProjectile.h"

namespace Bullet
{
    class BulletController;
    enum class BulletType;
    enum class MovementDirection;

    class BulletService
    {
    private:
        std::vector<Projectile::IProjectile*> bullet_list;
        std::vector<Projectile::IProjectile*> flagged_bullet_list;

        BulletController* createBullet(BulletType bullet_type, Entity::EntityType entity_type);
        bool isValidBullet(int index, std::vector<Projectile::IProjectile*>& bullet_list);
        void destroyFlaggedBullets();
        
        void destroy();

    public:
        BulletService();
        virtual ~BulletService();

        void initialize();
        void update();
        void render();

        void reset();

        BulletController* spawnBullet(BulletType bullet_type, Entity::EntityType entity_type, sf::Vector2f position, MovementDirection direction);
        void destroyBullet(BulletController* bullet_controller);
    };
}
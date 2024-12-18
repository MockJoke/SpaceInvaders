#include "../../include/Bullet/BulletService.h"
#include "../../include/Bullet/BulletController.h"
#include "../../include/Bullet/BulletConfig.h"
#include "../../include/Bullet/Controllers/PlayerBulletController.h"
#include "../../include/Bullet/Controllers/FrostBulletController.h"
#include "../../include/Bullet/Controllers/LaserBulletController.h"
#include "../../include/Bullet/Controllers/TorpedoController.h"
#include "../../include/Global/ServiceLocator.h"
// #include <iostream>

namespace Bullet
{
    BulletService::BulletService() { }

    BulletService::~BulletService() { destroy(); }

    void BulletService::initialize()
    {
        bullet_list.clear();
        flagged_bullet_list.clear();
    }

    void BulletService::update()
    {
        for (Projectile::IProjectile* bullet : bullet_list)
        {
            bullet->update();
        }

        destroyFlaggedBullets();
    }

    void BulletService::render()
    {
        for (Projectile::IProjectile* bullet : bullet_list)
        {
            bullet->render();
        }
    }

    BulletController* BulletService::createBullet(BulletType bullet_type, Entity::EntityType entity_type)
    {
        switch (bullet_type)
        {
        case BulletType::PLAYER_BULLET:
            return new Controller::PlayerBulletController(BulletType::PLAYER_BULLET, entity_type);
            
        case BulletType::LASER_BULLET:
            return new Controller::LaserBulletController(BulletType::LASER_BULLET, entity_type);

        case BulletType::FROST_BULLET:
            return new Controller::FrostBulletController(BulletType::FROST_BULLET, entity_type);

        case BulletType::TORPEDO:
            return new Controller::TorpedoController(BulletType::TORPEDO, entity_type);
        }
    }

    bool BulletService::isValidBullet(int index, std::vector<Projectile::IProjectile*>& bullet_list)
    {
        return index >= 0 && index < bullet_list.size() && bullet_list[index] != nullptr;
    }

    BulletController* BulletService::spawnBullet(BulletType bullet_type, Entity::EntityType owner_type, sf::Vector2f position, MovementDirection direction)
    {
        BulletController* bullet_controller = createBullet(bullet_type, owner_type);
        bullet_controller->initialize(position, direction);

        Global::ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<Collision::ICollider*>(bullet_controller));
        bullet_list.push_back(bullet_controller);
        return bullet_controller;
    }

    void BulletService::reset() { destroy(); }

    void BulletService::destroyFlaggedBullets()
    {
        for (int i = 0; i < flagged_bullet_list.size(); i++)
        {
            if (!isValidBullet(i, flagged_bullet_list))
                continue;

            // std::cerr << "Inspecting flagged bullet at index " << i << ": " << flagged_bullet_list[i] << '\n';
            // auto collider = dynamic_cast<Collision::ICollider*>(flagged_bullet_list[i]);

            // if (collider != nullptr)
            // {
            //     Global::ServiceLocator::getInstance()->getCollisionService()->removeCollider(collider);
            // }

            Global::ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(flagged_bullet_list[i]));

            delete (flagged_bullet_list[i]);
            flagged_bullet_list[i] = nullptr;
        }
        
        flagged_bullet_list.clear();
    }

    void BulletService::destroyBullet(BulletController* bullet_controller)
    {
        if (std::find(flagged_bullet_list.begin(), flagged_bullet_list.end(), bullet_controller) != flagged_bullet_list.end())
        {
            // std::cerr << "Bullet already flagged for destruction: " << bullet_controller << '\n';
            return; // Skip adding if it's already there
        }

        bullet_controller->disableCollision();
        flagged_bullet_list.push_back(bullet_controller);
        // std::cerr << "Added bullet at index " << flagged_bullet_list.size() -1 << ": " << flagged_bullet_list[flagged_bullet_list.size() -1] << '\n';
        bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
    }

    void BulletService::destroy()
    {
        for (int i = 0; i < bullet_list.size(); i++)
        {
            if (!isValidBullet(i, bullet_list))
                continue;

            Global::ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(bullet_list[i]));
            delete (bullet_list[i]);
        }
        
        bullet_list.clear();
    }
}
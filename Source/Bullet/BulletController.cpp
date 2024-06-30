#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
    BulletController::BulletController(BulletType type)
    {
    }

    BulletController::~BulletController()
    {
    }

    void BulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
    {
    }

    void BulletController::update()
    {
    }

    void BulletController::render()
    {
    }

    void BulletController::updateProjectilePosition()
    {
    }

    sf::Vector2f BulletController::getProjectilePosition()
    {
        return sf::Vector2f(0, 0);
    }

    void BulletController::handleOutOfBounds()
    {
    }

    void BulletController::moveUp()
    {
    }

    void BulletController::moveDown()
    {
    }
}

#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
    BulletModel::BulletModel(BulletType type)
    {
        bullet_type = type;
    }

    BulletModel::~BulletModel() { }

    void BulletModel::initialize(sf::Vector2f position, MovementDirection direction)
    {
        movement_direction = direction;
        bullet_position = position;
    }

    sf::Vector2f BulletModel::getBulletPosition() const
    {
        return bullet_position;
    }

    void BulletModel::setBulletPosition(sf::Vector2f position)
    {
        bullet_position = position;
    }

    BulletType BulletModel::getBulletType() const
    {
        return bullet_type;
    }

    void BulletModel::setBulletType(BulletType type)
    {
        bullet_type = type;
    }

    MovementDirection BulletModel::getMovementDirection() const
    {
        return movement_direction;
    }

    void BulletModel::setMovementDirection(MovementDirection direction)
    {
        movement_direction = direction;
    }

    float BulletModel::getMovementSpeed() const
    {
        return movement_speed;
    }

    void BulletModel::setMovementSpeed(float speed)
    {
        movement_speed = speed;
    }
}
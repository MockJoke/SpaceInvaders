#include "../../include/Bullet/BulletController.h"
#include "../../include/Bullet/BulletModel.h"
#include "../../include/Bullet/BulletView.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Player/PlayerController.h"
#include "../../include/Enemy/EnemyController.h"

namespace Bullet
{
    BulletController::BulletController(BulletType bullet_type, Entity::EntityType entity_type)
    {
        bullet_view = new BulletView();
        bullet_model = new BulletModel(bullet_type, entity_type);
    }

    BulletController::~BulletController()
    {
        delete (bullet_view);
        delete (bullet_model);
    }

    void BulletController::initialize(sf::Vector2f position, MovementDirection direction)
    {
        bullet_view->initialize(this);
        bullet_model->initialize(position, direction);
    }

    void BulletController::update()
    {
        updateProjectilePosition();
        bullet_view->update();
        handleOutOfBounds();
    }

    void BulletController::render()
    {
        bullet_view->render();
    }

    void BulletController::updateProjectilePosition()
    {
        switch (bullet_model->getMovementDirection())
        {
        case MovementDirection::UP:
            moveUp();
            break;

        case MovementDirection::DOWN:
            moveDown();
            break;
        }
    }

    void BulletController::moveUp()
    {
        sf::Vector2f currentPosition = bullet_model->getBulletPosition();
        currentPosition.y -= bullet_model->getMovementSpeed() * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

        bullet_model->setBulletPosition(currentPosition);
    }

    void BulletController::moveDown()
    {
        sf::Vector2f currentPosition = bullet_model->getBulletPosition();
        currentPosition.y += bullet_model->getMovementSpeed() * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

        bullet_model->setBulletPosition(currentPosition);
    }
    
    void BulletController::handleOutOfBounds()
    {
        sf::Vector2f bulletPosition = getProjectilePosition();
        sf::Vector2u windowSize = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

        if (bulletPosition.x < 0 || bulletPosition.x > windowSize.x ||
            bulletPosition.y < 0 || bulletPosition.y > windowSize.y)
        {
            Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
        }
    }
    
    sf::Vector2f BulletController::getProjectilePosition()
    {
        return bullet_model->getBulletPosition();
    }

    BulletType BulletController::getBulletType() const
    {
        return bullet_model->getBulletType();
    }

    Entity::EntityType BulletController::getEntityType() const
    {
        return bullet_model->getEntityType();
    }

    void BulletController::processBulletCollision(ICollider* other_collider)
    {
        BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

        if (bullet_controller)
        {
            Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
        }
    }

    void BulletController::processEnemyCollision(ICollider* other_collider)
    {
        Enemy::EnemyController* enemy_controller = dynamic_cast<Enemy::EnemyController*>(other_collider);

        if (enemy_controller && getEntityType() != Entity::EntityType::ENEMY)
        {
            Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
        }
    }

    void BulletController::processPlayerCollision(ICollider* other_collider)
    {
        Player::PlayerController* player_controller = dynamic_cast<Player::PlayerController*>(other_collider);

        if (player_controller && getEntityType() != Entity::EntityType::PLAYER)
        {
            Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
        }
    }

    void BulletController::processBunkerCollision(ICollider* other_collider)
    {
        Element::Bunker::BunkerController* bunker_controller = dynamic_cast<Element::Bunker::BunkerController*>(other_collider);

        if (bunker_controller)
        {
            Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
        }
    }

    const sf::Sprite& BulletController::getColliderSprite()
    {
        return bullet_view->getBulletSprite();
    }

    void BulletController::onCollision(ICollider* other_collider)
    {
        processPlayerCollision(other_collider);
        processEnemyCollision(other_collider);
        processBunkerCollision(other_collider);
        processBulletCollision(other_collider);
    }
}
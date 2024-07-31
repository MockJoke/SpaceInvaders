#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    EnemyView::EnemyView()
    {
        createUIElements();
    }

    EnemyView::~EnemyView()
    {
        destroy();
    }

    void EnemyView::initialize(EnemyController* controller)
    {
        enemy_controller = controller;
        initializeImage();
    }

    void EnemyView::createUIElements()
    {
        enemy_image = new UI::UIElement::ImageView();
    }

    void EnemyView::initializeImage()
    {
        enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_width, enemy_sprite_height, enemy_controller->getEnemyPosition());
    }

    void EnemyView::update() const
    {
        enemy_image->setPosition(enemy_controller->getEnemyPosition());
        enemy_image->update();
    }

    void EnemyView::render() const
    {
        enemy_image->render();
    }

    sf::String EnemyView::getEnemyTexturePath()
    {
        switch (enemy_controller->getEnemyType())
        {
        case EnemyType::ZAPPER:
            return Global::Config::zapper_texture_path;

        case EnemyType::THUNDER_SNAKE:
            return Global::Config::thunder_snake_texture_path;

        case EnemyType::SUBZERO:
            return Global::Config::subzero_texture_path;

        case EnemyType::UFO:
            return Global::Config::ufo_texture_path;
        }
    }

    void EnemyView::destroy() const
    {
        delete(enemy_image);
    }
}
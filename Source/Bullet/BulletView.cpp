#include <iostream>
#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
    BulletView::BulletView()
    {
        createUIElements();
    }

    BulletView::~BulletView()
    {
        destroy();
    }

    void BulletView::initialize(BulletController* controller)
    {
        bullet_controller = controller;
        initializeImage();
    }

    void BulletView::createUIElements()
    {
        bullet_image = new UI::UIElement::ImageView();
    }
    
    void BulletView::initializeImage()
    {
        bullet_image->initialize(getBulletTexturePath(), bullet_sprite_width, bullet_sprite_height, bullet_controller->getProjectilePosition());
    }

    void BulletView::update() const
    {
        bullet_image->setPosition(bullet_controller->getProjectilePosition());
        bullet_image->update();
    }

    void BulletView::render() const
    {
        bullet_image->render();
    }

    sf::String BulletView::getBulletTexturePath()
    {
        switch (bullet_controller->getBulletType())
        {
        case BulletType::PLAYER_BULLET:
            return Global::Config::player_bullet_texture_path;
            
        case BulletType::LASER_BULLET:
            return Global::Config::laser_bullet_texture_path;

        case BulletType::FROST_BULLET:
            return Global::Config::frost_beam_texture_path;

        case BulletType::TORPEDO:
            return Global::Config::torpedoe_texture_path;
        }
    }

    void BulletView::destroy() const
    {
        delete(bullet_image);
    }
}
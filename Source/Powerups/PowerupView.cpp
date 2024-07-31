#include "../../header/Powerup/PowerupView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Powerup/PowerupController.h"
#include "../../header/Powerup/PowerupConfig.h"

namespace Powerup
{
    using namespace Global;

    PowerupView::PowerupView()
    {
        createUIElements();
    }

    PowerupView::~PowerupView()
    {
        destroy();
    }

    void PowerupView::initialize(PowerupController* controller)
    {
        powerup_controller = controller;
        initializeImage();
    }

    void PowerupView::createUIElements()
    {
        powerup_image = new UI::UIElement::ImageView();
    }

    void PowerupView::initializeImage()
    {
        powerup_image->initialize(getPowerupTexturePath(), powerup_sprite_width, powerup_sprite_height, powerup_controller->getCollectiblePosition());
    }

    void PowerupView::update() const
    {
        powerup_image->setPosition(powerup_controller->getCollectiblePosition());
        powerup_image->update();
    }

    void PowerupView::render() const
    {
        powerup_image->render();
    }

    sf::String PowerupView::getPowerupTexturePath()
    {
        switch (powerup_controller->getPowerupType())
        {
        case PowerupType::SHIELD:
            return Config::shield_texture_path;

        case PowerupType::TRIPPLE_LASER:
            return Config::tripple_laser_texture_path;

        case PowerupType::RAPID_FIRE:
            return Config::rapid_fire_texture_path;
        }
    }

    void PowerupView::destroy() const
    {
        delete(powerup_image);
    }
}
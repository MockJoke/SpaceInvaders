#pragma once
#include <SFML/Graphics.hpp>
#include "../UI/UIElement/ImageView.h"

namespace Powerup
{
    class PowerupController;
    enum class PowerupType;

    class PowerupView
    {
    private:
        const float powerup_sprite_width = 30.f;
        const float powerup_sprite_height = 30.f;

        PowerupController* powerup_controller;
        UI::UIElement::ImageView* powerup_image;

        void createUIElements();
        void initializeImage();
        sf::String getPowerupTexturePath();

        void destroy() const;

    public:
        PowerupView();
        ~PowerupView();

        void initialize(PowerupController* controller);
        void update() const;
        void render() const;

        const sf::Sprite& getPowerupSprite() const;
    };
}

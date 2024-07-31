#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyConfig.h"
#include "../../header/UI/UIElement/ImageView.h"

namespace Enemy
{
    class EnemyController;

    class EnemyView
    {
    private:
        const float enemy_sprite_width = 80.f;
        const float enemy_sprite_height = 80.f;

        EnemyController* enemy_controller;
        UI::UIElement::ImageView* enemy_image;

        void createUIElements();
        void initializeImage();
        sf::String getEnemyTexturePath();

        void destroy() const;

    public:
        EnemyView();
        ~EnemyView();

        void initialize(EnemyController* controller);
        void update() const;
        void render() const;
    };
}

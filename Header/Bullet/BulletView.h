#pragma once
#include <SFML/Graphics.hpp>
#include "../UI/UIElement/ImageView.h"

namespace Bullet
{
    class BulletController;
    enum class BulletType;

    class BulletView
    {
    private:
        const float bullet_sprite_width = 20.f;
        const float bullet_sprite_height = 20.f;

        sf::RenderWindow* game_window;
        sf::Texture bullet_texture;
        sf::Sprite bullet_sprite;

        BulletController* bullet_controller;
        UI::UIElement::ImageView* bullet_image;

        void createUIElements();
        void initializeImage();
        sf::String getBulletTexturePath();

        void destroy() const;

    public:
        BulletView();
        ~BulletView();

        void initialize(BulletController* controller);
        void update() const;
        void render() const;
    };
}
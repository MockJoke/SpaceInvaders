#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace Gameplay
{
    class GameplayController;

    class GameplayView
    {
    private:
        sf::RenderWindow* game_window;
        sf::Texture background_texture;
        sf::Sprite background_sprite;

        GameplayController* gameplay_controller;
        UI::UIElement::ImageView* background_image;
        
        void initializeBackgroundImage() const;

    public:
        GameplayView();
        ~GameplayView();

        void initialize() const;
        void update() const;
        void render() const;
    };
}

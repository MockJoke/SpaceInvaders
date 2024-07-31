#pragma once
#include <SFML/Graphics.hpp>
#include "../../Global/Config.h"
#include "../../header/UI/UIElement/ImageView.h"

namespace Element
{
    namespace Bunker
    {
        class BunkerController;

        class BunkerView
        {
        private:
            const float bunker_sprite_width = 80.f;
            const float bunker_sprite_height = 60.f;

            BunkerController* bunker_controller;
            UI::UIElement::ImageView* bunker_image;

            sf::Texture bunker_texture;
            sf::Sprite bunker_sprite;

            void createUIElements();
            void initializeImage() const;

            void destroy() const;

        public:
            BunkerView();
            ~BunkerView();

            void initialize(BunkerController* controller);
            void update() const;
            void render() const;
        };
    }
}

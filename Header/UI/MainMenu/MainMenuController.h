#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"
#include "../Button.h"
#include "../../Global/Config.h"

namespace UI
{
    namespace MainMenu
    {
        class MainMenuUIController : public Interface::IUIController
        {
        private:
            const sf::String background_texture_path = Global::Config::background_texture_path;

            sf::RenderWindow* game_window;

            sf::Texture background_texture;
            sf::Sprite background_sprite;

            const sf::String title_font_texture_path = Global::Config::ArcadeI_font_path;
            const sf::String button_font_texture_path = Global::Config::ArcadeN_font_path;
            
            sf::Font title_font;
            sf::Text title_text;

            sf::Font button_font;
            Button play_btn;
            Button help_btn;
            Button quit_btn;

            // Since this is a single image, we can check if it loaded or not during initialization
            void initializeBackgroundImage();
            void scaleBackgroundImage();

            void initializeTitle();
            
            void initializeButtons();
            void positionButtons();

            void processButtonInteractions();
            bool clickedButton(const Button*, sf::Vector2f);

            void destroy();
            
        public:
            MainMenuUIController();

            void initialize() override;
            void update() override;
            void render() override;
            void show() override;
        };
    }
}

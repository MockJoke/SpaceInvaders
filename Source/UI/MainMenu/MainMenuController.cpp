#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/UI/Button.h"

namespace UI
{
    namespace MainMenu
    {
        MainMenuUIController::MainMenuUIController()
        {
            game_window = nullptr;
        }

        void MainMenuUIController::initialize()
        {
            game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBackgroundImage();
            initializeTitle();
            initializeButtons();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            // Check if a texture is loaded properly
            if (background_texture.loadFromFile(background_texture_path))
            {
                // If it did then set the bg image & scale it
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }

        void MainMenuUIController::scaleBackgroundImage()
        {
            // Scaling bg image based on the size of the game window 
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void MainMenuUIController::initializeTitle()
        {
            if (title_font.loadFromFile(title_font_texture_path))
            {
                title_text.setFont(title_font);
                title_text.setString("SPACE INVADERS");
                title_text.setFillColor(sf::Color::White);
                title_text.setCharacterSize(80);
                title_text.setPosition(static_cast<float>(game_window->getSize().x) / 2.f - title_text.getGlobalBounds().width/2.f, 150.f);
            }
        }

        void MainMenuUIController::initializeButtons()
        {
            if (button_font.loadFromFile(button_font_texture_path))
            {
                play_btn.Create("PLAY", button_font, sf::Color::White, 40);
                help_btn.Create("HELP", button_font, sf::Color::White, 40);
                quit_btn.Create("QUIT", button_font, sf::Color::White, 40);
                
                positionButtons();
            }
        }

        void MainMenuUIController::positionButtons()
        {
            play_btn.SetPosition(static_cast<float>(game_window->getSize().x) / 2.f - play_btn.getBounds().x / 2.f, 500.f);
            help_btn.SetPosition(static_cast<float>(game_window->getSize().x) / 2.f - help_btn.getBounds().x / 2.f, 700.f);
            quit_btn.SetPosition(static_cast<float>(game_window->getSize().x) / 2.f - quit_btn.getBounds().x / 2.f, 900.f);
        }
        
        void MainMenuUIController::update()
        {
            processButtonInteractions();
        }

        void MainMenuUIController::render()
        {
            game_window->draw(background_sprite);

            game_window->draw(title_text);
            
            play_btn.Render(game_window);
            help_btn.Render(game_window);
            quit_btn.Render(game_window);
        }

        /*
            First we get the location of the mouse on our screen,
            If we register a click while the mouse is above a button, 
            then we do something based on which button it is
            we will call processButtonInteractions() on update
        */
        void MainMenuUIController::processButtonInteractions()
        {
            const sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            play_btn.CheckForMouseHover(mouse_position);
            help_btn.CheckForMouseHover(mouse_position);
            quit_btn.CheckForMouseHover(mouse_position);
            
            if (clickedButton(&play_btn, mouse_position))
            {
                Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                Global::ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
                Main::GameService::setGameState(Main::GameState::GAMEPLAY);
            }

            if (clickedButton(&help_btn, mouse_position))
            {
                printf("Clicked Help Button \n");
            }

            if (clickedButton(&quit_btn, mouse_position))
            {
                game_window->close();
            }
        }
				
        /*
        This checks if the use left clicked on a sprite & then returns
        true if the click happened while the mouse was overlapping with the
        button
        */
        bool MainMenuUIController::clickedButton(const Button* button, sf::Vector2f mouse_position)
        {
            const Event::EventService* event_service = Global::ServiceLocator::getInstance()->getEventService();
            return event_service->pressedLeftMouseButton() && button->IsMousePointerOverlapping(mouse_position);
        }

        void MainMenuUIController::show()
        {
            
        }

        void MainMenuUIController::destroy()
        {
            
        }
    }
}
﻿#include "../Header/EventService.h"
#include "../Header/GameService.h"
#include "../Header/GraphicService.h"

EventService::EventService()
{
    game_window = nullptr;
}

EventService::~EventService() = default;    // calls the default destructor

void EventService::initialize()
{
    game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
}

void EventService::update()
{
}
    
void EventService::processEvents()
{
    if (isGameWindowOpen())
    {
        while (game_window->pollEvent(game_event))
        {
            // Check for window closure
            if (gameWindowWasClosed() || hasQuitGame())
            {
                game_window->close();
            }               
        }
    }
}

bool EventService::hasQuitGame() const
{
    // only true if the ESC key is pressed and a keyboard event has been registered
    return (isKeyboardEvent() && pressedEscapeKey());
}

bool EventService::isGameWindowOpen() const { return game_window != nullptr; }

bool EventService::gameWindowWasClosed() const { return game_event.type == sf::Event::Closed; }

// Checks for if a keyboard key has been pressed
bool EventService::isKeyboardEvent() const { return game_event.type == sf::Event::KeyPressed; }

bool EventService::pressedEscapeKey() const { return game_event.key.code == sf::Keyboard::Escape; }

bool EventService::pressedLeftKey() const { return game_event.key.code == sf::Keyboard::Left; }

bool EventService::pressedRightKey() const { return game_event.key.code == sf::Keyboard::Right; }
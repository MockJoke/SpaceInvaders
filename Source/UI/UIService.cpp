#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"

namespace UI
{
    UIService::UIService()
    {
        main_menu_controller = nullptr;

        createControllers();
    }

    void UIService::createControllers()
    {
        main_menu_controller = new MainMenu::MainMenuUIController();
    }

    UIService::~UIService()
    {
        destroy();
    }

    void UIService::initialize()
    {
        initializeControllers();
    }

    void UIService::update()
    {
        Interface::IUIController* ui_controller = getCurrentUIController();
        
        if (ui_controller)
            ui_controller->update();
    }

    void UIService::render()
    {
        Interface::IUIController* ui_controller = getCurrentUIController();
        
        if (ui_controller)
            ui_controller->render();
    }

    void UIService::showScreen()
    {
        Interface::IUIController* ui_controller = getCurrentUIController();

        if (ui_controller)
            ui_controller->show();
    }
    
    void UIService::initializeControllers() const
    {
        main_menu_controller->initialize();
    }

    Interface::IUIController* UIService::getCurrentUIController() const
    {
        switch (Main::GameService::getGameState())
        {
        case Main::GameState::MAIN_MENU:
            return main_menu_controller;

        default:
            return nullptr;
        }
    }

    void UIService::destroy()
    {
        delete(main_menu_controller);
    }
}
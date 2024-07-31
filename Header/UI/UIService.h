#pragma once
#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../header/UI/Interface/IUIController.h"

namespace UI
{
    class UIService
    {
    private:
        MainMenu::MainMenuUIController* main_menu_controller;

        void createControllers();
        void initializeControllers() const;
        Interface::IUIController* getCurrentUIController() const;
        void destroy();

    public:
        UIService();
        ~UIService();

        void initialize();
        void update();
        void render();
        void showScreen();
    };
}

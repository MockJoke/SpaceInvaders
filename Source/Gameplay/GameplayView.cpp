#include "../../header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Gameplay
{
    GameplayView::GameplayView()
    {
        background_image = new UI::UIElement::ImageView();
    }

    GameplayView::~GameplayView()
    {
        delete(background_image);
    }

    void GameplayView::initialize() const
    {
        initializeBackgroundImage();
    }

    void GameplayView::initializeBackgroundImage() const
    {
        sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

        background_image->initialize(Global::Config::background_texture_path,
                                     game_window->getSize().x,
                                     game_window->getSize().y,
                                     sf::Vector2f(0, 0));
    }

    void GameplayView::update() const
    {
        background_image->update();
    }

    void GameplayView::render() const
    {
        background_image->render();
    }
}

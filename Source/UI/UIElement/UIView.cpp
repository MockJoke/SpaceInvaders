#include "../../header/UI/UIElement/UIView.h"
#include "../../header/Global/ServiceLocator.h"

namespace UI
{
    namespace UIElement
    {
        UIView::UIView() = default;

        UIView::~UIView() = default;

        void UIView::initialize()
        {
            game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            ui_state = UIState::VISIBLE;
        }

        void UIView::update() { }

        void UIView::render() { }

        void UIView::show()
        {
            ui_state = UIState::VISIBLE;
        }

        void UIView::hide()
        {
            ui_state = UIState::HIDDEN;
        }
    }
}
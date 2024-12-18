﻿#include "../../include/Player/PlayerController.h"
#include "../../include/Player/PlayerView.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Player/PlayerModel.h"

namespace Player
{
    PlayerView::PlayerView() { createUIElements(); }

    PlayerView::~PlayerView() { destroy(); }

    void PlayerView::initialize(PlayerController* controller)
    {
        player_controller = controller;
        initializeImage();
    }

    void PlayerView::createUIElements()
    {
        player_image = new UI::UIElement::ImageView();
    }

    void PlayerView::initializeImage() const
    {
        player_image->initialize(Global::Config::player_texture_path, player_sprite_width, player_sprite_height, player_controller->getPlayerPosition());
    }

    void PlayerView::update() const
    {
        player_image->setPosition(player_controller->getPlayerPosition());
        player_image->update();
    }

    void PlayerView::render() const
    {
        player_image->render();
    }

    void PlayerView::destroy() const
    {
        delete(player_image);
    }

    void PlayerView::setPlayerHighlight(bool b_highlight) const
    {
        if (b_highlight)
        {
            player_image->setImageAlpha(PlayerModel::invincible_player_alpha);
        }
        else
        {
            player_image->setImageAlpha(255);
        }
    }

    const sf::Sprite& PlayerView::getPlayerSprite() const
    {
        return player_image->getSprite();
    }
}

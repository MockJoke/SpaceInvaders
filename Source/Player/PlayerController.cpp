﻿#include <iostream>
#include<algorithm>
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Player
{
	PlayerController::PlayerController()
	{
		player_view = new PlayerView();
		player_model = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete (player_view);
		delete (player_model);
	}
	
	void PlayerController::initialize()
	{
		player_model->initialize();
		
		player_view->initialize(this);
	}

	void PlayerController::update()
	{
		processPlayerInput();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}	

	sf::Vector2f PlayerController::getPlayerPosition() const
	{
		return player_model->getPlayerPosition();
	}

	void PlayerController::processPlayerInput()
	{
		const Event::EventService* event_service = Global::ServiceLocator::getInstance()->getEventService();
		
		if (event_service->pressedLeftKey() || event_service->pressedAKey())
		{
			moveLeft();
		}
		if (event_service->pressedRightKey() || event_service->pressedDKey())
		{
			moveRight();
		}

		if (event_service->pressedLeftMouseButton())
			fireBullet();
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x -= player_model->player_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, player_model->left_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x += player_model->player_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, player_model->right_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::fireBullet()
	{
		Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::PLAYER_BULLET,
			player_model->getPlayerPosition() + player_model->barrel_position_offset,
			Bullet::MovementDirection::UP);
	}
}
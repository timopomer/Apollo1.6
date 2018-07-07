#pragma once

#include "MemoryManager.h"
#include "constants.h"
#include "Coordinates.h"
#include "View.h"
#include <memory>


class Player
{
private:
	std::shared_ptr<MemoryManager> m_manager;
public:
	Player() = delete;
	Player(std::shared_ptr<MemoryManager> manager);
	~Player() = default;
	
	Coordinates GetCoordinates();
	View GetView();
};


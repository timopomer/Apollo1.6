#pragma once

#include "MemoryManager.h"
#include "constants.h"
#include "Coordinates.h"
#include <memory>

class Enemy
{
private:
	int m_offset;
	std::shared_ptr<MemoryManager> m_manager;
public:
	Enemy() = delete;
	Enemy(int enemyNumber, std::shared_ptr<MemoryManager> manager);
	~Enemy() = default;

	Coordinates GetCoordinates();
	bool IsAlive();
};


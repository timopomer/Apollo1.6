#pragma once
#include "MemoryManager.h"
#include "constants.h"
#include "Coordinates.h"
#include <memory>
#include <iomanip>

class Enemy
{
private:
	const int m_offset;
	const std::shared_ptr<MemoryManager> m_manager;
public:
	Enemy() = delete;
	Enemy(const int& enemyNumber, const std::shared_ptr<MemoryManager>& manager);
	~Enemy() = default;

	const Coordinates GetCoordinates() const;
	const bool IsAlive() const;
	friend std::ostream& operator <<(std::ostream& outputStream, const Enemy& enemy);

};


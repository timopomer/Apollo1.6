#pragma once
#include <memory>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "MemoryManager.h"
#include "constants.h"
#include <ostream>    
#include <iomanip>


class Hack
{
private:
	std::unique_ptr<Player> m_player;
	std::unique_ptr<std::vector<std::shared_ptr<Enemy>>> m_enemies;
public:
	Hack(const std::shared_ptr<MemoryManager>& manager);
	Hack() = delete;
	~Hack() = default;

	friend std::ostream& operator <<(std::ostream& outputStream, const Hack& hack);
};


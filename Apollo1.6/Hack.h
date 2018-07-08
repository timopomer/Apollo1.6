#pragma once
#include <memory>
#include <vector>
#include <ostream>    
#include <iomanip>
#include <thread>
#include <algorithm>
#include "Enemy.h"
#include "Player.h"
#include "MemoryManager.h"
#include "constants.h"


class Hack
{
private:
	std::unique_ptr<Player> m_player;
	std::unique_ptr<std::vector<std::shared_ptr<Enemy>>> m_enemies;
	std::unique_ptr<std::thread> m_aimbotThread;
	std::unique_ptr<std::thread> m_enemyResetThread;
	void startAimbot();
	void startEnemyReset();
	std::unique_ptr<std::vector<std::shared_ptr<Enemy>>> aliveEnemies() const;
public:
	Hack(const std::shared_ptr<MemoryManager>& manager);
	Hack() = delete;
	~Hack() = default;
	void Start();
	void Stop();

	friend std::ostream& operator <<(std::ostream& outputStream, const Hack& hack);
};


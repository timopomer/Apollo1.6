#pragma once
#include <memory>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "MemoryManager.h"
#include "constants.h"
#include <ostream>    
#include <iomanip>
#include <thread>


class Hack
{
private:
	std::unique_ptr<Player> m_player;
	std::unique_ptr<std::vector<std::shared_ptr<Enemy>>> m_enemies;
	std::unique_ptr<std::thread> m_aimbotThread;
	void startAimbot();
public:
	Hack(const std::shared_ptr<MemoryManager>& manager);
	Hack() = delete;
	~Hack() = default;
	void Start();
	void Stop();

	friend std::ostream& operator <<(std::ostream& outputStream, const Hack& hack);
};


#include "Hack.h"


void Hack::startAimbot()
{
	while (true)
	{
		auto aliveEnemies = this->aliveEnemies();
		auto it = std::min_element
		(
			aliveEnemies->begin(),
			aliveEnemies->end(),
			[&](std::shared_ptr<Enemy>& enemy1, std::shared_ptr<Enemy>& enemy2) {  return this->m_player->DistanceTo(enemy1) < this->m_player->DistanceTo(enemy2); }
		);
		if (it != aliveEnemies->end())
			this->m_player->AimAt(*it);
	}
}
void Hack::startEnemyReset()
{
	while (true)
	{
		for (auto& enemy : *this->m_enemies)
		{
			enemy->Reset();
		}
		Sleep(ENEMY_RESET_INTERVAL);
	}
}

std::unique_ptr<std::vector<std::shared_ptr<Enemy>>> Hack::aliveEnemies() const
{
	auto existing = std::make_unique<std::vector<std::shared_ptr<Enemy>>>();
	for (auto& enemy : *this->m_enemies)
	{
		if (enemy->IsAlive())
			existing->push_back(enemy);
	}
	return existing;
}


Hack::Hack(const std::shared_ptr<MemoryManager>& manager) :
	m_player(std::make_unique<Player>(manager)),
	m_enemies(std::make_unique<std::vector<std::shared_ptr<Enemy>>>())
{
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		this->m_enemies->push_back(std::make_shared<Enemy>(i, manager));
	}
}

void Hack::Start()
{
	this->m_aimbotThread = std::make_unique<std::thread>(&Hack::startAimbot, this);
	this->m_enemyResetThread = std::make_unique<std::thread>(&Hack::startEnemyReset, this);
}

void Hack::Stop()
{
	this->m_aimbotThread->join();
	this->m_enemyResetThread->join();
}


std::ostream& operator<<(std::ostream &outputStream, const Hack& hack)
{
	outputStream << "Player:" << std::endl;
	outputStream << *hack.m_player << std::endl;
	outputStream << std::endl;

	outputStream << "Enemies:" << std::endl;
	auto enemies = hack.aliveEnemies();
	for (auto const& enemy : *enemies)
	{
		outputStream << *enemy << std::endl;
	}
		
	return outputStream;
}

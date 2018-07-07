#include "Enemy.h"


Enemy::Enemy(int enemyNumber, std::shared_ptr<MemoryManager> manager) :
	m_offset(enemyNumber * ENEMY_NUMBER_MULTIPLICATION_OFFSET),
	m_manager(manager)
{}

Coordinates Enemy::GetCoordinates()
{
	Coordinates coords{};
	this->m_manager->ReadMemory(HWDLL, ENEMY_BASE + this->m_offset + ENEMY_COORDINATE_OFFSET, &coords);
	return coords;
}

bool Enemy::IsAlive()
{
	bool isAlive;
	this->m_manager->ReadMemory(HWDLL, ENEMY_BASE + this->m_offset + ENEMY_ALIVE_OFFSET, &isAlive);
	return isAlive;
}


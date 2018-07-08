#include "Enemy.h"


Enemy::Enemy(int enemyNumber, std::shared_ptr<MemoryManager> manager) :
	m_offset(enemyNumber * ENEMY_NUMBER_MULTIPLICATION_OFFSET),
	m_manager(manager)
{}

const Coordinates Enemy::GetCoordinates() const
{
	Coordinates coords{};
	this->m_manager->ReadMemory(HWDLL, ENEMY_BASE + this->m_offset + ENEMY_COORDINATE_OFFSET, &coords);
	return coords;
}

const bool Enemy::IsAlive() const
{
	bool isAlive;
	this->m_manager->ReadMemory(HWDLL, ENEMY_BASE + this->m_offset + ENEMY_ALIVE_OFFSET, &isAlive);
	return isAlive;
}

std::ostream & operator<<(std::ostream &outputStream, const Enemy &enemy)
{
	outputStream << "x: " << std::setw(10) << enemy.GetCoordinates().x;
	outputStream << " y: " << std::setw(10) << enemy.GetCoordinates().y;
	outputStream << " z: " << std::setw(10) << enemy.GetCoordinates().z;
	outputStream << " alive: " << std::boolalpha << std::setw(10) << enemy.IsAlive();
	return outputStream;
}

#include "Player.h"

Coordinates Player::GetCoordinates()
{
	Coordinates coords{};
	this->m_manager->ReadMemory(HWDLL, PLAYER_BASE + PLAYER_COORDINATE_OFFSET, &coords);
	return coords;
}

View Player::GetView()
{
	View view{};
	this->m_manager->ReadMemory(HWDLL, PLAYER_VIEW_OFFSET, &view);
	return view;
}

Player::Player(std::shared_ptr<MemoryManager> manager) :
	m_manager(manager)
{}

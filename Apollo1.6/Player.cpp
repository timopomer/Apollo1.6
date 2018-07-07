#include "Player.h"



Coordinates Player::GetCoordinates()
{
	Coordinates coords{};
	this->m_manager->ReadMemory(HWDLL, PLAYER_OFFSET + PLAYER_COORDINATE_OFFSET, &coords);
	return coords;
}

View Player::GetView()
{
	View view{};
	this->m_manager->ReadMemory(HWDLL, PLAYER_VIEW_OFFSET, &view);
	return view;
}

Player::Player(std::unique_ptr<MemoryManager> manager) :
	m_manager(std::move(manager))
{
}


Player::~Player()
{
}

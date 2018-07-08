#include "Player.h"


const Coordinates Player::GetCoordinates() const
{
	Coordinates coords{};
	this->m_manager->ReadMemory(HWDLL, PLAYER_BASE + PLAYER_COORDINATE_OFFSET, &coords);
	return coords;
}

const View Player::GetView() const
{
	View view{};
	this->m_manager->ReadMemory(HWDLL, PLAYER_VIEW_OFFSET, &view);
	return view;
}

Player::Player(const std::shared_ptr<MemoryManager>& manager) :
	m_manager(manager)
{}

std::ostream& operator<<(std::ostream& outputStream, const Player& player)
{
	outputStream << "x:     " << std::setw(15) << player.GetCoordinates().x << std::endl;
	outputStream << "y:     " << std::setw(15) << player.GetCoordinates().y << std::endl;
	outputStream << "z:     " << std::setw(15) << player.GetCoordinates().z << std::endl;
	outputStream << "pitch: " << std::setw(15) << player.GetView().pitch << std::endl;
	outputStream << "yaw:   " << std::setw(15) << player.GetView().yaw;
	return outputStream;
}

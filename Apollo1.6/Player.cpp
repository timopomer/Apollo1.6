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

const double Player::DistanceTo(std::shared_ptr<Enemy>& enemy) const
{
	Coordinates playerCoords = this->GetCoordinates();
	Coordinates enemyCoords = enemy->GetCoordinates();

	double diffX = std::abs(enemyCoords.x - playerCoords.x);
	double diffY = std::abs(enemyCoords.y - playerCoords.y);
	double diffZ = std::abs(enemyCoords.z - playerCoords.z);

	// 3d vector distance
	double dist2d = sqrt(pow(diffX, 2) + pow(diffY, 2));
	double dist3d = sqrt(pow(dist2d, 2) + pow(diffZ, 2));

	return dist3d;
}

void Player::AimAt(std::shared_ptr<Enemy>& enemy) const
{
	Coordinates playerCoords = this->GetCoordinates();
	Coordinates enemyCoords = enemy->GetCoordinates();

	double diffX = std::abs(enemyCoords.x - playerCoords.x);
	double diffY = std::abs(enemyCoords.y - playerCoords.y);
	double diffZ = std::abs(enemyCoords.z - playerCoords.z);

	// 3d vector distance
	double dist2d = sqrt(pow(diffX, 2) + pow(diffY, 2));
	double dist3d = sqrt(pow(dist2d, 2) + pow(diffZ, 2));

	double aXt = 90 - ((180 / M_PI) * atan(diffY / diffX));

	double aYt = (180 / M_PI) * atan(diffZ / dist2d);

	float targetYaw = 0;

	if (enemyCoords.x < playerCoords.x && playerCoords.y < enemyCoords.y)
	{
		targetYaw = (float)(360 - aXt);
	}

	if (playerCoords.x < enemyCoords.x  && playerCoords.y <  enemyCoords.y)
	{
		targetYaw = (float)(aXt);
	}

	if (enemyCoords.x < playerCoords.x &&  enemyCoords.y < playerCoords.y)
	{
		targetYaw = (float)(180 + aXt);
	}

	if (playerCoords.x < enemyCoords.x &&  enemyCoords.y < playerCoords.y)
	{
		targetYaw = (float)(180 - aXt);
	}

	View targetView{ aYt, targetYaw };
	this->ChangeView(targetView);
}

void Player::ChangeView(const View& view) const
{
	this->m_manager->WriteMemory(HWDLL, PLAYER_VIEW_OFFSET, &view);
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

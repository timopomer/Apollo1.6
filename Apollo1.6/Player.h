#pragma once
#include "MemoryManager.h"
#include "constants.h"
#include "Coordinates.h"
#include "View.h"
#include "Enemy.h"
#include <memory>
#include <iomanip>



class Player
{
private:
	const std::shared_ptr<MemoryManager> m_manager;
	void ChangeView(const View& view) const;
public:
	Player() = delete;
	Player(const std::shared_ptr<MemoryManager>& manager);
	~Player() = default;
	
	const Coordinates GetCoordinates() const;
	const View GetView() const;
	const double DistanceTo(std::shared_ptr<Enemy>& enemy) const;
	void AimAt(std::shared_ptr<Enemy>& enemy) const;

	friend std::ostream& operator <<(std::ostream& outputStream, const Player& player);
};


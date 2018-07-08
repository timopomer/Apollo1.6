#pragma once
#include "MemoryManager.h"
#include "constants.h"
#include "Coordinates.h"
#include "View.h"
#include <memory>
#include <iomanip>


class Player
{
private:
	const std::shared_ptr<MemoryManager> m_manager;
public:
	Player() = delete;
	Player(std::shared_ptr<MemoryManager> manager);
	~Player() = default;
	
	const Coordinates GetCoordinates() const;
	const View GetView() const;
	friend std::ostream& operator <<(std::ostream& outputStream, const Player& player);

};


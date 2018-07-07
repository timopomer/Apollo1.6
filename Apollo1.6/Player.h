#pragma once
#include "MemoryManager.h"
#include "constants.h"
#include <memory>

struct Coordinates
{
	float y;
	float x;
	float z;
};

struct View
{
	float pitch;	//Y axis
	float yaw;		//X axis
};

class Player
{
private:
	std::unique_ptr<MemoryManager> m_manager;
public:
	Player() = delete;
	Player(std::unique_ptr<MemoryManager> manager);
	~Player();
	
	Coordinates GetCoordinates();
	View GetView();
};


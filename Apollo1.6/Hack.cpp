#include "Hack.h"


void Hack::startAimbot()
{
	while (true)
	{

	}
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
}

void Hack::Stop()
{
	this->m_aimbotThread->join();
}


std::ostream& operator<<(std::ostream &outputStream, const Hack& hack)
{
	outputStream << "Player:" << std::endl;
	outputStream << *hack.m_player << std::endl;
	outputStream << std::endl;

	outputStream << "Enemies:" << std::endl;
	for (auto const& enemy : *hack.m_enemies)
	{
		outputStream << *enemy << std::endl;
	}
		
	return outputStream;
}

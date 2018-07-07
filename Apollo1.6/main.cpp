#include "main.h"

int main()
{
	HWND hGameWindow = FindWindow(NULL, CSTRIKE_WINDOW_NAME);
	DWORD dwProcId = NULL;

	if (hGameWindow == 0)
	{
		throw std::exception("Couldnt get window hwnd");
	}
	
	GetWindowThreadProcessId(hGameWindow, &dwProcId);
	//If it is a valid id we continue to try and open the process

	if (dwProcId == 0)
	{
		throw std::exception("Couldnt get process id");
	}

	std::unique_ptr<MemoryManager> manager = std::make_unique<MemoryManager>(dwProcId);
	std::unique_ptr<Player> player = std::make_unique<Player>(std::move(manager));

	for (;;)
	{
		std::cout << "x:      " << player->GetCoordinates().x << std::endl;
		std::cout << "y:      " << player->GetCoordinates().y << std::endl;
		std::cout << "z:      " << player->GetCoordinates().z << std::endl;
		std::cout << "pitch:  " << player->GetView().pitch << std::endl;
		std::cout << "yaw:    " << player->GetView().yaw << std::endl;
		Sleep(100);

		system("cls");
	}
	return 0;
}
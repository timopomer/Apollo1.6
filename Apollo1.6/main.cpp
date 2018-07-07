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

	std::shared_ptr<MemoryManager> manager = std::make_shared<MemoryManager>(dwProcId);
	std::unique_ptr<Player> player = std::make_unique<Player>(manager);
	std::unique_ptr<Enemy> enemy0 = std::make_unique<Enemy>(0, manager);

	for (;;)
	{
		std::cout << "x:        " << player->GetCoordinates().x << std::endl;
		std::cout << "y:        " << player->GetCoordinates().y << std::endl;
		std::cout << "z:        " << player->GetCoordinates().z << std::endl;
		std::cout << "pitch:    " << player->GetView().pitch << std::endl;
		std::cout << "yaw:      " << player->GetView().yaw << std::endl;
		std::cout << "en1 x:    " << enemy0->GetCoordinates().x << std::endl;
		std::cout << "en1 y:    " << enemy0->GetCoordinates().y << std::endl;
		std::cout << "en1 z:    " << enemy0->GetCoordinates().z << std::endl;
		std::cout << "en1 alive:" << std::boolalpha << enemy0->IsAlive() << std::endl;
		Sleep(100);

		system("cls");
	}
	return 0;
}
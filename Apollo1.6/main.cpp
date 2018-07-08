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
	std::unique_ptr<Hack> hack = std::make_unique<Hack>(manager);

	for (;;)
	{
		std::cout << *hack;
		Sleep(10);

		system("cls");
	}
	return 0;
}
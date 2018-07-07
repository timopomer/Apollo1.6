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
	for (;;)
	{
		float res = 0;
		std::cout << manager->ReadMemory(HWDLL, 0x1AFFA8, &res);
		Sleep(100);

		system("cls");
	}
	return 0;
}
#include "MemoryManager.h"


MemoryManager::MemoryManager(DWORD dwProcId) :
	m_hProcHandle(OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcId)),
	m_dwProcId(dwProcId)
{}

MemoryManager::~MemoryManager()
{}



const DWORD MemoryManager::getAddress(const LPCSTR &moduleName)
{
	if (this->m_modules.count(moduleName) == 0)
	{
		this->m_modules[moduleName] = this->dwGetModuleBaseAddress(moduleName);
	}
	return this->m_modules[moduleName];
}

const DWORD_PTR MemoryManager::dwGetModuleBaseAddress(const TCHAR *szModuleName)
{
	DWORD_PTR dwModuleBaseAddress = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, this->m_dwProcId);
	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 ModuleEntry32;
		ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &ModuleEntry32))
		{
			do
			{
				if (_tcsicmp(ModuleEntry32.szModule, szModuleName) == 0)
				{
					dwModuleBaseAddress = (DWORD_PTR)ModuleEntry32.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnapshot, &ModuleEntry32));
		}
		CloseHandle(hSnapshot);
	}
	return dwModuleBaseAddress;
}

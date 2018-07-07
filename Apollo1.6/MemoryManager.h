#pragma once
#include <windows.h>
#include <map>
#include <tlhelp32.h>
#include <tchar.h>

class MemoryManager
{
private:
	HANDLE m_hProcHandle;
	DWORD m_dwProcId;
	std::map<LPCSTR, DWORD> m_modules;
	DWORD getAddress(const LPCSTR &moduleName);
	DWORD_PTR dwGetModuleBaseAddress(const TCHAR *szModuleName);

public:
	MemoryManager() = delete;
	MemoryManager(const DWORD dwProcId);
	~MemoryManager();


	template <typename T>
	T ReadMemory(const LPCSTR &moduleName, const int offset, T *result)
	{
		DWORD BaseAddress = (DWORD)(this->getAddress(moduleName) + offset);
		BOOL success = ReadProcessMemory(this->m_hProcHandle, (LPCVOID)BaseAddress, result, sizeof(T), NULL);
		return *result;
	}
};


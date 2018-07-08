#pragma once
#include <windows.h>
#include <map>
#include <tlhelp32.h>
#include <tchar.h>


class MemoryManager
{
private:
	const HANDLE m_hProcHandle;
	const DWORD m_dwProcId;
	std::map<LPCSTR, DWORD> m_modules;
	const DWORD getAddress(const LPCSTR &moduleName);
	const DWORD_PTR dwGetModuleBaseAddress(const TCHAR *szModuleName);

public:
	MemoryManager() = delete;
	MemoryManager(const DWORD dwProcId);
	~MemoryManager();

	template <typename T>
	T ReadMemory(const LPCSTR &moduleName, const int& offset, T *result)
	{
		DWORD BaseAddress = (DWORD)(this->getAddress(moduleName) + offset);
		BOOL success = ReadProcessMemory(this->m_hProcHandle, (LPCVOID)BaseAddress, result, sizeof(T), NULL);
		//todo: throw exception on failure
		return *result;
	}

	template <typename T>
	void WriteMemory(const LPCSTR &moduleName, const int& offset, T *towrite)
	{
		DWORD BaseAddress = (DWORD)(this->getAddress(moduleName) + offset);
		BOOL success = WriteProcessMemory(this->m_hProcHandle, (LPVOID)BaseAddress, towrite, sizeof(T), NULL);
		//todo: throw exception on failure
	}

	template <typename T>
	void NullMemory(const LPCSTR &moduleName, const int& offset)
	{
		T nulledMemory = T{ 0 };
		this->WriteMemory(moduleName, offset, &nulledMemory);
		//todo: throw exception on failure
	}
};


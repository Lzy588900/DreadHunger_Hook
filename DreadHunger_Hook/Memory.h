#pragma once
#include <windows.h>
#include <iostream>

using namespace std;
class Memory
{
public:
	
	HANDLE ��Ϸ���̾��;
	template<typename Type>
	Type ReadData(uintptr_t Base)
	{
		Type data = NULL;
		ReadProcessMemory(��Ϸ���̾��, (LPVOID)Base, &data, sizeof(Type), NULL);

		return data;
	}
	string ReadBuffer( uint64_t Address, uint16_t Length);
	string GetObjectName(uint32_t obj_id,  uintptr_t base);

};




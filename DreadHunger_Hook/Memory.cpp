#include "Memory.h"
string Memory::ReadBuffer(uint64_t Address, uint16_t Length)
{
	byte* buffer = new byte[Length];
	//SIZE_T bytesRead;
	ReadProcessMemory(游戏进程句柄, (LPVOID)Address, buffer, Length, NULL);
	//byte* i=ReadData<byte*>(游戏进程句柄, Address);
	//string str = (char*)buffer;
	char* p = new char[Length];
	memcpy(p, buffer, Length);
	p[Length] = 0;
	string str(p);
	return str;
}
string Memory::GetObjectName(uint32_t obj_id, uintptr_t base)
{
	uint32_t TableLocation = obj_id >> 16;
	uint16_t RowLocation = uint16_t(obj_id);
	uint64_t TableLocationAddress = ReadData<uint64_t>(base + 0x4AFD180 + 0x10 + 0x8 * TableLocation);
	TableLocationAddress = TableLocationAddress + 2 * RowLocation;
	uint16_t sLength = ReadData<uint16_t>( TableLocationAddress);
	sLength >>= 6;
	if (sLength < 128)
	{
		string str = ReadBuffer(TableLocationAddress + 0x2, sLength);
		return str;
	}
	return "";
}
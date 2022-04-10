#pragma once
#include "includes.h"
#include <psapi.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <iostream>
#include "class.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include <d3d9.h>
#include <dwmapi.h>
#include <vector>
#include "Memory.h"
#include "offset.h"
#include <tchar.h>

HWND hwnd;
void DrawThread();
HWND ��Ϸ���ھ��;
HWND �������ھ��;
unsigned long ��Ϸ����ID;
RECT ��Ϸ���ڷֱ���;
LPCSTR ��Ϸ������ = "UnrealWindow";

uintptr_t Base;
UINT64 Gname;
uintptr_t UWorld;
uintptr_t ULevel;
uint32_t LevelNumber;
uintptr_t Alllevel[20];
uintptr_t AllCount[20];
uintptr_t AllActor[20];
uintptr_t UActor;
uintptr_t UCount;
uintptr_t �����ַ;
uintptr_t �����ַ;
uintptr_t �����ַ1;
Vectors3 ��������;
uintptr_t ����ID;
string ��������;
float matrix[4][4];
ImU32 Drawcolor = ImGui::ColorConvertFloat4ToU32(ImVec4(255 / 255.0, 96 / 255.0, 0 / 255, 255 / 255.0));
Memory* mem = new Memory;
ImDrawList* draw_list;
ImFont* font ;
ImFont* ��������;
vector<string> split(string str, string pattern)
{
	string::size_type pos;
	vector<string> result;
	str += pattern;//��չ�ַ����Է������
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}
�������� ����;
���ʵ����� ��������;
�������� ����;
��������� ��������;
bool ��ʾ��������;
namespace DrawTool {

	void DrawBox(Vectors4 box, int ������, int ����߶�, int color, int thickness)
	{
		draw_list->AddRect(ImVec2(box.x - ������ / 2, box.y + ����߶� / 4), ImVec2(box.x - ������ / 2 + ������, box.y + ����߶� - ����߶� / 4), Drawcolor, 1, 1, thickness);
	}
	void DrawLine(Vectors4 box, int �ӽǿ�, int �ӽǸ�, int ����߶�)
	{
		draw_list->AddLine(ImVec2(�ӽǿ�, �ӽǸ� * 2), ImVec2(box.x, box.y + ����߶� / 2), Drawcolor, 1);
	}
	void DrawText(string name, Vectors4 box, int ����߶�)
	{
		draw_list->AddText(font, 15, ImVec2(box.x, box.y + ����߶� / 2), Drawcolor, name.c_str(), 0, 0, nullptr);
	}
};
int GetModules(DWORD processID)
{
	HMODULE hMods[1024];
	HANDLE hProcess;
	DWORD cbNeeded;
	unsigned int i;

	// Print the process identifier.

	//printf("\nProcess ID: %u\n", processID);

	// Get a handle to the process.

	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);
	if (NULL == hProcess)
		return 1;

	// Get a list of all the modules in this process.

	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			TCHAR szModName[MAX_PATH];

			// Get the full path to the module's file.

			if (GetModuleFileNameEx(hProcess, hMods[i], szModName,
				sizeof(szModName) / sizeof(TCHAR)))
			{
				// Print the module name and handle value.

				//_tprintf(TEXT("\t%s (0x%08x)\n"), szModName, hMods[i]);
			}
		}
	}

	// Release the handle to the process.

	CloseHandle(hProcess);
	Base = reinterpret_cast<uintptr_t>(hMods[0]);

	return 0;
}
void GetViewmatrix() {
	int ViewmatrixIndex = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = mem->ReadData<float>(�����ַ1 + ViewmatrixIndex * 0x4);
			ViewmatrixIndex++;
			//	printf("%f\t\t", matrix[i][j]);
			
		}
		
		//printf("\n");
	}
	//Sleep(50);
	//system("cls");
}
void ��������(string name,Vectors4 box,int ����߶�)
{
	if (����.������ && name == ��������.������)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.������ && name == ��������.������)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.������ && name == ��������.������)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.ҽ���� && name == ��������.ҽ����)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.��Ĺ && name == ��������.��Ĺ)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.��ҩ�� && name == ��������.��ҩ��)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.ú̿ѩ�� && name == ��������.ú̿ѩ��1 | name == ��������.ú̿ѩ��2)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.���� && name == ��������.����)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.���� && name == ��������.����1 | name == ��������.����2 | name == ��������.����3)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}

}
void ���ƶ���(string name, Vectors4 box, int ����߶�)
{
	if (����.������ && name == ��������.������)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.������ && name == ��������.������)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.������ && name == ��������.������)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.ҽ���� && name == ��������.ҽ����)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.��Ĺ && name == ��������.��Ĺ)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.��ҩ�� && name == ��������.��ҩ��)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.ú̿ѩ�� && name == ��������.ú̿ѩ��1 | name == ��������.ú̿ѩ��2)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.���� && name == ��������.����)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}
	if (����.���� && name == ��������.����1 | name == ��������.����2 | name == ��������.����3)
	{
		DrawTool::DrawTextA(name, box, ����߶�);
	}

}
void DrawThread()
{

	GetViewmatrix();
	int ���ڿ�� = ��Ϸ���ڷֱ���.right - ��Ϸ���ڷֱ���.left;
	int ���ڸ߶� = ��Ϸ���ڷֱ���.bottom - ��Ϸ���ڷֱ���.top;
	int ����; int ����߶�; int ������;
	int �ӽǿ� = ���ڿ�� / 2;
	int �ӽǸ� = ���ڸ߶� / 2;

	
	Vectors4 box;
	if (UWorld > 0)
	{
		for (int m_levelIndex = 0; m_levelIndex < LevelNumber; m_levelIndex++)
		{
			for (int i = 0; i < AllCount[m_levelIndex]; i++)
			{
				�����ַ = mem->ReadData<UINT64>(AllActor[m_levelIndex] + (i - 1) * 8);
				//cout << "�����ַ=" << �����ַ << endl;
				//printf("�����ַ=%p\n", �����ַ);
				if (�����ַ > 0)
				{
					
					����ID = mem->ReadData<DWORD>(�����ַ + 0x18);
					string name = mem->GetObjectName(����ID, Base);
					��������.x = mem->ReadData<float>((mem->ReadData<UINT64>(�����ַ + 0x130) + 0x1D0));
					��������.y = mem->ReadData<float>((mem->ReadData<UINT64>(�����ַ + 0x130) + 0x1D4));
					��������.z = mem->ReadData<float>((mem->ReadData<UINT64>(�����ַ + 0x130) + 0x1D8));
					//printf("obj_Addres=%p,x=%f,y=%f,z=%f\n", �����ַ, ��������.x, ��������.y, ��������.z);

					box.w = (��������.x * matrix[0][3]) + (��������.y * matrix[1][3]) + (��������.z * matrix[2][3]) + matrix[3][3];
					���� = box.w / 100;

					if (box.w > 0.01)
					{
						box.x = �ӽǿ� + (��������.x * matrix[0][0] + ��������.y * matrix[1][0] + ��������.z * matrix[2][0] + matrix[3][0]) / box.w * �ӽǿ�;
						box.y = �ӽǸ� - (��������.x * matrix[0][1] + ��������.y * matrix[1][1] + (��������.z + 100) * matrix[2][1] + matrix[3][1]) / box.w * �ӽǸ�;
						box.w = �ӽǸ� - (��������.x * matrix[0][1] + ��������.y * matrix[1][1] + (��������.z - 100) * matrix[2][1] + matrix[3][1]) / box.w * �ӽǸ�;
						����߶� = box.w - box.y;
						������ = ����߶� / 2;
						����߶� = box.w - box.y;
						������ = ����߶� / 2;
					
						if (��ʾ��������)
						{
							DrawTool::DrawTextA(name, box, ����߶�);
							continue;
						}

						��������(name,box,����߶�);
							
						



						}
					
					}
				}

			}
		}
	}
void DrawMenu()
{
	ImGui::Begin(u8"�������ԡ�Home������/��ʾ");
	ImGui::SetWindowSize(ImVec2(350, 400), 0);
	ImGui::Checkbox(u8"��ʾ��������", &��ʾ��������);
	if (ImGui::CollapsingHeader(u8"��������"))
	{
		ImGui::Checkbox(u8"������", &����.������);
		ImGui::SameLine();
		ImGui::Checkbox(u8"������", &����.������);
		ImGui::SameLine();
		ImGui::Checkbox(u8"������", &����.������);

		ImGui::Checkbox(u8"ҽ����", &����.ҽ����);
		ImGui::SameLine();
		ImGui::Checkbox(u8"ú̿ѩ��", &����.ú̿ѩ��);
		ImGui::SameLine();
		ImGui::Checkbox(u8"��Ĺ", &����.��Ĺ);

		ImGui::Checkbox(u8"��ҩ��", &����.��ҩ��); 
		ImGui::SameLine();
		ImGui::Checkbox(u8"����", &����.����);
		ImGui::SameLine();
		ImGui::Checkbox(u8"����", &����.����);

	}
	if (ImGui::CollapsingHeader(u8"��������"))
	{
		ImGui::Checkbox(u8"����", &����.����);
		ImGui::SameLine();
		ImGui::Checkbox(u8"����", &����.����);
		ImGui::SameLine();
		ImGui::Checkbox(u8"��", &����.��);
		ImGui::SameLine();
		ImGui::Checkbox(u8"��", &����.��);
		ImGui::SameLine();
		ImGui::Checkbox(u8"ʳʬ��", &����.ʳʬ��);
		
	}
	ImGui::CollapsingHeader(u8"�������");
	ImGui::CollapsingHeader(u8"��������");
	ImGui::CollapsingHeader(u8"��������");
	//��Ҫ���ƴ���
	//��������
	ImGui::End();
}
bool Initdata(HWND hwnd)
{
	/*AllocConsole();
	freopen("CON", "w", stdout);*/

	GetWindowThreadProcessId(hwnd, &��Ϸ����ID);
	mem->��Ϸ���̾�� = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ��Ϸ����ID);
	GetModules(��Ϸ����ID);
	cout << "initdata" << endl;
	return true;
}
void updataAddress(HWND hwnd)
{
	 GetWindowRect(hwnd, &��Ϸ���ڷֱ���);
	UWorld = mem->ReadData<UINT64>(Base + offsets::GWorld);
	/*ULevel = ReadData<UINT64>(��Ϸ���̾��, UWorld + offsets::GLevel);*/
	ULevel = mem->ReadData<UINT64>(UWorld + 0x138);
	LevelNumber = mem->ReadData<UINT64>(UWorld + 0x138 + 8);
	UActor = mem->ReadData<UINT64>(ULevel + offsets::GActor);
	UCount = mem->ReadData<DWORD>(ULevel + offsets::GCount);
	�����ַ = mem->ReadData<UINT64>(Base + 0x0486BBB0);
	�����ַ1 = mem->ReadData<UINT64>(�����ַ + 0x20) + 0x280;
	//cout << LevelNumber << endl;
	//AllCount[0] = mem->ReadData<DWORD>(ULevel = mem->ReadData<UINT64>(UWorld + 0x30) + 0xA0);
	//AllActor[0] = mem->ReadData<UINT64>(ULevel = mem->ReadData<UINT64>(UWorld + 0x30) + 0x98);
	for (int i = 0; i < LevelNumber; i++)
	{
		Alllevel[i] = mem->ReadData<UINT64>(ULevel + i * 0x8);
		AllCount[i] = mem->ReadData<DWORD>(Alllevel[i] + 0xA0);
		AllActor[i] = mem->ReadData<UINT64>(Alllevel[i] + 0x98);
		//printf("ULevel=%p,count=%d,Actor=%u\n", Alllevel[i], AllCount[i], AllActor[i]);
		//cout << "ULevel=" << Alllevel[i]<<"count="<< AllCount[i]<<"Actor="<< AllActor[i]<<endl;
		
	}
	//system("cls");
}

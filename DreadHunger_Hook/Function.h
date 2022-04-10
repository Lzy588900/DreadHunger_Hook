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
HWND 游戏窗口句柄;
HWND 辅助窗口句柄;
unsigned long 游戏进程ID;
RECT 游戏窗口分辨率;
LPCSTR 游戏窗口类 = "UnrealWindow";

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
uintptr_t 对象地址;
uintptr_t 矩阵地址;
uintptr_t 矩阵地址1;
Vectors3 对象坐标;
uintptr_t 对象ID;
string 对象名字;
float matrix[4][4];
ImU32 Drawcolor = ImGui::ColorConvertFloat4ToU32(ImVec4(255 / 255.0, 96 / 255.0, 0 / 255, 255 / 255.0));
Memory* mem = new Memory;
ImDrawList* draw_list;
ImFont* font ;
ImFont* 内容字体;
vector<string> split(string str, string pattern)
{
	string::size_type pos;
	vector<string> result;
	str += pattern;//扩展字符串以方便操作
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
物资设置 物资;
物资的名字 物资名字;
动物设置 动物;
动物的名字 动物名字;
bool 显示所有名字;
namespace DrawTool {

	void DrawBox(Vectors4 box, int 方框宽度, int 方框高度, int color, int thickness)
	{
		draw_list->AddRect(ImVec2(box.x - 方框宽度 / 2, box.y + 方框高度 / 4), ImVec2(box.x - 方框宽度 / 2 + 方框宽度, box.y + 方框高度 - 方框高度 / 4), Drawcolor, 1, 1, thickness);
	}
	void DrawLine(Vectors4 box, int 视角宽, int 视角高, int 方框高度)
	{
		draw_list->AddLine(ImVec2(视角宽, 视角高 * 2), ImVec2(box.x, box.y + 方框高度 / 2), Drawcolor, 1);
	}
	void DrawText(string name, Vectors4 box, int 方框高度)
	{
		draw_list->AddText(font, 15, ImVec2(box.x, box.y + 方框高度 / 2), Drawcolor, name.c_str(), 0, 0, nullptr);
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
			matrix[i][j] = mem->ReadData<float>(矩阵地址1 + ViewmatrixIndex * 0x4);
			ViewmatrixIndex++;
			//	printf("%f\t\t", matrix[i][j]);
			
		}
		
		//printf("\n");
	}
	//Sleep(50);
	//system("cls");
}
void 绘制物资(string name,Vectors4 box,int 方框高度)
{
	if (物资.物资箱 && name == 物资名字.物资箱)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.保险箱 && name == 物资名字.保险箱)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.储藏室 && name == 物资名字.储藏室)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.医生包 && name == 物资名字.医生包)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.坟墓 && name == 物资名字.坟墓)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.弹药箱 && name == 物资名字.弹药箱)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.煤炭雪橇 && name == 物资名字.煤炭雪橇1 | name == 物资名字.煤炭雪橇2)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.背包 && name == 物资名字.背包)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.骷髅 && name == 物资名字.骷髅1 | name == 物资名字.骷髅2 | name == 物资名字.骷髅3)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}

}
void 绘制动物(string name, Vectors4 box, int 方框高度)
{
	if (物资.物资箱 && name == 物资名字.物资箱)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.保险箱 && name == 物资名字.保险箱)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.储藏室 && name == 物资名字.储藏室)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.医生包 && name == 物资名字.医生包)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.坟墓 && name == 物资名字.坟墓)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.弹药箱 && name == 物资名字.弹药箱)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.煤炭雪橇 && name == 物资名字.煤炭雪橇1 | name == 物资名字.煤炭雪橇2)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.背包 && name == 物资名字.背包)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}
	if (物资.骷髅 && name == 物资名字.骷髅1 | name == 物资名字.骷髅2 | name == 物资名字.骷髅3)
	{
		DrawTool::DrawTextA(name, box, 方框高度);
	}

}
void DrawThread()
{

	GetViewmatrix();
	int 窗口宽度 = 游戏窗口分辨率.right - 游戏窗口分辨率.left;
	int 窗口高度 = 游戏窗口分辨率.bottom - 游戏窗口分辨率.top;
	int 距离; int 方框高度; int 方框宽度;
	int 视角宽 = 窗口宽度 / 2;
	int 视角高 = 窗口高度 / 2;

	
	Vectors4 box;
	if (UWorld > 0)
	{
		for (int m_levelIndex = 0; m_levelIndex < LevelNumber; m_levelIndex++)
		{
			for (int i = 0; i < AllCount[m_levelIndex]; i++)
			{
				对象地址 = mem->ReadData<UINT64>(AllActor[m_levelIndex] + (i - 1) * 8);
				//cout << "对象地址=" << 对象地址 << endl;
				//printf("对象地址=%p\n", 对象地址);
				if (对象地址 > 0)
				{
					
					对象ID = mem->ReadData<DWORD>(对象地址 + 0x18);
					string name = mem->GetObjectName(对象ID, Base);
					对象坐标.x = mem->ReadData<float>((mem->ReadData<UINT64>(对象地址 + 0x130) + 0x1D0));
					对象坐标.y = mem->ReadData<float>((mem->ReadData<UINT64>(对象地址 + 0x130) + 0x1D4));
					对象坐标.z = mem->ReadData<float>((mem->ReadData<UINT64>(对象地址 + 0x130) + 0x1D8));
					//printf("obj_Addres=%p,x=%f,y=%f,z=%f\n", 物体地址, 物体坐标.x, 物体坐标.y, 物体坐标.z);

					box.w = (对象坐标.x * matrix[0][3]) + (对象坐标.y * matrix[1][3]) + (对象坐标.z * matrix[2][3]) + matrix[3][3];
					距离 = box.w / 100;

					if (box.w > 0.01)
					{
						box.x = 视角宽 + (对象坐标.x * matrix[0][0] + 对象坐标.y * matrix[1][0] + 对象坐标.z * matrix[2][0] + matrix[3][0]) / box.w * 视角宽;
						box.y = 视角高 - (对象坐标.x * matrix[0][1] + 对象坐标.y * matrix[1][1] + (对象坐标.z + 100) * matrix[2][1] + matrix[3][1]) / box.w * 视角高;
						box.w = 视角高 - (对象坐标.x * matrix[0][1] + 对象坐标.y * matrix[1][1] + (对象坐标.z - 100) * matrix[2][1] + matrix[3][1]) / box.w * 视角高;
						方框高度 = box.w - box.y;
						方框宽度 = 方框高度 / 2;
						方框高度 = box.w - box.y;
						方框宽度 = 方框高度 / 2;
					
						if (显示所有名字)
						{
							DrawTool::DrawTextA(name, box, 方框高度);
							continue;
						}

						绘制物资(name,box,方框高度);
							
						



						}
					
					}
				}

			}
		}
	}
void DrawMenu()
{
	ImGui::Begin(u8"辅助测试“Home”隐藏/显示");
	ImGui::SetWindowSize(ImVec2(350, 400), 0);
	ImGui::Checkbox(u8"显示所有名字", &显示所有名字);
	if (ImGui::CollapsingHeader(u8"物资设置"))
	{
		ImGui::Checkbox(u8"物资箱", &物资.物资箱);
		ImGui::SameLine();
		ImGui::Checkbox(u8"储藏室", &物资.储藏室);
		ImGui::SameLine();
		ImGui::Checkbox(u8"保险箱", &物资.保险箱);

		ImGui::Checkbox(u8"医生包", &物资.医生包);
		ImGui::SameLine();
		ImGui::Checkbox(u8"煤炭雪橇", &物资.煤炭雪橇);
		ImGui::SameLine();
		ImGui::Checkbox(u8"坟墓", &物资.坟墓);

		ImGui::Checkbox(u8"弹药箱", &物资.弹药箱); 
		ImGui::SameLine();
		ImGui::Checkbox(u8"背包", &物资.背包);
		ImGui::SameLine();
		ImGui::Checkbox(u8"骷髅", &物资.骷髅);

	}
	if (ImGui::CollapsingHeader(u8"动物设置"))
	{
		ImGui::Checkbox(u8"兔子", &动物.兔子);
		ImGui::SameLine();
		ImGui::Checkbox(u8"海豹", &动物.海豹);
		ImGui::SameLine();
		ImGui::Checkbox(u8"熊", &动物.熊);
		ImGui::SameLine();
		ImGui::Checkbox(u8"狼", &动物.狼);
		ImGui::SameLine();
		ImGui::Checkbox(u8"食尸鬼", &动物.食尸鬼);
		
	}
	ImGui::CollapsingHeader(u8"玩家设置");
	ImGui::CollapsingHeader(u8"自瞄设置");
	ImGui::CollapsingHeader(u8"特殊设置");
	//主要绘制代码
	//结束绘制
	ImGui::End();
}
bool Initdata(HWND hwnd)
{
	/*AllocConsole();
	freopen("CON", "w", stdout);*/

	GetWindowThreadProcessId(hwnd, &游戏进程ID);
	mem->游戏进程句柄 = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 游戏进程ID);
	GetModules(游戏进程ID);
	cout << "initdata" << endl;
	return true;
}
void updataAddress(HWND hwnd)
{
	 GetWindowRect(hwnd, &游戏窗口分辨率);
	UWorld = mem->ReadData<UINT64>(Base + offsets::GWorld);
	/*ULevel = ReadData<UINT64>(游戏进程句柄, UWorld + offsets::GLevel);*/
	ULevel = mem->ReadData<UINT64>(UWorld + 0x138);
	LevelNumber = mem->ReadData<UINT64>(UWorld + 0x138 + 8);
	UActor = mem->ReadData<UINT64>(ULevel + offsets::GActor);
	UCount = mem->ReadData<DWORD>(ULevel + offsets::GCount);
	矩阵地址 = mem->ReadData<UINT64>(Base + 0x0486BBB0);
	矩阵地址1 = mem->ReadData<UINT64>(矩阵地址 + 0x20) + 0x280;
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

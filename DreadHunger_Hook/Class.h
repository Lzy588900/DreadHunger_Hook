#pragma once
struct Vectors4
{
	float x, y, z, w;
};
struct Vectors3
{
	float x, y, z;
};
struct Vectors2
{
	float x, y;
	int TeamFlag, Healthy;
	int BoxWidth, BoxHeight;
	float Distance;
};
struct 物资设置
{
	bool 物资箱 = false;
	bool 医生包 = false;
	bool 储藏室 = false;
	bool 煤炭雪橇= false;
	bool 背包 = false;
	bool 骷髅 = false;
	bool 弹药箱 = false;
	bool 坟墓 = false;
	bool 保险箱 = false;

};
struct 物资的名字
{
	std::string 物资箱 = "BP_StorageTrunk_Supplies_C";
	std::string 医生包 = "BP_StorageTrunk_Medical_C";
	std::string 储藏室 = "BP_CoveredCrate_Storage_Low_C";

	std::string 煤炭雪橇1= "BP_CoalStorage_Sled_C";
	std::string 煤炭雪橇2 = "BP_CoalStorage_Sled_V2_C";

	std::string 背包 = "";


	std::string 骷髅1 = "BP_Skeleton_Naked_04_C";
	std::string 骷髅2 = "1BP_Skeleton_Naked_04_Snow_C";
	std::string 骷髅3 = "BP_Skeleton_Naked_05_Snow_C";

	std::string 弹药箱 = "BP_StorageTrunk_Ammo_C";
	std::string 坟墓 = "BP_OfficerSkeleton_C";
	std::string 尸体 = "BP_Cannibal_Stirage_8_C";
	std::string 保险箱 = "BP_StrongBox_NoSnow_C";


};
struct 动物设置
{
	bool 海豹 = false;
	bool 狼 = false;
	bool 食尸鬼 = false;
	bool 熊 = false;
	bool 兔子 = false;
};
struct 动物的名字
{
	std::string 海豹 = "BP_Prey_Seal_C";
	std::string 狼 = "BP_Predator_Wolf_C";
	std::string 食尸鬼 = "";
	std::string 熊 = "BP_Predator_Bear_C";
	std::string 兔子 = "'BP_Prey_Rabbit_C";
};
struct 玩家设置
{
	bool 玩家方框 = false;
	
};
struct 玩家的名字
{
	std::string 玩家 = "BP_HumanCharacter_C";

};
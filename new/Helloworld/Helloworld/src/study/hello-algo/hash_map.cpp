#include "basic.h"

int main1()
{
	// 初始化哈希表
	std::unordered_map<int, std::string> map;

	// 添加操作
	// 在哈希表中添加键值对 （key, value）
	map[12836] = " 小王";
	map[15937] = " 小晴";
	map[16750] = " 小成";
	map[13276] = " 小盈";
	map[10583] = " 小兰";

	// 查询操作
	// 向哈希表中输入键 key， 得到值 value
	std::string name = map[15937];

	// 删除操作
	// 在哈希表中删除键值对（key, value）
	map.erase(10583);

	// 遍历哈希表
	// 遍历键值对 key -> value
	for (auto key : map)
	{
		std::cout << key.first << " -> " << key.second << std::endl;
	}

	// 使用迭代器遍历 key -> value
	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		std::cout << iter->first << " -> " << iter->second << std::endl;
	}
	return 0;
}
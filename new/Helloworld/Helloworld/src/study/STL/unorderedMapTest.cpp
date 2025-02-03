#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
	std::unordered_map<int, std::string> map;
	map.emplace(1, "ssss");
	map.insert({ 2,"sdaas" });
	map.emplace(3, "sdsadfasdf");

	// 1==>ssss, 2==>sdaas, 3==>sdsadfasdf
	for (auto key : map)
		std::cout << key.first << "==>" << key.second << std::endl;

	std::cout << map.count(2) << std::endl; // 1

	auto temp = map.find(3); 
	std::cout << temp->first << "==>" << temp->second << std::endl; // 3==>sdsadfasdf

	std::cout << map.size() << std::endl; // 3

	std::cout << map[1] << std::endl; // ssss

	//std::cout << map.conta

	return 0;
}
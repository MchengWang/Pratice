#include "basic.h"

class ArrayHashMap
{
public:
	ArrayHashMap()
		:buckets(std::vector<Pair*>(100))
	{
	}

	~ArrayHashMap()
	{
		// 释放内存
		for (const auto& bucket : buckets)
			delete bucket;
		buckets.clear();
	}

	// 哈希函数
	int hashFunc(int key)
	{
		return key % 100;
	}

	// 查询操作
	std::string get(int key)
	{
		int index = hashFunc(key);
		Pair* pair = buckets[index];
		if (pair == nullptr) return "";
		return pair->val;
	}

	// 添加操作
	void put(int key, std::string val)
	{
		Pair* pair = new Pair(key, val);
		buckets[hashFunc(key)] = pair;
	}

	// 删除操作
	void remove(int key)
	{
		int index = hashFunc(key);
		// 释放内存并置为 nullptr
		delete buckets[index];
		buckets[index] = nullptr;
	}

	// 获取所有键值对
	std::vector<Pair*> pairSet()
	{
		std::vector<Pair*> pairSet;
		for (Pair* pair : buckets)
			if (pair != nullptr) pairSet.push_back(pair);
		return pairSet;
	}

	// 获取所有键
	std::vector<int> keySet()
	{
		std::vector<int> keySet;
		for (auto* pair : buckets)
			if (pair != nullptr)
				keySet.push_back(pair->key);
		return keySet;
	}

	// 获取所有值
	std::vector<std::string> valueSet()
	{
		std::vector<std::string> valueSet;
		for (auto* pair : buckets)
			if (pair != nullptr)
				valueSet.push_back(pair->val);
		return valueSet;
	}

	// 打印哈希表
	void print()
	{
		for (auto* key : pairSet())
		{
			std::cout << key->key << " -> " << key->val << std::endl;
		}
	}
private:
	std::vector<Pair*> buckets;
};

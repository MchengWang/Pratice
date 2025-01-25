#include "basic.h"

int main1()
{
	// 初始化堆
	// 初始化小顶堆
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	// 初始化大顶堆
	std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;

	// 元素入堆
	maxHeap.push(1);
	maxHeap.push(3);
	maxHeap.push(2);
	maxHeap.push(5);
	maxHeap.push(4);

	// 获取堆顶元素
	int peek = maxHeap.top(); // 5

	// 堆顶元素出堆
	// 出堆元素会形成一个从大到小的序列
	maxHeap.pop(); // 5
	maxHeap.pop(); // 4
	maxHeap.pop(); // 3
	maxHeap.pop(); // 2
	maxHeap.pop(); // 1

	// 获取堆大小
	int size = maxHeap.size();

	// 判断堆是否为空
	bool isEmpty = maxHeap.empty();

	// 插入列表并建堆
	std::vector<int> input{ 1, 3, 2, 5, 4 };
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(input.begin(), input.end());
	return 0;
}
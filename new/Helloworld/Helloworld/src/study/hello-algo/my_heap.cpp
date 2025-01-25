#include "basic.h"

class MaxHeap
{
public:
	// 构造方法，根据输入列表建堆
	MaxHeap(std::vector<int> nums)
	{
		// 将列元素原封不动添加进堆
		maxHeap = nums;
		// 堆化除叶节点以外的其他所有节点
		for (int i = parent(size() - 1); i >= 0; i--)
			siftDown(i);
	}

	// 获取左子节点的索引
	int left(int i)
	{
		return 2 * i + 1;
	}

	// 获取右子节点的索引
	int right(int i)
	{
		return 2 * i + 2;
	}

	// 获取父节点的索引
	int parent(int i)
	{
		return (i - 1) / 2; // 向下整除
	}

	// 获取堆顶元素
	int peek()
	{
		return maxHeap[0];
	}

	int size()
	{
		return maxHeap.size();
	}

	bool isEmpty()
	{
		return size() == 0;
	}

	// 元素入堆
	void push(int val)
	{
		// 添加节点
		maxHeap.push_back(val);
		// 从底至顶堆化
		siftUp(size() - 1);
	}

	// 从节点 i 开始，从底至顶堆化
	void siftUp(int i)
	{
		while (true)
		{
			// 获取节点 i 的父节点
			int p = parent(i);
			// 当 “越过根节点” 或 “节点无需修复” 时，结束堆化
			if (p < 0 || maxHeap[i] <= maxHeap[p])
				break;
			// 交换两点
			std::swap(maxHeap[i], maxHeap[p]);
			// 循环向上堆化
			i = p;
		}
	}

	// 元素出堆
	void pop()
	{
		// 判空处理
		if (isEmpty())
			std::cout << "堆为空" << std::endl;
		// 交换根节点与最右叶节点（交换首元素与尾元素）
		std::swap(maxHeap[0], maxHeap[size() - 1]);
		// 删除节点
		maxHeap.pop_back();
		// 从顶至底堆化
		siftDown(0);
	}

	// 从节点 i 开始，从顶至底堆化
	void siftDown(int i)
	{
		while (true)
		{
			// 判断节点 i， l，r 中值最大的节点，记为 ma
			int l = left(i), r = right(i), ma = i;
			if (l < size() && maxHeap[l] > maxHeap[ma])
				ma = l;
			if (l < size() && maxHeap[r] > maxHeap[ma])
				ma = r;
			// 若节点 i 最大或索引 l，r 越界，则无需继续堆化，跳出
			if (ma == i)
				break;
			std::swap(maxHeap[i], maxHeap[ma]);
			// 循环向下堆化
			i = ma;
		}
	}
private:
	std::vector<int> maxHeap;
};
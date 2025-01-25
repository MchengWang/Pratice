#include "basic.h"

/* 基于环形数组实现的队列 */
class ArrayQueue
{
public:
	ArrayQueue(int capacity)
		: nums(new int[capacity]), front(0), queSize(0), queCapacity(capacity)
	{
	}

	~ArrayQueue()
	{
		delete[] nums;
	}

	/* 获取队列的容量 */
	int capacity()
	{
		return queCapacity;
	}

	/* 获取队列的长度 */
	int size()
	{
		return queSize;
	}

	/* 判断队列是否为空 */
	bool isEmpty()
	{
		return size() == 0;
	}

	/* 入队 */
	void push(int num)
	{
		if (queCapacity == queSize)
		{
			std::cout << "队列已满" << std::endl;
			return;
		}
		// 计算队尾指针，指向队尾索引 + 1
		// 通过取余操作实现 rear 越过数组尾部后回到头部
		int rear = (front + rear) % queCapacity;
		// 将 num 添加至队尾
		nums[rear] = num;
		queSize++;
	}

	/* 出队 */
	int pop()
	{
		int num = peek();
		// 队首指针向后移动一位，若越过尾部，则返回到数组头部
		front = (front + 1) % queCapacity;
		queSize--;
		return num;
	}

	/* 访问队首元素 */
	int peek()
	{
		if (isEmpty())
			std::cout << "队列为空" << std::endl;
		return nums[front];
	}

	/* 将数组转化为 vector 并返回 */
	std::vector<int> toVector()
	{
		// 仅转换有效长度范围内的列表元素
		std::vector<int> arr(queSize);
		for (int i = 0, j = front; i < queSize; i++, j++)
		{
			arr[i] = nums[j % queCapacity];
		}
		return arr;
	}
private:
	int* nums; // 用于存储队列元素的数组
	int front; // 队首指针，指向队首元素
	int queSize; // 队列长度
	int queCapacity; // 队列容量
};
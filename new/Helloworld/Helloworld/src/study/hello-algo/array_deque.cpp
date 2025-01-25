#include "basic.h"

/* 基于环形数组实现的双向队列 */
class ArrayDeque {
public:
	/* 构造方法 */
	ArrayDeque(int capacity) {
		nums.resize(capacity);
			front = queSize = 0;
	}

	/* 获取双向队列的容量 */
	int capacity() {
		return nums.size();
	}

	/* 获取双向队列的长度 */
	int size() {
		return queSize;
	}

	/* 判断双向队列是否为空 */
	bool isEmpty() {
		return queSize == 0;
	}

	/* 计算环形数组索引 */
	int index(int i) {
		// 通过取余操作实现数组首尾相连
		// 当 i 越过数组尾部后，回到头部
		// 当 i 越过数组头部后，回到尾部
		return (i + capacity()) % capacity();
	}

	/* 队首入队 */
	void pushFirst(int num) {
		if (queSize == capacity()) {
			std::cout << " 双向队列已满" << std::endl;
			return;
		}
		// 队首指针向左移动一位
		// 通过取余操作实现 front 越过数组头部后回到尾部
		front = index(front - 1);
		// 将 num 添加至队首
		nums[front] = num;
		queSize++;
	}

	/* 队尾入队 */
	void pushLast(int num) {
		if (queSize == capacity()) {
			std::cout << " 双向队列已满" << std::endl;
			return;
		}
		// 计算队尾指针，指向队尾索引 + 1
		int rear = index(front + queSize);
		// 将 num 添加至队尾
		nums[rear] = num;
		queSize++;
	}
	/* 队首出队 */
	int popFirst() {
		int num = peekFirst();
		// 队首指针向后移动一位
		front = index(front + 1);
		queSize--;
		return num;
	}
	/* 队尾出队 */
	int popLast() {
		int num = peekLast();
		queSize--;
		return num;
	}
	/* 访问队首元素 */
	int peekFirst() {
		if (isEmpty())
			std::cout << "双向队列为空" << std::endl;
		return nums[front];
	}
	/* 访问队尾元素 */
	int peekLast() {
		if (isEmpty())
			std::cout << "双向队列为空" << std::endl;
		// 计算尾元素索引
		int last = index(front + queSize - 1);
		return nums[last];
	}

	/* 返回数组用于打印 */
	std::vector<int> toVector() {
		// 仅转换有效长度范围内的列表元素
		std::vector<int> res(queSize);
		for (int i = 0, j = front; i < queSize; i++, j++) {
			res[i] = nums[index(j)];
		}
		return res;
	}
private:
	std::vector<int> nums; // 用于存储双向队列元素的数组
	int front; // 队首指针，指向队首元素
	int queSize; // 双向队列长度
};
#include <iostream>
#include <assert.h>

#define maxSize 50

template <class T>
class ArrayQueue
{
public:
	// 初始化
	ArrayQueue() : front(0), rear(0) {}

	// 队空
	bool isEmpty()
	{
		return rear == front;
	}

	// 入队
	bool enQueue(T t)
	{
		if ((front + 1) % maxSize == front)
		{
			throw std::out_of_range("队满");
			return false;
		}
		data[rear] = t;
		rear = (rear + 1) % maxSize;
		return true;
	}

	// 出队
	bool deQueue(T& t)
	{
		if (rear == front)
		{
			throw std::out_of_range("队空");
			return false;
		}
		t = data[front];
		front = (front + 1) % maxSize;
		return true;
	}
private:
	T data[maxSize];
	int front, rear;
};

int main()
{
	ArrayQueue<int>* queue = new ArrayQueue<int>();
	queue->enQueue(10);
	queue->enQueue(12);
	queue->enQueue(11);
	int num = 0;
	queue->deQueue(num);
	assert(num == 10);
	std::cout << num << std::endl;
	return 0;
}
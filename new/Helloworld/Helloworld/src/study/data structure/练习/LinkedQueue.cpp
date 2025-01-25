#include <iostream>
#include <assert.h>

template <typename T>
struct LinkedNode
{
	T data;
	LinkedNode* next;
};

template <typename T>
class LinkedQueue
{
public:
	// 初始化队列
	LinkedQueue()
	{
		front = rear = new LinkedNode<T>();
		front->next = nullptr;
	}

	// 判断队列是否为空
	bool isEmpty()
	{
		return front == rear;
	}

	// 入队
	void enQueue(T t)
	{
		LinkedNode<T>* temp = new LinkedNode<T>();
		temp->data = t; // 将变量放入队列结点数据中
		temp->next = nullptr; // 将结点指针置为空
		this->rear->next = temp; // 将当前尾部节点的下一个指针置为新插入的结点
		this->rear = temp; // 将尾部结点设置为插入节点
	}

	// 出队  
	bool deQueue(T& t)
	{
		if (rear == front)
		{
			throw std::out_of_range("队列为空");
			return false;
		}
		LinkedNode<T>* temp = front->next;
		t = temp->data;
		front->next = temp->next;
		if (rear == temp)
			rear = front;
		delete temp;
		return true;
	}
private:
	LinkedNode<T>* front, *rear;
};

int main()
{
	LinkedQueue<int>* queue = new LinkedQueue<int>();
	queue->enQueue(10);
	queue->enQueue(12);
	queue->enQueue(11);
	int num = 0;
	queue->deQueue(num);
	queue->deQueue(num);
	assert(num == 12);
	std::cout << num << std::endl;
	return 0;
}
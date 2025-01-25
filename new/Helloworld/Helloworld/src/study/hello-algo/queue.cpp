#include <iostream>
#include <queue>

int main()
{
	/* 初始化队列 */
	std::queue<int> queue;

	/* 元素入队 */
	queue.push(1);
	queue.push(3);
	queue.push(2);
	queue.push(5);
	queue.push(4);

	/* 访问队首元素 */
	int front = queue.front();

	/* 元素出队 */
	queue.pop();

	/* 获取队列的长度 */
	int size = queue.size();

	/* 判断队列是否为空 */
	bool empty = queue.empty();
	return 0;
}
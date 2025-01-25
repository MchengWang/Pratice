#include "basic.h"
#include <deque>

int main1()
{
	/* 初始化双向队列 */
	std::deque<int> deque;

	/* 元素入队 */
	deque.push_back(2); // 添加至队尾
	deque.push_back(5); 
	deque.push_back(4); 
	deque.push_front(3); // 添加至队首
	deque.push_front(1);

	/* 访问元素 */
	int front = deque.front(); // 队首元素
	int front = deque.back(); // 队尾元素

	/* 元素出队 */
	deque.pop_front(); // 队首元素出队
	deque.pop_back(); // 队尾元素出队

	/* 获取双向队列的长度 */
	int size = deque.size();

	/* 判断双向队列是否为空 */
	bool empty = deque.empty();
	return 0;
}
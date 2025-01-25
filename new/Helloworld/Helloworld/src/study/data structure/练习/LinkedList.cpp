#include <iostream>
#include <exception>

template <class T>
struct LNode
{
	T data;
	LNode<T>* next;
};

// 初始化
template <class T>
void listInit(LNode<T>* head)
{
	head = new LNode<T>();
	head->data = 0;
	head->next = nullptr;
}

// 链表的长度
template <class T>
int listLength(LNode<T> head)
{
	int length = 0;
	while (head)
	{
		head = head->next;
		length++;
	}
	return length;
}

// 删除结点中指定位置元素
template <class T>
bool listDelete(LNode<T>& head, int i, T& t)
{
	// 定义一个新节点，指向当前头节点
	LNode<T>* cur = head;
	int j = 0; // 记录当前位置，头节点是第 0 号位
	while (cur && j < i - 1) // 循环找到第 i - 1 个结点
	{
		cur = cur->next;
		j++;
	}
	if (!cur || !cur->next) // i 值不合法
		return false;
	LNode<T>* temp = cur->next; // 令临时节点指向被删除结点
	t = temp->data; // 将删除的结点数据导出
	cur->next = temp->next; // 断开删除结点的链接域
	delete temp; // 释放被删除节点的空间占用
	return true;
}

// 按序号查找结点
template <class T>
LNode<T>* getElement(LNode<T> head, int i)
{
	// 定义指针指向当前结点
	LNode<T>* cur = head;
	// 记录当前位置，头节点设置为 0 号
	int j = 0;
	while (head && j < i) // 循环找到第 i 个结点
	{
		cur = cur->next; // 将当前节点一直向后移动
		j++;
	}
	return cur;
}

// 按值查找结点
template <class T>
LNode<T>* getLocateElement(LNode<T> head, T t)
{
	// 定义一个指向当前节点的结点
	LNode<T>* cur = head; // 为了防止直接的操作原始头地址，造成数据丢失
	while (cur && cur->data != t) // 循环查找，当结点为空，或者当前结点中的元素是要找的结束循环
		cur = cur->next;
	// 当退出循环时，两种情况
	// 1、结点为空
	if (!cur) return nullptr;
	// 2、找到值相等的结点
	if (cur->data == t) return cur;
}

// 在第 i 个位置上插入节点
template <class T>
void insertList(LNode<T>& head, int i, T t)
{
	// 定义一个临时指针指向当前结点
	LNode<T>* cur = head;
	int j = 0; // 因为链表中带有头节点，而头节点是第 0 位
	while (cur && j < i - 1) // 循环找到第 i - 1 个结点并且移动后，结点不为空
	{
		cur = cur->next;
		j++;
	}
	if (!cur) // 如果结点为空，这说明 i 值不合法
		throw std::invalid_argument("i 值非法");
	// 创建一个新节点，将其插入到当前结点
	LNode<T>* temp = new LNode<T>(t);
	// 将新节点的下一个指针绑定为当前当前节点的下一个结点地址
	temp->next = cur->next;
	// 将当前节点的指针指向新插入的结点
	cur->next = temp;
}

// 头插法建立单链表 (逆向创建)
template <class T>
LNode<T>* listHeadInsert(LNode<T>* head, T* nums, int j)
{
	// 创建头节点
	head = new LNode<T>();
	// 将头结点的指针置为空
	head->next = nullptr;
	// 循环遍历 T 数组，添加结点
	for (int i = 0; i < j; i++)
	{
		// 创建要插入结点
		LNode<T>* temp = new LNode<T>();
		temp->data = nums[i]; // 将数组中的元素赋值给节点的数据域
		temp->next = head->next; // 将新创建的结点的下一个指针设置为头结点的下一个指针
		head->next = temp; // 将头结点的下一个结点的地址设置为新插入的结点
	}
	return head;
}

// 尾插法建立单链表 (正向创建)
template <class T>
LNode<T>* listTailInsert(LNode<T>* head, T* nums)
{
	// 创建头节点
	head = new LNode<T>();
	// 设置表尾指针
	LNode<T>* rear = new LNode<T>();
	// 计算数组长度
	int length = sizeof(nums) / sizeof(nums[0]);
	// 循环遍历 T 数组，添加结点
	for (int i = 0; i < length; i++)
	{
		// 创建要插入结点
		LNode<T>* temp = new LNode<T>();
		temp->data = nums[i]; // 将数组中的元素赋值给节点的数据域
		rear->next = temp; // 将尾指针的下一个地址设置为新插入的结点
		rear = temp; // 将尾指针设置为新插入的结点
	}
	return head;
}

int main()
{
	LNode<int>* head = new LNode<int>();
	listInit(head);
	int* nums = new int[4];
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	nums[3] = 4;
	head = listHeadInsert(head, nums, 4);
	while (head->next != nullptr)
	{
		head = head->next;
		std::cout << head->data << " ";
	}

	return 0;
}
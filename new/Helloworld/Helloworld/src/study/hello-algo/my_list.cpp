#include <iostream>
#include <vector>

/* 列表类 */
class MyList
{
public:
	/* 构造方法 */
	MyList()
	{
		arr = new int[arrCapacity];
	}

	/* 析构方法 */
	~MyList()
	{
		delete[] arr;
	}

	/* 获取列表长度（当前元素数量） */
	int size()
	{
		return arrSize;
	}

	/* 获取列表容量 */
	int capacity()
	{
		return arrCapacity;
	}

	/* 访问元素 */
	int get(int index)
	{
		// 索引如果越界，则输出异常，下同
		if (index < 0 || index >= size())
			std::cout << "索引越界" << std::endl;
		return arr[index];
	}

	/* 更新元素 */
	void set(int index, int num)
	{
		if (index < 0 || index >= size())
			std::cout << "索引越界" << std::endl;
		arr[index] = num;
	}

	/* 在尾部添加元素 */
	void add(int num)
	{
		// 元素数量超出容量时，出发扩容机制
		if (size() == capacity())
			extendCapacity();
		arr[size()] = num;
		// 更新元素数量
		arrSize++;
	}

	/* 在中间插入元素 */
	void insert(int index, int num)
	{
		if (index < 0 || index >= size())
			std::cout << "索引越界" << std::endl;
		// 元素数量超出容量时，出发扩容机制
		if (size() == capacity())
			extendCapacity();
		// 将索引 index 以及之后的元素向后移动一位
		for (int j = size() - 1; j >= index; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[index] = num;
		// 更新元素数量
		arrSize++;
	}

	/* 列表扩容 */
	void extendCapacity()
	{
		// 新建一个长度为原数组 extendRatio 倍的新数组
		int newCapacity = capacity() * extendRatio;
		int* tmp = arr;
		arr = new int[newCapacity];
		// 将原数组中的所有元素赋值到新数组
		for (int i = 0; i < size(); i++)
		{
			arr[i] = tmp[i];
		}
		// 释放内存
		delete[] tmp;
		arrCapacity = newCapacity;
	}

	/* 将列表转换为 Vector 用于打印 */
	std::vector<int> toVector()
	{
		// 仅转换有效长度范围内的列表元素
		std::vector<int> vec(size());
		for (int i = 0; i < size(); i++)
		{
			vec[i] = arr[i];
		}
		return vec;
	}

	/* 删除元素 */
	int remove(int index)
	{
		if (index < 0 || index >= size())
			std::cout << "索引越界" << std::endl;
		int num = arr[index];
		// 将索引 index 之后的元素都向前移动一位
		for (int j = index; j < size() - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		// 更新元素数量
		arrSize--;
		// 返回被删除的元素
		return num;
	}
private:
	int* arr; // 数组（存储列表元素）
	int arrCapacity = 10; // 列表容量
	int arrSize = 0; // 列表长度（当前元素数量）
	int extendRatio = 2; // 每次列表扩容的倍数
};
#include <iostream>
#include <exception>

template <class T>
class ArrayList
{
public:
	// 初始化构建顺序表
	void arrayListInit(int maxLength = 100)
	{
		arrs = new T[maxLength]; // 创建数据域 长度为 maxLength （默认为 100 ）
		length = maxLength; // 顺序表最大支持长度
		size = 0; // 顺序表中元素个数
	}

	// 查找指定元素
	bool findElement(T arr)
	{
		// 按照顺序表中的元素个数进行遍历查找，可以防止遍历无用空间
		for (int i = 0; i < size; i++)
			if (arrs[i] == arr) // 当当前顺序表元素的数据等于我们所要查找的，直接返回 true
				return true;
		// 查找失败 返回 false
		return false;
	}

	// 获取指定位置的元素
	T findLocalElement(int index)
	{
		// 判断指定位置是否合法
		if (index < 0 || index >= length)
			throw std::invalid_argument("查找位置不符合");
		// 否则返回数据
		return arrs[index];
	}

	// 在顺序表尾部插入数据
	void inElementOnBack(T arr)
	{
		if (size + 1 >= length)
			// 扩容顺序表
			extendListLength();
		// 在 size 的位置上插入元素
		arrs[size] = arr;
		// 元素个数变长
		size++;
	}

	// 在指定位置上添加元素
	void inElementLocal(int index, T arr)
	{
		// 判断添加位置是否非法
		if (index < 0) throw std::invalid_argument("索引非法");
		// 如果添加位置超出顺序表最大长度，则进行扩充顺序表
		if (index > length) extendListLength();
		// 上述均未 接下来插入元素到指定位置
		// 首先将指定位置的元素以及其后部分的元素均向后移动一位
		for (int i = size - 1; i >= index; i--)
			arrs[i + 1] = arrs[i];
		arrs[index] = arr;
		// 元素数量 加 1
		size++;
	}

	// 删除指定元素
	void eraseFixtureElement(T arr)
	{
		// 循环遍历顺序表，找到需要删除数据，将其删除，并移动元素
		for (int i = 0; i < length; i++)
			if (arrs[i] == arr) eraseIndexElement(i);
	}

	// 删除元素
	void eraseIndexElement(int index)
	{
		// 判断顺序表长度是否合法
		if (index < 0 || index >= length) throw std::invalid_argument("删除索引非法");
		// 删除指定索引位置的元素
		for (int i = index; i < length; i++)
			arrs[i] = arrs[i + 1];
		size--;
	}

	// 删除全部元素
	void erase()
	{
		arrs = new T[length];
		size = 0;
	}

	// 扩展顺序表
	void extendListLength()
	{
		// 创建扩大后的顺序表
		T* extendArrs = new T[length * 2];
		// 将原来顺序表中的元素复制到新顺序表中
		for (int i = 0; i < length; i++)
			extendArrs[i] = arrs[i]; // 复制元素
		// 将新顺序表返回
		arrs = extendArrs;
		// 清除占用空间
		delete[] extendArrs;
	}

	// 顺序表是否为空
	bool isEmpty()
	{
		return size == 0;
	}

	// 返回顺序表元素个数
	int sizeElement()
	{
		return size;
	}

	// 返回元素大小
	long long listSize()
	{
		return (long long)(sizeof(arrs) * size);
	}

private:
	T* arrs; // 顺序表中的元素
	int length, size; // 顺序表的长度和表中元素个数
};

int main()
{
	ArrayList<int>* list = new ArrayList<int>();
	list->arrayListInit();
	list->inElementLocal(0, 1);
	list->inElementLocal(0, 2);
	list->inElementLocal(0, 3);
	list->inElementLocal(0, 4);
	list->inElementLocal(0, 5);
	std::cout << list->sizeElement() << std::endl;
	std::cout << list->listSize() << std::endl;
	list->eraseFixtureElement(1);
	std::cout << list->sizeElement() << std::endl;
	std::cout << list->listSize() << std::endl;
	list->erase();
	std::cout << list->sizeElement() << std::endl;
	std::cout << list->listSize() << std::endl;
	return 0;
}
#include <stdio.h>

// sum
int main1()
{
	int n = 10, sum = 0;
	//scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		sum += (1 / i);
	}
	printf("sum = %d", sum);
	return 0;
}

#include <iostream>


// friend test
class Base
{
public:
	friend void get(Base t);
	friend class Demo;
	void print()
	{
		std::cout << set << std::endl;
	}

private:
	int set = 10;
};

class Demo
{
public:
	Demo(Base base)
		:set(base.set) {
	}


	void print()
	{
		std::cout << set << std::endl;
	}
private:
	int set = 1;
};


void get(Base t)
{
	t.set = 12;
	t.print();
}


int main2()
{
	Base base;
	get(base);

	Demo demo(base);
	demo.print();


	return 0;
}


double pam(int);


int main3()
{
	// 创建函数函数
	double (*pf)(int);
	pf = pam;

	double d = pf(3);

	int i = 10, y = 20;

	// lamada 表达式
	auto t = [&](int i, int y) {
		std::cout << i + y << std::endl;
		};

	 t(i, y);
	 return 0;
}

double pam(int e)
{
	std::cout << e << std::endl;
	return e;
}

struct BitNode
{
	int val;
	BitNode* left, * right;
	BitNode(int val, BitNode* lrft, BitNode* right)
		:val(val), left(lrft), right(right) {}
	BitNode() {}
};

int HeightBalance(BitNode* T, int Height)
{
	if (T == nullptr)
	{
		Height = 0;
		return 1;
	}


	int leftHeight = 0, rightHeight = 0;
	if (HeightBalance(T->left, leftHeight) == 0) return 0;
	if (HeightBalance(T->right, rightHeight) == 0) return 0;
	Height = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
	if ((leftHeight - rightHeight) <= 1 && (leftHeight - rightHeight) >= -1) return 1;
	else return 0;
}

int main()
{
	BitNode* t1 = new BitNode(9 ,nullptr, nullptr);
	BitNode* t2 = new BitNode(8 ,t1, nullptr);
	BitNode* t3 = new BitNode(4 ,t2, nullptr);
	BitNode* t4 = new BitNode(5 ,nullptr, nullptr);
	BitNode* t5 = new BitNode(2 ,t3, t4);
	BitNode* t6 = new BitNode(6, nullptr, nullptr);
	BitNode* t7 = new BitNode(7, nullptr, nullptr);
	BitNode* t8 = new BitNode(3 ,t6, t7);
	BitNode* t9 = new BitNode(1, t5, t8);

	std::cout << HeightBalance(t9, 0);
}
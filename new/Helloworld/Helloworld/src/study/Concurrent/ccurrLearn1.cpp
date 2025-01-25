#include <iostream>
#include <thread>

void hello()
{
	std::cout << "Hellow concurrent world\n";
}

int main()
{
	// 在 thread 构造中使用的方法会作为其对应线程的运行入口
	std::thread t(hello); 
	t.join(); // 使主线程等子线程运行
}
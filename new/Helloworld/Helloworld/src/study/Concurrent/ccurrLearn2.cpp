#include <iostream>
#include <thread>

class thread_guard
{
	std::thread& t;

public:
	explicit thread_guard(std::thread& t_)
		:t(t_)
	{
	}

	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}

	thread_guard(thread_guard const&) = delete;
	thread_guard& operator= (thread_guard const&) = delete;
};

struct func
{
	int& i;
	func(int& i) :i(i) {}
	void operator() ()
	{
		for (unsigned j = 0; j < 100000; j++)
		{
			std::cout << j << "\n";
		}
	}
};

void oops()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread my_thread(my_func);
	my_thread.detach(); // 不等待新线程结束
}

void f()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread t(my_func);
	thread_guard g(t);
	std::cout << "11" << "\n";
}


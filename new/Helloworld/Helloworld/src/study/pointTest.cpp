#include <iostream>
#include <string>

int main()
{
	char c = 'a';
	//
	std::cout << " 一层指针，未修改值" << std::endl;
	char* add = &c;

	std::cout << *add << std::endl;

	// 一层指针 修改值
	*add = 'b';

	std::cout << *add << std::endl;

	std::cout << "二层指针" << std::endl;
	// 二层指针
	char** sc = &add;
	std::cout << **sc << std::endl;

	**sc = 'c';

	std::cout << **sc << std::endl;

	std::cout << "三层指针" << std::endl;
	// 三层指针
	char*** scs = &sc;

	std::cout << ***scs << std::endl;

	***scs = 'd';

	//std::cout << *scs << std::endl;
	//std::cout << **scs << std::endl;
	std::cout << ***scs << std::endl;

	std::cout << "四层指针" << std::endl;
	// 四层指针
	char**** scsc = &scs;

	std::cout << ****scsc << std::endl;

	****scsc = 'e';

	std::cout << ****scsc << std::endl;

	std::cout << "五层指针" << std::endl;
	// 五层指针
	char***** scscs = &scsc;

	std::cout << *****scscs << std::endl;

	*****scscs = 'f';

	std::cout << *****scscs << std::endl;

	std::cout << " 六层指针" << std::endl;
	// 六层指针
	char****** scscsc = &scscs;

	std::cout << ******scscsc << std::endl;

	******scscsc = 'g';

	std::cout << ******scscsc << std::endl;

	std::cout << "七层指针" << std::endl;
	// 七层指针
	char******* scscscs = &scscsc;

	std::cout << *******scscscs << std::endl;

	*******scscscs = 'h';

	std::cout << *******scscscs << std::endl;

	std::cout << "八层指针" << std::endl;
	// 八层指针
	char******** scscscsc = &scscscs;

	std::cout << ********scscscsc << std::endl;

	********scscscsc = 'i';

	std::cout << ********scscscsc << std::endl;

	std::cout << "最后修改后的一层指针" << std::endl;

	std::cout << *add << std::endl;
}

#include <iostream>
#include <memory>

int main1()
{
	std::unique_ptr<int> ptr1 = std::make_unique<int>();
	std::cin.get();
}
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string strs;
	while (std::cin >> strs)
	{
		std::string* temp = new std::string();
		std::vector<int> vecs;
		for (int i = 0; i < strs.length(); i++)
		{
			if (strs[i] == '5' && !temp->empty())
			{
				vecs.push_back(std::stoi(*temp, 0, 10));
				temp->erase();
			}
			else
				temp->push_back(strs[i]);
		}

		for (int i = 0; i < vecs.size(); i++)
		{
			for (int j = i; j < vecs.size(); j++)
			{
				int* t = new int();
				if (vecs[i] > vecs[j])
				{
					*t = vecs[i];
					vecs[i] = vecs[j];
					vecs[j] = *t;
				}
				delete t;
			}
		}

		int flag = 0;
		for (int i = 0; i < vecs.size(); i++)
		{
			if (!flag)
			{
				std::cout << vecs[i];
				flag = 1;
			}
			else
			{
				std::cout << " " << vecs[i];
			}
		}

		std::cout << std::endl;
	}
	return 0;
}
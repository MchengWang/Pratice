#include <iostream>
#include <string>
#include <memory>

int main()
{
	std::unique_ptr<std::string> strs = std::make_unique<std::string>();
	while (std::cin >> *strs)
	{
		std::string* temp = new std::string();
		for (int i = 0; i < strs->size(); i++)
		{
			switch (strs->at(i))
			{
			case 'b': temp->push_back(' '); break;
			case 'q': temp->push_back(','); break;
			case 't': temp->push_back('!'); break;
			case 'm': temp->push_back('l'); break;
			case 'i': temp->push_back('e'); break;
			case 'c': temp->push_back('a'); break;
			case 'a': temp->push_back('c'); break;
			case 'e': temp->push_back('i'); break;
			case 'l': temp->push_back('m'); break;
			default:
				temp->push_back(strs->at(i));
				break;
			}
		}

		std::cout << *temp << std::endl;

		delete temp;
	}
	return 0;
}

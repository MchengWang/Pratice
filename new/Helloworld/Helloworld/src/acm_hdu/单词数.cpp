#include <iostream> 
#include <string>
#include <set>

int main()
{
	std::string str, str1;   //str代表输入，str1代表过渡字符串 
	std::set<std::string> sets;    //单词表  
	while (getline(std::cin, str) && str[0] != '#')  //输入 
	{
		sets.clear();
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')  //读到一个单词的末尾 
			{
				if (str1 != "")
					sets.insert(str1);
				str1 = "";
			}
			else                  //将读取到的字符存入字符串str1中 
			{
				str1 += str[i];
			}
		}
		//存储单词 
		if (str1 != "")
		{
			sets.insert(str1);
			str1 = "";
		}
		std::cout << sets.size() << std::endl;//结果输出 
	}

	return 0;
}
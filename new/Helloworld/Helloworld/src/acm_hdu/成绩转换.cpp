#include <iostream>
#include <string>

int main()
{
	int score;
	while (std::cin >> score)
	{
		if (score < 0 || score > 100)
		{
			std::cout << "Score is error!" << std::endl;
		}
		else
		{
			if (score >= 90 && score <= 100) std::cout << "A" << std::endl;
			else if (score >= 80 && score <= 89) std::cout << "B" << std::endl;
			else if (score >= 70 && score <= 79) std::cout << "C" << std::endl;
			else if (score >= 60 && score <= 69) std::cout << "D" << std::endl;
			else std::cout << "E" << std::endl;
		}
	}
	return 0;
}
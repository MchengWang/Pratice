#include <iostream>

int main()
{
	int n;
	while (std::cin >> n)
	{
		while (n--)
		{
			int* ah = new int(), * am = new int(), * as = new int(), * bh = new int(), * bm = new int(), * bs = new int();
			std::cin >> *ah >> *am >> *as >> *bh >> *bm >> *bs;
			*ah += *bh;
			*am += *bm;
			*as += *bs;
			if (*as / 60 != 0)
			{
				int* temp = new int();
				*temp = *as / 60;
				*as %= 60;
				*am += *temp;
				delete temp;
			}

			if (*am / 60 != 0)
			{
				{
					int* temp = new int();
					*temp = *am / 60;
					*am %= 60;
					*ah += *temp;
					delete temp;
				}
			}

			std::cout << *ah << ' ' << *am << ' ' << *as << std::endl;
			delete ah, am, as, bh, bm, bs;
		}
	}
	return 0;
}
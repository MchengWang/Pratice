#include <iostream>
#include <string>

 #define isRunYear(year) (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)

 int nums[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31}, {0,31,29,31,30,31,30,31,31,30,31,30,31} };
 char buf[7][20] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

 int main() {
     int i, j, year, month, day, total;
     while (std::cin >> year >> month >> day) {
         total = day;
         j = isRunYear(year);
         if (month == 0 || day == 0) {
             std::cout << "illegal" << std::endl;
             continue;
		}
        for (i = 1; i < month; ++i)
		    total += nums[j][i];
            if (month == 2) {
                 if (!j && day > 28) {
                     std::cout << "illegal" << std::endl;
                    continue;
			}
		    if (j && day > 29) {
                std::cout << "illegal" << std::endl;
               continue;
			    }
		    }
            if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		       std::cout << "illegal" << std::endl;
                 continue;
		    }
            for (i = 1; i < year; ++i) {
              if (isRunYear(i))
                    total += 366;
                 else
                     total += 365;
		    }
             i = total % 7;
             std::cout << buf[i] << std::endl;
	    }
    return 0;
}
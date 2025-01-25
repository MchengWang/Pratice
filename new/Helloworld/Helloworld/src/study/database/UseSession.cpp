#include <mysqlx/xdevapi.h>

#include <iostream>
#include <string>
#include <list>

int main()
{
	std::string url = "root:12120326@127.0.0.1:33060/test";
	
	{
		mysqlx::Session mySession(url);

		// 获取全部的 schemas
		std::list<mysqlx::Schema> schemaList = mySession.getSchemas();

		// 输出全部可用 schemas
		for (mysqlx::Schema schema : schemaList)
		{
			std::cout << schema.getName() << "\n";
		}
	}


	return 0;
}
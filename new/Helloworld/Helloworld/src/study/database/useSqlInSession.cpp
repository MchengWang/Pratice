#include <mysqlx/xdevapi.h>

#include <iostream>
#include <string>

int main()
{
    // Connect to server on localhost
    std::string url = "root:12120326@127.0.0.1:33060/test";
    mysqlx::Session mySession(url);

    // Switch to use schema 'test'
    mySession.sql("USE test").execute();

    // In a Session context the full SQL language can be used
    mySession.sql("CREATE PROCEDURE my_add_one_procedure "
        " (INOUT incr_param INT) "
        "BEGIN "
        "  SET incr_param = incr_param + 1;"
        "END;")
        .execute();
    mySession.sql("SET @my_var = ?;").bind(10).execute();
    mySession.sql("CALL my_add_one_procedure(@my_var);").execute();
    mySession.sql("DROP PROCEDURE my_add_one_procedure;").execute();

    // Use an SQL query to get the result
    auto myResult = mySession.sql("SELECT @my_var").execute();

    // Gets the row and prints the first column
    mysqlx::Row row = myResult.fetchOne();
    std::cout << row[0] << std::endl;
	return 0;
}
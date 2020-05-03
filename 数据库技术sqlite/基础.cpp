/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-02 21:18:45
 * @LastEditTime: 2020-05-03 10:08:40
 * @FilePath: /数据库技术sqlite/基础.cpp
 */
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <iomanip>

// 回调函数先上一份官方文档啃
/*
CAPI3REF: One-Step Query Execution Interface

The sqlite3_exec() interface is a convenience wrapper around
[sqlite3_prepare_v2()], [sqlite3_step()], and [sqlite3_finalize()],
that allows an application to run multiple statements of SQL
without having to use a lot of C code. 

^The sqlite3_exec() interface runs zero or more UTF-8 encoded,
semicolon-separate SQL statements passed into its 2nd argument,
in the context of the [database connection] passed in as its 1st
argument.  ^If the callback function of the 3rd argument to
sqlite3_exec() is not NULL, then it is invoked for each result row
coming out of the evaluated SQL statements.  ^The 4th argument to
sqlite3_exec() is relayed through to the 1st argument of each
callback invocation.  ^If the callback pointer to sqlite3_exec()
is NULL, then no callback is ever invoked and result rows are
ignored.

^If an error occurs while evaluating the SQL statements passed into
sqlite3_exec(), then execution of the current statement stops and
subsequent statements are skipped.  ^If the 5th parameter to sqlite3_exec()
is not NULL then any error message is written into memory obtained
from [sqlite3_malloc()] and passed back through the 5th parameter.
To avoid memory leaks, the application should invoke [sqlite3_free()]
on error message strings returned through the 5th parameter of
of sqlite3_exec() after the error message string is no longer needed.
^If the 5th parameter to sqlite3_exec() is not NULL and no errors
occur, then sqlite3_exec() sets the pointer in its 5th parameter to
NULL before returning.

^If an sqlite3_exec() callback returns non-zero, the sqlite3_exec()
routine returns SQLITE_ABORT without invoking the callback again and
without running any subsequent SQL statements.

^The 2nd argument to the sqlite3_exec() callback function is the
number of columns in the result.  ^The 3rd argument to the sqlite3_exec()
callback is an array of pointers to strings obtained as if from
[sqlite3_column_text()], one for each column.  ^If an element of a
result row is NULL then the corresponding string pointer for the
sqlite3_exec() callback is a NULL pointer.  ^The 4th argument to the
sqlite3_exec() callback is an array of pointers to strings where each
entry represents the name of corresponding result column as obtained
from [sqlite3_column_name()].

^If the 2nd parameter to sqlite3_exec() is a NULL pointer, a pointer
to an empty string, or a pointer that contains only whitespace and/or 
SQL comments, then no SQL statements are evaluated and the database
is not changed.

Restrictions:

 The application must insure that the 1st parameter to sqlite3_exec()
is a valid and open [database connection].
 The application must not close [database connection] specified by
the 1st parameter to sqlite3_exec() while sqlite3_exec() is running.
 The application must not modify the SQL statement text passed into
the 2nd parameter of sqlite3_exec() while sqlite3_exec() is running.
*/
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   for(int i = 0; i < argc; i ++){
      std::cout  << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
   }
   std::cout << std::endl;
   return 0;
}

// [注]编译时需要加参数-l sqlite3
int main(void){
   sqlite3 *db;
   int rc;
   char *sql = 0; // 避免形成野指针
   char *zErrMsg = 0;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   if(rc != SQLITE_OK){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = (char *)"CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if(rc != SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Table created successfully\n");
   }

   sql = (char *)"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
      "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
      "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
      "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
      "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
      "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
      "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
      "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if(rc != SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records created successfully\n");
   }

   sql = (char *)"select * from company";
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg); // [注] 在不使用回调函数时将call_back参数置为空
   if(rc != SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records created successfully\n");
   }
   
   /* 关闭数据库 */
   sqlite3_close(db);
   return 0;
}
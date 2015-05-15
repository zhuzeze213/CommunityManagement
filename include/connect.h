#ifndef CONNECT_H
#define CONNECT_H
#define MYSQLHOST "localhost"
#define MYSQLUSER "root"
#define MYSQLPASSWORD "123456"
#define MYSQLDB "community"

int connect_mysql();
void close_mysql();
#endif

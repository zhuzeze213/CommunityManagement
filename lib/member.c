#include "../include/member.h"

MYSQL mysql;
int connect_mysql() 
{    
	if( mysql_init(&mysql) == NULL ){
		printf("Init mysql err!"); 
		return FAIL;
	}
	if(mysql_real_connect(&mysql,MYSQLHOST,MYSQLUSER,MYSQLPASSWORD,MYSQLDB,0,NULL,0) == NULL){
		printf("Connect to mysql Error!"); 
		return FAIL;
	}
	else
		printf("Connect to mysql success!");    
	return SUCCESS;
} 
void close_mysql()
{
	mysql_close(&mysql); 
} 
static int doaddmember(struct member *addone) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"insert into member_info(m_name,m_sno,m_sex,m_phone,password,state) values ('%s', '%s', '%s', '%s', '%s', %d)",addone->name,addone->sno,addone->sex,addone->phone,addone->password,addone->state); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	m_res = mysql_store_result(&mysql); 
/*	if(m_res==NULL){
		printf("get result err"); 
		return FAIL;
	}*/
	mysql_free_result(m_res);
	return SUCCESS;
}

int __addmember(struct member *addone)
{
	if(connect_mysql()==SUCCESS&&doaddmember(addone)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}

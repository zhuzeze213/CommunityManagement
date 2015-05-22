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

static int doverifyaccount(char username[NAME_LENGTH],char password[PASSWORD_LENGTH]) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"select password from member_info where m_sno='%s'",username); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	m_res = mysql_store_result(&mysql); 
	if(m_res==NULL){
		printf("get result err"); 
		return FAIL;
	}
	if(m_row = mysql_fetch_row(m_res)){
		//printf("%s\n",m_row[0]);
		if(!strcmp(m_row[0],password)){
			mysql_free_result(m_res);
			return SUCCESS;
		}
		else{
			mysql_free_result(m_res);
			return FAIL;
		}
	}
	else{
		mysql_free_result(m_res);
		return FAIL;
	}
}

int __verifyaccount(char username[NAME_LENGTH],char password[PASSWORD_LENGTH])//login
{
	if(connect_mysql()==SUCCESS&&doverifyaccount(username,password)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;
}

static int dogetinformation(char username[NAME_LENGTH]) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"select * from member_info where m_sno='%s'",username); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	m_res = mysql_store_result(&mysql); 
	if(m_res==NULL){
		printf("get result err"); 
		return FAIL;
	}
	if(m_row = mysql_fetch_row(m_res)){
		member_z.id=atoi(m_row[0]);
		strcpy(member_z.name,m_row[1]);
		strcpy(member_z.sno,m_row[2]);
		strcpy(member_z.sex,m_row[3]);
		strcpy(member_z.phone,m_row[4]);
		strcpy(member_z.password,m_row[5]);
		return SUCCESS;
	}
	else{
		mysql_free_result(m_res);
		return FAIL;
	}
}

int __getinformation(char username[NAME_LENGTH])
{
	if(connect_mysql()==SUCCESS&&dogetinformation(username)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;
}

static int dosetstate(char username[NAME_LENGTH],int state) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"update member_info set state=%d where m_sno='%s'",state,username); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	mysql_free_result(m_res);
	return SUCCESS;
}

int __setstate(char username[NAME_LENGTH],int state)
{
	if(connect_mysql()==SUCCESS&&dosetstate(username,state)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;
}

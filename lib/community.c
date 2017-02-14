#include "../include/community.h"

MYSQL mysql;
static int dolookcommunity() 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"select * from community_info"); 
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
	int count=0;
	while(m_row = mysql_fetch_row(m_res)){
		community_z[count].c_id=atoi(m_row[0]);
		strcpy(community_z[count].c_name,m_row[1]);
		strcpy(community_z[count].c_data,m_row[2]);
		strcpy(community_z[count].c_phone,m_row[3]);
		community_z[count].master_no=atoi(m_row[4]);
		strcpy(community_z[count].c_information,m_row[5]);
		count++;
	}
	community_num=count;
    mysql_free_result(m_res);
	return SUCCESS;
}

int __lookcommunity()
{
	if(connect_mysql()==SUCCESS&&dolookcommunity()==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}
static int dofindcommunity(int id) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"select * from community_info where c_id=%d",id); 
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
	int count=0;
	if(m_row = mysql_fetch_row(m_res)){
		community_z[count].c_id=atoi(m_row[0]);
		strcpy(community_z[count].c_name,m_row[1]);
		strcpy(community_z[count].c_data,m_row[2]);
		strcpy(community_z[count].c_phone,m_row[3]);
		community_z[count].master_no=atoi(m_row[4]);
		strcpy(community_z[count].c_information,m_row[5]);
	}
    mysql_free_result(m_res);
	return SUCCESS;
}

int __findcommunity(int id)
{
	if(connect_mysql()==SUCCESS&&dofindcommunity(id)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}

static int doapplycommunity(int id) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"insert into member_admin(m_id,c_id,mc_grant) values (%d, %d, %d)",member_z.id,id,GRANT_PASSERS_BY); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	return SUCCESS;
}

int __applycommunity(int id)
{
	if(connect_mysql()==SUCCESS&&doapplycommunity(id)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}

static int dolookapply() 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"select * from member_admin where c_id=%d",member_z.id); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query\n");
		return FAIL;
	} 
	m_res = mysql_store_result(&mysql); 
	if(m_res==NULL){
		printf("get result err"); 
		return FAIL;
	}
	int cm_flag=0,com_id;
	while(m_row = mysql_fetch_row(m_res)){
		if(atoi(m_row[2])==GRANT_CM){
			cm_flag=1;
			com_id=atoi(m_row[1]);
			break;
		}
	}
	if(cm_flag){
		sprintf(sql,"select * from member_info where m_id in (select m_id from member_admin where c_id=%d and mc_grant=%d)",com_id,GRANT_PASSERS_BY); 
		printf("%s\n",sql);
		if(mysql_query(&mysql,sql) != 0){
			printf("mysql_query\n");
			return FAIL;
		} 
		m_res = mysql_store_result(&mysql); 
		if(m_res==NULL){
			printf("get result err"); 
			return FAIL;
		}
		int count=0;
		while(m_row = mysql_fetch_row(m_res)){
			member_a[count].id=atoi(m_row[0]);
			strcpy(member_a[count].name,m_row[1]);
			strcpy(member_a[count].sno,m_row[2]);
			strcpy(member_a[count].sex,m_row[3]);
			strcpy(member_a[count].phone,m_row[4]);
			member_a[count].state=atoi(m_row[6]);
			count++;
		}
		apply_num=count;
		mysql_free_result(m_res);
		return SUCCESS;
	}
	else
		return FAIL;
}

int __lookapply()
{
	if(connect_mysql()==SUCCESS&&dolookapply()==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}

static int doagreeapply(int id,int c_id) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"update member_admin set mc_grant=%d where m_id=%d and c_id=%d",GRANT_NM,id,c_id); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	return SUCCESS;
}

int __agreeapply(int id,int c_id)
{
	if(connect_mysql()==SUCCESS&&doagreeapply(id,c_id)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}
static int dorefuseapply(int id,int c_id) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"delete from member_admin where m_id=%d and c_id=%d",id,c_id); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	return SUCCESS;
}

int __refuseapply(int id,int c_id)
{
	if(connect_mysql()==SUCCESS&&dorefuseapply(id,c_id)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}

static int dolookmember() 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 
	int i,count=0;
	for(i=0;i<check_community_num;i++){
		in_num[i]=0;
		sprintf(sql,"select * from member_info where m_id in (select m_id from member_admin where mc_grant!=%d and c_id=%d)",GRANT_PASSERS_BY,check_community_id[i]); 
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
		
		while(m_row = mysql_fetch_row(m_res)){
			member_i[count].id=atoi(m_row[0]);
			strcpy(member_i[count].name,m_row[1]);
			strcpy(member_i[count].sno,m_row[2]);
			strcpy(member_i[count].sex,m_row[3]);
			strcpy(member_i[count].phone,m_row[4]);
			member_i[count].state=atoi(m_row[6]);
			count++;
		}
		in_num[i]+=count;
	}
    mysql_free_result(m_res);
	return SUCCESS;
}

int __lookmember()
{
	if(connect_mysql()==SUCCESS&&dolookmember()==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}
static int dofindmember(int id) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"select * from member_info where m_id=%d",id); 
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
	int count=0;
	if(m_row = mysql_fetch_row(m_res)){
		member_i[count].id=atoi(m_row[0]);
		strcpy(member_i[count].name,m_row[1]);
		strcpy(member_i[count].sno,m_row[2]);
		strcpy(member_i[count].sex,m_row[3]);
		strcpy(member_i[count].phone,m_row[4]);
		member_i[count].state=atoi(m_row[6]);
	}
    mysql_free_result(m_res);
	return SUCCESS;
}

int __findmember(int id)
{
	if(connect_mysql()==SUCCESS&&dofindmember(id)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}
static int dodeletemember(int id,int c_id) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"delete from member_admin where m_id=%d and c_id=%d",id,c_id); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	return SUCCESS;
}

int __deletemember(int id,int c_id)
{
	if(connect_mysql()==SUCCESS&&dodeletemember(id,c_id)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}
static int doaddcommunity(struct community *addone) 
{ 
	if(strcmp(member_z.name,"root")!=0)
		return FAIL;
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 
	sprintf(sql,"insert into community_info(c_name,c_data,c_phone,master_no,c_infomation) values ('%s', '%s', '%s', %d, '%s')",addone->c_name,addone->c_data,addone->c_phone,addone->master_no,addone->c_information); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	}
	
	int c_id=0;
	sprintf(sql,"select c_id from community_info where c_name='%s'",addone->c_name); 
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
		c_id=atoi(m_row[0]);
	}
	
	sprintf(sql,"insert into member_admin(m_id,c_id,mc_grant) values (%d, %d, %d)",addone->master_no,c_id,GRANT_CM); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	}	
	
	return SUCCESS;
}

int __addcommunity(struct community *addone)
{
	if(connect_mysql()==SUCCESS&&doaddcommunity(addone)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}
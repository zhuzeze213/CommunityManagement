#include "../include/message.h"

MYSQL mysql;
static int dosendmessage(struct info_diffusion *addone) 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 

	sprintf(sql,"insert into info_diffusion(m_id,c_id,i_text,i_date) values (%d, %d, '%s','%s')",addone->m_id,addone->c_id,addone->i_text,addone->i_data); 
	printf("%s\n",sql);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	return SUCCESS;
}

int __sendmessage(struct info_diffusion *addone)
{
	if(connect_mysql()==SUCCESS&&dosendmessage(addone)==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}

static int doreceivemessage() 
{ 
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 
	int i,count=0;
	for(i=0;i<check_community_num;i++){
		message_in_num[i]=0;
		sprintf(sql,"select * from info_diffusion where c_id=%d",check_community_id[i]); 
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
			message_i[count].m_id=atoi(m_row[1]);
			strcpy(message_i[count].i_text,m_row[3]);
			strcpy(message_i[count].i_data,m_row[4]);
			count++;
		}
		message_in_num[i]+=count;
	}
    mysql_free_result(m_res);
	return SUCCESS;
}

int __receivemessage()
{
	if(connect_mysql()==SUCCESS&&doreceivemessage()==SUCCESS){
		close_mysql();
		return SUCCESS;
	}
	return FAIL;	
}

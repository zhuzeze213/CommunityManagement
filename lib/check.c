#include "../include/check.h"

MYSQL mysql;
static void init_check_data()
{
	check_community_num=0;
	check_activity_num=0;
	check_apply_num=0;
	check_apply_activity_num=0;
	check_info_num=0;
	int i;
	for(i=0;i<MAX_COMMUNITY_NUM;i++){
		check_community_id[i]=0;
		check_grant[i]=0;
		check_per_num[i]=0;
	}
}

int per_num(int c_id)//calculate number of people in community.
{
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res;
	char sql[LONG_BUFF]; 
	sprintf(sql,"select count(*) from member_admin where mc_grant!=%d and c_id=%d",GRANT_PASSERS_BY,c_id);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	m_res = mysql_store_result(&mysql); 
	if(m_res==NULL){
		printf("get result err"); 
		return FAIL;
	}
	if(m_row = mysql_fetch_row(m_res))
		return atoi(m_row[0]);
		
}

int check()
{
	init_check_data();
	connect_mysql();
	MYSQL_ROW m_row; 
	MYSQL_RES *m_res; 
	char sql[LONG_BUFF]; 
	int i,j;
	/*First we should update the member information */
	int m_id=member_z.id;
	sprintf(sql,"select * from member_admin where mc_grant<>%d and m_id=%d",GRANT_PASSERS_BY,m_id); 
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
		check_community_id[check_community_num]=atoi(m_row[1]);
		check_grant[check_community_num]=atoi(m_row[2]);
		check_per_num[check_community_num]=per_num(atoi(m_row[1]));
		check_community_num++;
	}
	printf("%d ",check_community_num);fflush(stdin);
	/* check_activity_num*/
	sprintf(sql,"select count(*) from activity_list where m_id=%d",m_id);
	if(mysql_query(&mysql,sql) != 0){
		printf("mysql_query");
		return FAIL;
	} 
	m_res = mysql_store_result(&mysql); 
	if(m_res==NULL){
		printf("get result err"); 
		return FAIL;
	}
	if(m_row = mysql_fetch_row(m_res))
		check_activity_num=atoi(m_row[0]);
	
	/* check_apply_num */
	for(i=0;i<check_community_num;i++){
		if(check_grant[i]==GRANT_CM){
			sprintf(sql,"select count(*) from member_admin where c_id=%d and mc_grant=%d",check_community_id[i],GRANT_PASSERS_BY);
			if(mysql_query(&mysql,sql) != 0){
				printf("mysql_query");
				return FAIL;
			} 
			m_res = mysql_store_result(&mysql); 
			if(m_res==NULL){
				printf("get result err"); 
				return FAIL;
			}
			if(m_row = mysql_fetch_row(m_res))
				check_apply_num+=atoi(m_row[0]);
		}
	}
		
	/* check_apply_activity_num */
	if(!strcmp(member_z.name,"root")){
		sprintf(sql,"select count(*) from activity_info where a_state=%d",0);
		if(mysql_query(&mysql,sql) != 0){
			printf("mysql_query");
			return FAIL;
		} 
		m_res = mysql_store_result(&mysql); 
		if(m_res==NULL){
			printf("get result err"); 
			return FAIL;
		}
		if(m_row = mysql_fetch_row(m_res))
			check_apply_activity_num=atoi(m_row[0]);
	}	
	/* check_info_num */
	for(i=0;i<check_community_num;i++){
		sprintf(sql,"select count(*) from info_diffusion where c_id=%d",check_community_id[i]);
		if(mysql_query(&mysql,sql) != 0){
			printf("mysql_query");
			return FAIL;
		} 
		m_res = mysql_store_result(&mysql); 
		if(m_res==NULL){
			printf("get result err"); 
			return FAIL;
		}
		if(m_row = mysql_fetch_row(m_res))
			check_info_num+=atoi(m_row[0]);
	}
	close_mysql();
	/*state security*/
	return 1;
	
}

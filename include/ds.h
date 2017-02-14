#ifndef DS_H
#define DS_H

/*important DS */

#define NAME_LENGTH 40
#define SNO_LENGTH 20
#define SEX_LENGTH 4
#define PHONE_LENGTH 15
#define PASSWORD_LENGTH 40
#define RESERVE_LENGTH 255
#define INITSTATE 0

#define ONLINE 1
#define NOONLINE 0
struct member{
/* basic individual information */
	int id;
	char name[NAME_LENGTH];
	char sno[SNO_LENGTH];
	char sex[SEX_LENGTH];
	char phone[PHONE_LENGTH];
	char password[PASSWORD_LENGTH];
	int state;//whether online
	char m_reserve[RESERVE_LENGTH];
};
#define PER_MEMBER_NUM 10
struct member member_z;
struct member member_a[PER_MEMBER_NUM];
struct member member_i[PER_MEMBER_NUM];
int apply_num;
int in_num[PER_MEMBER_NUM];
struct member_admin{
	int m_id;//member 
	int c_id;//community
	int grant;
	char ma_reserve[RESERVE_LENGTH];
};
struct member_admin member_admin_z;

#define TEXT_LENGTH 1024
#define DATA_LENGTH 100
struct info_diffusion{
	int i_id;//information
	int m_id;//member
	int c_id;//community
	char i_text[TEXT_LENGTH];
	char i_data[DATA_LENGTH];
	char i_reserve[RESERVE_LENGTH];
};
#define PER_MESSAGE_NUM 10
struct info_diffusion info_diffusion_z;
struct info_diffusion message_i[PER_MESSAGE_NUM];
int message_in_num[PER_MESSAGE_NUM];
struct community{
	int c_id;
	char c_name[NAME_LENGTH];
	char c_data[DATA_LENGTH];
	char c_phone[PHONE_LENGTH];
	int master_no;
	char c_information[TEXT_LENGTH];
	char c_reserve[RESERVE_LENGTH];
};
#define PER_COMMUNITY_NUM 10
struct community community_z[PER_COMMUNITY_NUM];
int community_num;
struct activity_list{
	int a_id;//activity
	int c_id;//community
	int m_id;//member
	char al_reserve[RESERVE_LENGTH];
};
struct activity_list activity_list_z;
#define ADDRESS_LENGTH 40
struct activity{
	int a_id;
	char a_name[NAME_LENGTH];
	char a_address[ADDRESS_LENGTH];
	char a_data[DATA_LENGTH];
	float a_time;
	int a_state;
	char a_reserve[RESERVE_LENGTH];
};
struct activity activity_z;
#endif

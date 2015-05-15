#ifndef DS_H
#define DS_H

/*important DS */

#define NAME_LENGTH 40
#define SNO_LENGTH 20
#define SEX_LENGTH 4
#define PHONE_LENGTH 15
#define PASSWORD_LENGTH 40
#define INITSTATE 0
struct member{
	int id;
	char name[NAME_LENGTH];
	char sno[SNO_LENGTH];
	char sex[SEX_LENGTH];
	char phone[PHONE_LENGTH];
	char password[PASSWORD_LENGTH];
	int state;
};


#endif

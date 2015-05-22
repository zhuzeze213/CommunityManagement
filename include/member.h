#ifndef SQLMEMBER_H
#define SQLMEMBER_H
#include "ds.h"
#include "normal.h"
#include "connect.h"
int __addmember(struct member *addone);

int __verifyaccount(char username[NAME_LENGTH],char password[PASSWORD_LENGTH]);

int __getinformation(char username[NAME_LENGTH]);

int __setstate(char username[NAME_LENGTH],int state);
#endif

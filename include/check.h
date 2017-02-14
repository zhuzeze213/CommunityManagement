#ifndef CHECK_H
#define CHECK_H

#include "ds.h"
#include "normal.h"
#include "connect.h"

#define SYSTEMINFO 0 //i_baoliu

#define STATEERROR 0 //i_text
#define STATEERRORCAPTION "Someone want to login!"

#define NEWAPPLY 1
#define NEWAPPLYCAPTION "Someone apply community!"

#define HAVEAPPLY 2
#define HAVEAPPLYCAPTION "Your apply pass!"

#define NEWINFO 3
#define NEWINFOCAPTION "You have new info!"

#define NEWACTIVITY 4
#define NEWACTIVITYCAPTION "You have new activity apply!"

#define HAVEACTIVITY 5
#define HAVEACTIVITYCAPTION "You have new activity!"

#define MAX_COMMUNITY_NUM 10
int check_community_num;
int check_community_id[MAX_COMMUNITY_NUM];
int check_grant[MAX_COMMUNITY_NUM];
int check_per_num[MAX_COMMUNITY_NUM];
int check_activity_num;
int check_apply_num;
int check_apply_activity_num;
int check_info_num;

int check();
#endif
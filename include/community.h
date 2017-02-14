#ifndef COMMUNITY_H
#define COMMUNITY_H

#include "ds.h"
#include "normal.h"
#include "connect.h"
#include "check.h"

int __lookcommunity();

int __findcommunity(int id);

int __applycommunity(int id);

int __lookapply();

int __agreeapply(int id,int c_id);

int __refuseapply(int id,int c_id);

int __lookmember();

int __findmember(int id);

int __deletemember(int id,int c_id);
#endif

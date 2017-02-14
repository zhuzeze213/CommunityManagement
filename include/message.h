#ifndef SQLMESSAGE_H
#define SQLMESSAGE_H
#include "ds.h"
#include "normal.h"
#include "connect.h"
#include "check.h"
int __sendmessage(struct info_diffusion *addone);

int __receivemessage();
#endif

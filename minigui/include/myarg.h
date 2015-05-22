#ifndef MYARG_H
#define MYARG_H

#include "mainmenu.h"
#include "login.h"
#include "addmember.h"
#include "util.h"
#include "lookinformation.h"
#include "../../include/member.h"

/*important variables*/
char user_name[NAME_LENGTH];
int user_grant;//we should change it
#define GRANT_ROOT 0
#define GRANT_CM 1
#define GRANT_NM 2
#define GRANT_PASSERS_BY 3

/*The template data in login */
DLGTEMPLATE DlgLogin;
CTRLDATA CtrlLogin[LOGIN_ELEMENT_NUM];

/*The template data in addmember */
DLGTEMPLATE DlgAddmember;
CTRLDATA CtrlAddmember[ADDMEMBER_ELEMENT_NUM];

/*The template data in lookinformation */
DLGTEMPLATE DlgLookInformation;
CTRLDATA CtrlLookInformation[LOOKINFORMATION_ELEMENT_NUM];
/*The following arg is normal! */
#define ID_TIMER 50
#define TIME_FLUSH 100

#define WORD_HEIGHT 20

/*The following arg is describing the mainui!*/
#define PROJECT_NAME "The School Community Management System"
#define MAINHICON 0
#define MAINLX 50
#define MAINTY 50
#define MAINRX 500
#define MAINBY 300
#define DWADDDATA 0

#endif

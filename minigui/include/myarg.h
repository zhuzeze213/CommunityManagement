#ifndef MYARG_H
#define MYARG_H

#include "mainmenu.h"
#include "login.h"
#include "addmember.h"
#include "lookmember.h"
#include "findmember.h"
#include "deletemember.h"
#include "util.h"
#include "lookinformation.h"
#include "addcommunity.h"
#include "lookcommunity.h"
#include "findcommunity.h"
#include "applycommunity.h"
#include "lookapply.h"
#include "sendmessage.h"
#include "receivemessage.h"
#include "../../include/member.h"
#include "../../include/community.h"
#include "../../include/check.h"
#include "../../include/message.h"

/*important variables*/
char user_name[NAME_LENGTH];
int user_grant;//we should change it

/*The template data in login */
DLGTEMPLATE DlgLogin;
CTRLDATA CtrlLogin[LOGIN_ELEMENT_NUM];

/*The template data in addmember */
DLGTEMPLATE DlgAddmember;
CTRLDATA CtrlAddmember[ADDMEMBER_ELEMENT_NUM];

/*The template data in findmember */
DLGTEMPLATE DlgFindMember;
CTRLDATA CtrlFindMember[FINDMEMBER_ELEMENT_NUM];

/*The template data in lookmember */
DLGTEMPLATE DlgLookMember;
CTRLDATA CtrlLookMember[LOOKMEMBER_ELEMENT_NUM];

/*The template data in deletemember */
DLGTEMPLATE DlgDeleteMember;
CTRLDATA CtrlDeleteMember[DELETEMEMBER_ELEMENT_NUM];

/*The template data in lookinformation */
DLGTEMPLATE DlgLookInformation;
CTRLDATA CtrlLookInformation[LOOKINFORMATION_ELEMENT_NUM];

/*The template data in addcommunity */
DLGTEMPLATE DlgAddCommunity;
CTRLDATA CtrlAddCommunity[ADDCOMMUNITY_ELEMENT_NUM];

/*The template data in lookcommunity */
DLGTEMPLATE DlgLookCommunity;
CTRLDATA CtrlLookCommunity[LOOKCOMMUNITY_ELEMENT_NUM];

/*The template data in findcommunity */
DLGTEMPLATE DlgFindCommunity;
CTRLDATA CtrlFindCommunity [FINDCOMMUNITY_ELEMENT_NUM];

/*The template data in applycommunity */
DLGTEMPLATE DlgApplyCommunity;
CTRLDATA CtrlApplyCommunity[APPLYCOMMUNITY_ELEMENT_NUM];

/*The template data in applycommunity */
DLGTEMPLATE DlgLookApply;
CTRLDATA CtrlLookApply[LOOKAPPLY_ELEMENT_NUM];

/*The template data in sendmessage */
DLGTEMPLATE DlgSendMessage;
CTRLDATA CtrlSendMessage[SENDMESSAGE_ELEMENT_NUM];

/*The template data in receivemessage */
DLGTEMPLATE DlgReceiveMessage;
CTRLDATA CtrlReceiveMessage[RECEIVEMESSAGE_ELEMENT_NUM];

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

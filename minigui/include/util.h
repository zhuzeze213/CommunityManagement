/* This head file include the name of functions in ../../src */
#ifndef UTIL_H
#define UTIL_H

#include "../../include/normal.h"
#include "../../include/check.h"

HMENU createmenu(void);

int LoginBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int AddmemberBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int LookInformationBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int AddCommunityBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int LookCommunityBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int FindCommunityBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int ApplyCommunityBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int LookApplyBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int LookMemberBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int FindMemberBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int DeleteMemberBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int SendMessageBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int ReceiveMessageBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);
/* The following function is get someone 's community id if he is community master!*/
static inline int getcm()
{
	int c_id=FAIL,i;
	for(i=0;i<check_community_num;i++){
		if(check_grant[i]==GRANT_CM){
			c_id=check_community_id[i];
			break;
		}
	}
	return c_id;
} 

#endif

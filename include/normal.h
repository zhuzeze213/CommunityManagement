#ifndef NORMAL_H
#define NORMAL_H

/*some std head files */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <mysql/mysql.h>
#include <syslog.h>

#include<minigui/common.h>
#include<minigui/minigui.h>
#include<minigui/gdi.h>
#include<minigui/window.h>
#include<minigui/control.h>

/*grant*/
#define GRANT_ROOT 0
#define GRANT_CM 1
#define GRANT_NM 2
#define GRANT_PASSERS_BY 3
/*normal parameter */

#define FAIL -1
#define SUCCESS 0
#define SHORT_BUFF 20
#define MID_BUFF 100
#define LONG_BUFF 1024
#define LONG_LONG_BUFF 10240
#endif

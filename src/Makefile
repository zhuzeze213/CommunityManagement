LIB_RED_HAT=-lpthread -lminigui_ths -ljpeg -lpng -lz -lm -ldl -lpciaccess
LIBS=-L/usr/local/lib -lminigui_ths -lpciaccess -ljpeg -lpng -ldl -lm -lpthread  -L/usr/lib/mysql -lmysqlclient -lz
CC=gcc
CFLAGS=-c -g
OBJS=mainui.o ../lib/member.o ../lib/community.o ../lib/check.o ../lib/message.o ../lib/mainmenu.o ../lib/login.o ../lib/addmember.o ../lib/lookmember.o ../lib/findmember.o ../lib/deletemember.o ../lib/lookinformation.o ../lib/addcommunity.o ../lib/lookcommunity.o ../lib/findcommunity.o ../lib/applycommunity.o ../lib/lookapply.o ../lib/sendmessage.o ../lib/receivemessage.o

mainui:$(OBJS)
	$(CC) $(OBJS) $(LIBS) -o mainui

../lib/mainmenu.o:../minigui/lib/mainmenu.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/mainmenu.c -o ../lib/mainmenu.o

../lib/lookinformation.o:../minigui/lib/lookinformation.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/lookinformation.c -o ../lib/lookinformation.o
	
../lib/login.o:../minigui/lib/login.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/login.c -o ../lib/login.o	

../lib/addmember.o:../minigui/lib/addmember.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/addmember.c -o ../lib/addmember.o

../lib/lookmember.o:../minigui/lib/lookmember.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/lookmember.c -o ../lib/lookmember.o
	
../lib/findmember.o:../minigui/lib/findmember.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/findmember.c -o ../lib/findmember.o

../lib/deletemember.o:../minigui/lib/deletemember.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/deletemember.c -o ../lib/deletemember.o
	
../lib/addcommunity.o:../minigui/lib/addcommunity.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/addcommunity.c -o ../lib/addcommunity.o
	
../lib/lookcommunity.o:../minigui/lib/lookcommunity.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/lookcommunity.c -o ../lib/lookcommunity.o

../lib/findcommunity.o:../minigui/lib/findcommunity.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/findcommunity.c -o ../lib/findcommunity.o
	
../lib/applycommunity.o:../minigui/lib/applycommunity.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/applycommunity.c -o ../lib/applycommunity.o

../lib/lookapply.o:../minigui/lib/lookapply.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/lookapply.c -o ../lib/lookapply.o
	
../lib/sendmessage.o:../minigui/lib/sendmessage.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/sendmessage.c -o ../lib/sendmessage.o

../lib/receivemessage.o:../minigui/lib/receivemessage.c ../minigui/include/myarg.h
	$(CC) $(CFLAGS) ../minigui/lib/receivemessage.c -o ../lib/receivemessage.o
	
../lib/community.o:../lib/community.c ../include/community.h
	$(CC) $(CFLAGS) ../lib/community.c -o ../lib/community.o
	
../lib/member.o:../lib/member.c ../include/member.h
	$(CC) $(CFLAGS) ../lib/member.c -o ../lib/member.o

../lib/check.o:../lib/check.c ../include/check.h
	$(CC) $(CFLAGS) ../lib/check.c -o ../lib/check.o
	
../lib/message.o:../lib/message.c ../include/message.h
	$(CC) $(CFLAGS) ../lib/message.c -o ../lib/message.o
	
mainui.o:mainui.c ../minigui/include/myarg.h ../include/member.h
	$(CC) $(CFLAGS) mainui.c -o mainui.o
	
clean:
	rm -rf ../lib/*.o ./*.o mainui

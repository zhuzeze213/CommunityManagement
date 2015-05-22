LIB_RED_HAT=-lpthread -lminigui_ths -ljpeg -lpng -lz -lm -ldl -lpciaccess
LIBS=-L/usr/local/lib -lminigui_ths -lpciaccess -ljpeg -lpng -ldl -lm -lpthread  -L/usr/lib/mysql -lmysqlclient -lz
CC=gcc
CFLAGS=-c
OBJS=mainui.o ../lib/mainmenu.o ../lib/login.o ../lib/addmember.o ../lib/member.o ../lib/lookinformation.o

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
	
../lib/member.o:../lib/member.c ../include/member.h
	$(CC) $(CFLAGS) ../lib/member.c -o ../lib/member.o
	
mainui.o:mainui.c ../minigui/include/myarg.h ../include/member.h
	$(CC) $(CFLAGS) mainui.c -o mainui.o
	
clean:
	rm -rf ../lib/*.o ./*.o mainui

default: LocalHostInfo.obj
	link LocalHostInfo.obj ws2_32.lib iphlpapi.lib
LocalHostInfo.obj: LocalHostInfo.c
	cl -c LocalHostInfo.c

CC=i486-mingw32-gcc
gcc: LocalHostInfo.o
	$(CC) -o LocalHostInfo.exe LocalHostInfo.o -lws2_32 -liphlpapi
LocalHostInfo.c.o: LocalHostInfo.c
	$(CC) -c LocalHostInfo.c

.PHONY:clean
clean:
	rm -f LocalHostInfo.o LocalHostInfo.obj LocalHostInfo.exe

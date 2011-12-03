default: LocalhostInfo.obj
	link LocalhostInfo.obj ws2_32.lib iphlpapi.lib
LocalhostInfo.obj: LocalhostInfo.c
	cl -c LocalhostInfo.c

gcc: LocalhostInfo.o
	gcc -o LocalhostInfo.exe LocalhostInfo.o -lws2_32 -liphlpapi
LocalhostInfo.o: LocalhostInfo.c
	gcc -c LocalhostInfo.c

.PHONY:clean
clean:
	rm -f LocalhostInfo.o LocalhostInfo.obj LocalhostInfo.exe

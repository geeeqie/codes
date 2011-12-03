all: Server.obj
	link Server.obj ws2_32.lib
Server.obj: Server.c
	cl -c Server.c

clean:
	rm -f Server.obj Server.exe

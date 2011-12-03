all: Client.obj
	link Client.obj ws2_32.lib
Client.obj: Client.c
	cl -c Client.c

clean:
	rm -f Client.obj Client.exe

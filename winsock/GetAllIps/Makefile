all: GetAllIps.obj
	link GetAllIps.obj ws2_32.lib
GetAllIps.obj: GetAllIps.c
	cl -c GetAllIps.c

clean:
	rm -f GetAllIps.obj rm GetAllIps.exe

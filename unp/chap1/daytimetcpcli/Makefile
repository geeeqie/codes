APP=daytimetcpcli
LIB=../../lib
LIB_FILE=$(LIB)/error.c
CFLAGS+=-I$(LIB)
default: $(APP).c $(LIB_FILE)
	gcc -g $(CFLAGS) $(APP).c $(LIB_FILE)
clean:
	rm -f a.out a.exe

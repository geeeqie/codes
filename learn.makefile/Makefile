objects=main.o kbd.o command.o display.o insert.o search.o files.o utils.o

edit: $(objects)
	cc -o edit $(objects)
$(objects):defs.h

.PHONY:clean
clean:
	rm edit $(objects)

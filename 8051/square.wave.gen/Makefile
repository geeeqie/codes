objs=square_wave_gen.o os.o
CC=sdcc
default: square_wave_gen.rel os.rel
	$(CC) square_wave_gen.rel os.rel
	packihx square_wave_gen.ihx > square_wave_gen.hex
	objcopy -Iihex -Obinary square_wave_gen.hex square_wave_gen.bin
square_wave_gen.rel: square_wave_gen.c os.h
	$(CC) -c square_wave_gen.c
os.rel: os.c os.h
	$(CC) -c os.c

.PHONY:clean
clean:
	rm -f os.asm os.ihx os.lnk os.lst os.map os.mem os.rel os.rst os.sym square_wave_gen.asm square_wave_gen.lst square_wave_gen.rel square_wave_gen.sym square_wave_gen.ihx  square_wave_gen.lnk  square_wave_gen.map  square_wave_gen.mem  square_wave_gen.rst square_wave_gen.bin square_wave_gen.hex

APP=square_wave_gen
default: os.obj $(APP).obj
	bl51 $(APP).OBJ,os.OBJ
	oh51 $(APP)

os.obj: os.c os.h
	c51 os.c
$(APP).obj: $(APP).c
	c51 $(APP).c

clean:
	rm -f os.LST
	rm -f os.OBJ
	rm -f $(APP).OBJ
	rm -f $(APP).LST
	rm -f $(APP).hex
	rm -f $(APP).M51
	rm -f $(APP)

APP=radio
CFLAGS=--model-large
default:
	sdcc $(CFLAGS) $(APP).c
	packihx $(APP).ihx > $(APP).hex
clean:
	rm -f $(APP).{asm,hex,ihx,lnk,lst,map,mem,rel,rst,sym}

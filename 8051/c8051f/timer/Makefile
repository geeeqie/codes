APP=timer
default:
	sdcc $(APP).c
	packihx $(APP).ihx > $(APP).hex
clean:
	rm $(APP).{asm,hex,ihx,lnk,lst,map,mem,rel,rst,sym}

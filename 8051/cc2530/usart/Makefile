APP=usart
default:
	sdcc $(APP).c
	packihx $(APP).ihx > $(APP).hex
clean:
	rm -f $(APP).{asm,hex,ihx,lnk,lst,map,mem,rel,rst,sym,cdb,lk,omf}

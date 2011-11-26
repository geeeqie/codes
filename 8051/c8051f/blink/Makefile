APP=blink
default: $(APP).c
	sdcc $(APP).c
	packihx $(APP).ihx > $(APP).hex
clean:
	rm $(APP).asm $(APP).ihx $(APP).lst $(APP).map $(APP).mem $(APP).rel $(APP).rst $(APP).sym $(APP).lnk $(APP).hex

default: timer.c
	avr-gcc -mmcu=atmega64 timer.c
burn:
	avr-objcopy --output-target=srec a.out a.srec
	avrdude -cstk500v2 -P/dev/ttyUSB0 -U hfuse:w:0xd1:m -pm64 -U efuse:w:0xff:m  -U flash:w:a.srec:a

.PHONY:clean
clean:
	rm a.out
	rm a.srec

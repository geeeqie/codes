default: sleep.status.c
	avr-gcc sleep.status.c -mmcu=atmega1281
burn: a.out
	avr-objcopy --output-target=srec a.out a.srec
	avrdude -cstk500v2 -P/dev/tts/USB0 -U hfuse:w:0xd9:m -pm1281 -U efuse:w:0xff:m -C/etc/avrdude/avrdude.conf  -U flash:w:a.srec:a

clean:
	rm a.srec a.out


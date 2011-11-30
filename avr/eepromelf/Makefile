APP=eepromelf
default: $(APP).c
	avr-gcc -mmcu=atmega1281 -Os $(APP).c
burn:
	avr-objcopy --output-target=srec a.out a.srec
	avrdude -cstk500v2 -P/dev/tts/USB0 -U hfuse:w:0xd1:m -pm1281 -U efuse:w:0xff:m  -U flash:w:a.srec:a

clean:
	rm -f a.out a.srec

obj-m := hello.o
KDIR=/usr/src/linux-$(shell uname -r)

default:
	 make -C $(KDIR) M=$(PWD) modules
clean:
	 make -C $(KDIR) M=$(PWD) modules clean

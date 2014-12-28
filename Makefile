KDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

$(info building with ${KDIR})
obj-m += hello.o

all:
        make -C $(KDIR) M=$(PWD) modules

clean:
        make -C $(KDIR) M=$(PWD) clean

Debian based build:
```shell
apt-get install bc fakeroot build-essential kernel-package libncurses5-dev -y
git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
cd linux 
cp /boot/config-`uname -r` ./.config
```

patch for CONFIG_LOCALVERSION_AUTO:
```shell
55c55
< # CONFIG_LOCALVERSION_AUTO is not set
---
> CONFIG_LOCALVERSION_AUTO=y
```
apply it:
``` patch .config < config_auto.patch```

build it "raw" way:
```
yes "" | make localmodconfig
make -j$(cat /proc/cpuinfo|grep processor|wc -l) && make modules
make modules_install
make install
```

or debian way:
```shell
fakeroot make-kpkg --initrd kernel_image kernel_headers
cd ..
dpkg -i linux-image
```

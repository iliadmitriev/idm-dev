# Requiremenst

Unbuntu 20 x86_64/aarc64

# Prepare

1. clone repository
2. install needed packages
```shell
sudo apt install linux-headers-generic build-essential
```

# Build

1. make
```shell
make
```
2. make clean
```shell
make clean
```

# Install

# Usage

1. insert module to kernel
```shell
sudo insmod idm_dev.ko 
```

2. log module messages
```shell
tail -f /var/log/kern.log
```

3. unload module
```shell
sudo rmmod idm_dev
```

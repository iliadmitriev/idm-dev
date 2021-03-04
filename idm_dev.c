#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "idmdev"

static int dev_open(struct inode*, struct file*);
static int dev_release(struct inode*, struct file*);
static ssize_t dev_read(struct file*, char*, size_t, loff_t*);
struct ssize_t dev_write(struct file*, const char*, size_t, loff_t*);


static struct file_operations fops={
	.open = dev_open,
	.read = dev_read,
	.write = dev_write,
	.release = dev_release,
};

static int major;

static int __init idm_dev_init(void) {
	major = register_chrdev(0, DEVICE_NAME, &fops);
	
	if (major < 0) {
		printk(KERN_ALERT "IDM device load failed");
		return major;
	}
	
	printk(KERN_INFO "IDM device module loaded\n");
	return 0;
}


static void __exit idm_dev_exit(void) {
	unregister_chrdev(major, DEVICE_NAME);
	printk(KERN_INFO "IDM device module unloaded\n");
}

static int dev_open(struct inode*, struct file*) {
	printk(KERN_INFO "IDM device opened");
	return 0;
}

static int dev_release(struct inode*, struct file*) {
	printk(KERN_INFO "IDM device closed (released)");
	return 0;
}

static ssize_t dev_read(struct file*, char*, size_t, loff_t*) {
	int errors  = 0;
	char *message = "IDM static read message";
	int message_len = strlen(message);
	
	errors = copy_to_user(buffer, message, message_len);
	
	return errors == 0 ? message_len : -EFAULT;
}

struct ssize_t dev_write(struct file*, const char*, site_t, loff_t*) {
	printk(KERN_INFO "IDM is a readonly device");
	return -EFAULT;

}

module_init(idm_dev_init)
module_exit(idm_dev_exit)


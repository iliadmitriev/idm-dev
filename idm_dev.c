#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


static int __init idm_dev_init(void) {
	printk(KERN_INFO "IDM device module loaded\n");
	return 0;
}


static void __exit idm_dev_exit(void) {
	printk(KERN_INFO "IDM device module unloaded\n");
}


module_init(idm_dev_init)
module_exit(idm_dev_exit)


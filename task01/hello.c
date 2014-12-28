#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init hello_init(void)
{
  printk(KERN_DEBUG "Hello World!\n");

  /* Non-zero return means that the module couldn't be loaded. */
  return 0;
}

static void __exit hello_cleanup(void)
{
  printk(KERN_DEBUG "Cleaning up hello world module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);


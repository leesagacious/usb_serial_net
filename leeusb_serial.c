
struct kmem_cache *tty_driver_cache;

struct tty_driver * alloc_tty_driver(unsigned int index)
{
  struct tty_driver * driver;
  
  /* alloc */
#if 0  
  driver = kzalloc(sizeof *driver, GFP_KERNEL):
  if (!driver)
    return -ENOMEM;
#endif

  driver = kmem_cache_alloc(tty_driver_cache, GFP_KERNEL | __GFP_ZERO);
  if (!driver)
      return NULl;
    
}

static int __init usb_serial_init(void)
{
    tty_driver_cache =  kmem_cache_create("tty_driver_cache", sizeof(struct tty_driver), 0, SLAB_PANIC, NULL);
    if (!tty_driver_cache)
        goto kmem_cache_panic;
    
    
  
  kmem_cache_panic:
      panic("kmem_cache_create tty_driver has failure\n");
}
/*
  Loading priority is higher than module_init
*/
arch_initcall(usb_serial_init);

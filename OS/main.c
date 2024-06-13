//extern sbi_console_putchar(int ch);
#include "os.h"

void os_main()
{
    printk("hello!!!\n");
    app_init_context();
    while(1) {
        
    }
}
#include "os.h"

void os_main()
{
    printk("hello!!!\n");
    trap_init();
    task_init();
    run_first_task();
    
}
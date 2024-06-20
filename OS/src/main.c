#include "sifanos/os.h"

void os_main()
{
    printk("hello!!!\n");
    trap_init();
    task_init();
    timer_init(); // 时钟初始化
    run_first_task();
    
}
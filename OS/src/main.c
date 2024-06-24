#include "sifanos/os.h"

extern void frame_allocator_test();
extern void kvminit();
extern void kvminithart();


void os_main()
{
    printk("hello!!!\n");

    frame_allocator_init();    
    kvminit();
    kvminithart();

    trap_init();
    task_init();
    timer_init(); // 时钟初始化
    //run_first_task();
    
}
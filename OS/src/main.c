#include "sifanos/os.h"

extern void frame_allocator_test();

void os_main()
{
    printk("hello!!!\n");
    frame_allocator_test();    
    while(1) {
        
    }
    //trap_init();
    //task_init();
    //timer_init(); // 时钟初始化
    //run_first_task();
    
}
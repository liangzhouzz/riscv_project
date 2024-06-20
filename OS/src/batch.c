#include <stddef.h>
#include "sifanos/os.h"
#include "context.h"
#define USER_STACK_SIZE (4096 * 2)
#define KERNEL_STACK_SIZE (4096 * 2)
#define APP_BASE_ADDRESS 0x80600000


size_t syscall(size_t id, reg_t arg1, reg_t arg2, reg_t arg3) {
    long ret;
    asm volatile (
        "mv a7, %1\n\t"   // Move syscall id to a7 register
        "mv a0, %2\n\t"   // Move args[0] to a1 register
        "mv a1, %3\n\t"   // Move args[1] to a2 register
        "mv a2, %4\n\t"   // Move args[2] to a3 register
        "ecall\n\t"       // Perform syscall
        "mv %0, a0"       // Move return value to 'ret' variable
        : "=r" (ret)
        : "r" (id), "r" (arg1), "r" (arg2), "r" (arg3)
        : "a7", "a0", "a1", "a2", "memory"
    );
    return ret;
}

void testsys() {
    const char *message = "Hello, RISC-V!\n";
    int len = strlen(message);
    int ret = syscall(0x40,1,message, len);
    while (1)
    {
        /* code */
    }
}


uint8_t KernelStack[KERNEL_STACK_SIZE];
uint8_t UserStack[USER_STACK_SIZE];

extern void __restore(trap_Context *next);

struct trap_Context tasks;
void app_init_context()
{

    reg_t user_sp = &UserStack + USER_STACK_SIZE;
    //printk("user_sp:%p\n", user_sp);

    //reg_t stvec = r_stvec();
    //printk("stvec:%x\n", stvec);


    trap_init();

    reg_t sstatus = r_sstatus();
    // 设置 sstatus 寄存器第8位即SPP位为0 表示为U模式
    sstatus &= (0U << 8);
    w_sstatus(sstatus);
    //printk("sstatus:%x\n", sstatus);


    tasks.sepc = (reg_t)testsys;
    //printk("tasks sepc:%x\n", tasks.sepc);

    tasks.sstatus = sstatus;

    tasks.sp = user_sp;



    trap_Context* cx_ptr = &KernelStack[0] + KERNEL_STACK_SIZE - sizeof(trap_Context);
    //printk("pt_regs: %d\n",sizeof(trap_Context));
    cx_ptr->sepc = tasks.sepc;
    //printk("cx_ptr sepc :%x\n", cx_ptr->sepc);
    //printk("cx_ptr sepc adress:%x\n", &(cx_ptr->sepc));
    cx_ptr->sstatus = tasks.sstatus;
    cx_ptr->sp = tasks.sp;
    // *cx_ptr = tasks[0];
    //printk("cx_ptr adress:%x\n", cx_ptr);

    __restore(cx_ptr); 

}

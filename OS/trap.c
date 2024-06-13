#include "os.h"
#include "context.h"
#include "riscv.h"

extern void __alltraps(void);

pt_regs* trap_handler(pt_regs* cx)
{
    reg_t scause = r_scause() ;
    printk("cause:%x\n",scause);
	printk("a0:%x\n",cx->a0);
	printk("a1:%x\n",cx->a1);
	printk("a2:%x\n",cx->a2);
	printk("a7:%x\n",cx->a7);
	printk("sepc:%x\n",cx->sepc);
	printk("sstatus:%x\n",cx->sstatus);
	printk("sp:%x\n",cx->sp);
	while (1)
	{
	}
    return cx;
}


void trap_init()
{
	/*
	 * 设置 trap 时调用函数的基地址
	 */
	w_stvec((reg_t)__alltraps);
}
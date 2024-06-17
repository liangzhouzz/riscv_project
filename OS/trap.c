#include "os.h"
#include "context.h"
#include "riscv.h"

//extern void __alltraps(void);

trap_Context* trap_handler(trap_Context* cx)
{
    reg_t scause = r_scause();
	switch (scause)
	{
	case 8:
			__SYSCALL(cx->a7,cx->a0,cx->a1,cx->a2);
		break;
	default:
			printk("undfined scause:%d\n",scause);
			
		break;
	}
	
	cx->sepc += 8;

	return cx;
}


void trap_init()
{
	/*
	 * 设置 trap 时调用函数的基地址
	 */
	w_stvec((reg_t)__alltraps);
}
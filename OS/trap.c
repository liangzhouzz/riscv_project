#include "os.h"
#include "context.h"
#include "riscv.h"


trap_Context* trap_handler(trap_Context* cx)
{
    reg_t scause = r_scause();

	reg_t cause_code = scause & 0xfff;
	
	// 1 << 63 = 0x8000000000000000
	if (scause & 0x8000000000000000){
		// 中断模式
		switch (cause_code)
		{
		/* rtc 中断*/
		case 5:
			set_next_trigger();
			schedule();
			break;
		default:
			printk("undfined interrrupt scause:%x\n", scause);
			break;
		}
	} else {
		// 异常模式
		switch (cause_code)
		{
		/* U模式下的syscall */
		case 8:
			cx->a0 = __SYSCALL(cx->a7,cx->a0,cx->a1,cx->a2);
			cx->sepc += 8;
			break;
		default:
			printk("undfined exception scause:%x\n",scause);
			break;
		}

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
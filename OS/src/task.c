#include "sifanos/os.h"
#define USER_STACK_SIZE (4096 * 2)
#define KERNEL_STACK_SIZE (4096 * 2)
#define MAX_TASKS 10   /* 操作系统支持的最大任务数量 */
uint8_t KernelStack[MAX_TASKS][KERNEL_STACK_SIZE]; /* 任务内核栈 */
uint8_t UserStack[MAX_TASKS][USER_STACK_SIZE];     /* 任务用户栈 */

static int _current = 0;
static int _top = 0;

struct TaskControlBlock tasks[MAX_TASKS];   // 任务数组，保存上下文和状态

struct task_Context tcx_init(reg_t kstack_ptr) {
    struct task_Context task_ctx;

    task_ctx.ra = __restore;
    task_ctx.sp = kstack_ptr;
    task_ctx.s0 = 0;
    task_ctx.s1 = 0;
    task_ctx.s2 = 0;
    task_ctx.s3 = 0;
    task_ctx.s4 = 0;
    task_ctx.s5 = 0;
    task_ctx.s6 = 0;
    task_ctx.s7 = 0;
    task_ctx.s8 = 0;
    task_ctx.s9 = 0;
    task_ctx.s10 = 0;
    task_ctx.s11 = 0;

    return task_ctx;
}

void task_create(void (*task_entry)(void))
{
    if(_top < MAX_TASKS)
    {
        /* 对于每个任务先构造该任务的trap上下文，包括入口地址和用户栈指针，并将其压入到内核栈顶*/
        trap_Context* cx_ptr = (trap_Context*)((uint8_t*)(&KernelStack[_top]) + KERNEL_STACK_SIZE - sizeof(trap_Context));
        reg_t user_sp = &UserStack[_top] + USER_STACK_SIZE;
        reg_t stvec = r_stvec();
        reg_t sstatus = r_sstatus();
        // 设置 sstatus 寄存器第8位即SPP位为0 表示为U模式
        sstatus &= (0U << 8);
        w_sstatus(sstatus);
        /* 设置用户程序内核栈 ，填充用户栈指针*/
        cx_ptr->sepc = (reg_t)task_entry;
        cx_ptr->sstatus = sstatus; 
        cx_ptr->sp = user_sp;

       /* 构造每个任务任务控制块中的任务上下文，设置 ra 寄存器为 __restore 的入口地址*/
        tasks[_top].task_context = tcx_init((reg_t)cx_ptr);
        // 初始化 TaskStatus 字段为 Ready
        tasks[_top].task_state = Ready;

        _top++;
        //__restore(cx_ptr); 

    }
}

void schedule()
{
	if (_top <= 0) {
		panic("Num of task should be greater than zero!\n");
		return;
	}

    /* 轮转调度 */
    int next = _current + 1;
    next = next % _top;

    if(tasks[next].task_state == Ready)
    {
        struct task_Context *current_task_cx_ptr = &(tasks[_current].task_context);
        struct task_Context *next_task_cx_ptr = &(tasks[next].task_context);
        tasks[next].task_state = Running;
        tasks[_current].task_state = Ready;
        _current = next;
        __switch(current_task_cx_ptr,next_task_cx_ptr);  // 切换
    }

}

void run_first_task()
{
    tasks[0].task_state = Running;
    struct task_Context *next_task_cx_ptr = &(tasks[0].task_context);
    struct task_Context _unused ;

    __switch(&_unused,next_task_cx_ptr);
    panic("unreachable in run_first_task!");
}


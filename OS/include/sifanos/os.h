#ifndef SOS__OS_H__
#define SOS__OS_H__


#include <stddef.h>
#include <stdarg.h>
#include "sifanos/types.h"
#include "sifanos/context.h"
#include "sifanos/riscv.h"
#include "sifanos/task.h"
#include "sifanos/stdio.h"
#include "sifanos/syscall.h"




/* trap.c */
extern void trap_init();

/* kerneltrap.S*/
extern void __alltraps(void);
extern void __restore(trap_Context* next);


/* switch*/
extern void __switch(task_Context *current_task_cx_ptr, task_Context* next_task_cx_ptr );

/* task.c*/
extern void schedule();
extern void task_create(void (*task_entry)(void));
extern void run_first_task();

/* app.c*/
extern void task_init();

/*timer*/
void sbi_set_timer(uint64_t stime_value);
void timer_init();
void set_next_trigger();
extern uint64_t get_time_us();

#endif /* __OS_H__ */
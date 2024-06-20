#ifndef SOS__TASK_H__
#define SOS__TASK_H__

#include "os.h"
typedef enum TaskState
{
	UnInit, // 未初始化
    Ready, // 准备运行
    Running, // 正在运行
    Exited, // 已退出
}TaskState;

typedef struct TaskControlBlock
{
    TaskState task_state; 
    task_Context task_context; 
}TaskControlBlock;

#endif

/*sbi.h*/
#ifndef __SBI_H__
#define __SBI_H__

enum sbi_ext_id {
	SBI_EXT_0_1_SET_TIMER = 0x0,                    // 设置定时器
	SBI_EXT_0_1_CONSOLE_PUTCHAR = 0x1,              // 输出一个字符
	SBI_EXT_0_1_CONSOLE_GETCHAR = 0x2,              // 获取一个字符
	SBI_EXT_0_1_CLEAR_IPI = 0x3,                    // 清除中断处理器间中断IPI
	SBI_EXT_0_1_SEND_IPI = 0x4,                     // 发送IPI
	SBI_EXT_0_1_REMOTE_FENCE_I = 0x5,               // 远程指令缓存刷新
	SBI_EXT_0_1_REMOTE_SFENCE_VMA = 0x6,            // 远程地址空间刷新
	SBI_EXT_0_1_REMOTE_SFENCE_VMA_ASID = 0x7,       // 远程地址刷新，基于ASID 地址空间标识符
	SBI_EXT_0_1_SHUTDOWN = 0x8,                     // 关闭系统
	
    SBI_EXT_BASE = 0x10,                            // 基本拓展
	SBI_EXT_TIME = 0x54494D45,                      // 时间管理扩展
	SBI_EXT_IPI = 0x735049,                         // ipi拓展
	SBI_EXT_RFENCE = 0x52464E43,                    // 远程内存屏障扩展
	SBI_EXT_HSM = 0x48534D,                         // 硬件状态机扩展
	SBI_EXT_SRST = 0x53525354,                      // 系统复位扩展
	SBI_EXT_PMU = 0x504D55,                         // 性能监控单元扩展
};

/* sbi 返回结构体*/
struct sbiret {
	long error;
	long value;
};

enum sbi_ext_time_fid {
	SBI_EXT_TIME_SET_TIMER = 0,
};

#define SBI_FID_SET_TIMER		SBI_EXT_TIME_SET_TIMER

#endif  
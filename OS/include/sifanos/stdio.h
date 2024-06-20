#ifndef SOS_STDIO_H__
#define SOS_STDIO_H__

#include <sifanos/os.h>

int _vsnprintf(char * out, size_t n, const char* s, va_list vl);
void panic(char *s);
int printk(const char* s, ...);
int printf(const char* s, ...);

/* 文件描述符 */
typedef enum std_fd_t
{
    stdin,  
    stdout,
    stderr,
} std_fd_t;

#endif
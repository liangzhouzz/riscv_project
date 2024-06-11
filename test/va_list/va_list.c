#include "stdio.h"
//将可变参数全部入栈
typedef void* Va_list;
//在64位系统栈帧分配的单元大小是8字节(一个参数占8字节)
#define Va_start(ap,v) (ap = (Va_list)&v )
#define Va_arg(ap,t) (*(t*)(ap += sizeof(t *)))
#define Va_end(ap) (ap = (Va_list)0)   //直接将Va_list 置为空指针


void print_str(int count, ...) {

#if 1 //i386
    /*这里就是复现上面可变参数的逻辑*/
    void* ap = (void*)&count;
    printf("%d\n", *(int *)ap);
    ap += sizeof(char**);
    printf("%s\n", *(char**)ap);
    ap += sizeof(char**);
    printf("%s\n", *(char**)ap);
    ap += sizeof(char**);
    printf("%s\n", *(char**)ap);
#else // riscv64
    void* ap = (void*)&fmt;
    printf("%s\n", *(int*)ap);
    ap += sizeof(char**) * 6;
    printf("%s\n", *(char**)ap);
    ap += sizeof(char**);
    printf("%s\n", *(char**)ap);
    ap += sizeof(char**);
    printf("%s\n", *(char**)ap);
#endif
}

int main() {
    int s1 = 3;
    char * s2 = "world";
    char * s3 = "fuck you";
    char * s4 = "riscv";
    print_str(s1,s2,s3,s4);
    return 0;
}

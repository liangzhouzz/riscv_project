#ifndef SOS_STRING_H__
#define SOS_STRING_H__

#include <sifanos/os.h>
size_t strlen(const char *str);
void* memcpy(void *dest, const void *src, size_t count);
void* memset(void *dest, int ch, size_t count);

#endif
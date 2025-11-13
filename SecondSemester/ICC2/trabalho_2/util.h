#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>
#include <stddef.h>

void init_crc32();
uint32_t crc32(uint32_t crc, const void* buf, size_t size);
int get_random(int* state, int max);

#endif

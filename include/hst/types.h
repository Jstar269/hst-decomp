/* Integer type names shared by the sources. The widths are the PSP's (Allegrex, ILP32). */
#ifndef HST_TYPES_H
#define HST_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;

#ifndef __cplusplus
typedef unsigned char bool;
#define true 1
#define false 0
#endif

#endif

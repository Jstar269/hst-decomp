/* HSTMATCH module=EBOOT.BIN start=0x000500ac end=0x00050148 symbol=FUN_000500ac lang=c99 */
/* Clone of src/sharing_main/FUN_00050988_00050988.c (hstclone.py tag u6cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void * FUN_00023a00(void *);
extern void * FUN_00050210();

int FUN_000500ac(undefined4 param_1, undefined4 param_2, int param_3)
{
  void *context;
  void *ptr;
  uint value;
  int result;
  result = 0;
  context = FUN_00050210();
  if (context != 0) {
    if (*(unsigned char *)((char *)context + 0x8c) == 3) {
      ptr = *(void **)((char *)context + 0x18);
    }
    else {
      ptr = 0;
    }
    if (ptr != 0) {
      ptr = FUN_00023a00(ptr);
      if (ptr != 0) {
        value = (uint)*(ushort *)((char *)ptr + 0xe) * 8 - 1;
        value = ~value & (value + (uint)*(ushort *)((char *)ptr + 0xc) * param_3);
        result = (int)value >> 3;
        if ((int)value < 0) {
          result = (int)(value + 7) >> 3;
        }
      }
    }
  }
  return result;
}
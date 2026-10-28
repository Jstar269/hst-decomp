/* HSTMATCH module=hstp_trans_main.prx start=0x00050988 end=0x00050a24 symbol=FUN_00050988 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void * FUN_00023a28(void *);
extern void * FUN_00050aec();

int FUN_00050988(u32 param_1, u32 param_2, int param_3)
{
  void *context;
  void *ptr;
  u32 value;
  int result;
  result = 0;
  context = FUN_00050aec();
  if (context != 0) {
    if (*(unsigned char *)((char *)context + 0x8c) == 3) {
      ptr = *(void **)((char *)context + 0x18);
    }
    else {
      ptr = 0;
    }
    if (ptr != 0) {
      ptr = FUN_00023a28(ptr);
      if (ptr != 0) {
        value = (u32)*(u16 *)((char *)ptr + 0xe) * 8 - 1;
        value = ~value & (value + (u32)*(u16 *)((char *)ptr + 0xc) * param_3);
        result = (int)value >> 3;
        if ((int)value < 0) {
          result = (int)(value + 7) >> 3;
        }
      }
    }
  }
  return result;
}
/* HSTMATCH module=EBOOT.BIN start=0x00198278 end=0x001982d8 symbol=FUN_00198278 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00197834();
extern void FUN_00198098();

u32 FUN_00198278(u32 param_1,u32 param_2,u32 param_3,u32 param_4)
{
  u8 auStack_400 [1024];
  
  FUN_00198098(param_1,param_2,auStack_400);
  FUN_00197834(param_1,auStack_400,0,0,param_3,param_4);
  return param_4;
}

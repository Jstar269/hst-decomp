/* HSTMATCH module=EBOOT.BIN start=0x001e0748 end=0x001e075c symbol=FUN_001e0748 lang=c99 data=0x002ebac8 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ebac8-0x002ebaec) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_0030ebf4; /* loader context */
extern void FUN_0001ca58();

/* Load the prize display layout file through the loader; the first two arguments are unused and the rest are passed on. */
void FUN_001e0748(u32 unused0,u32 unused1,u32 arg2,int *arg3,u32 arg4 ,u32 arg5,u32 arg6,u32 arg7)
{
  FUN_0001ca58((int)&DAT_0030ebf4,"game/700_prize/030_prize_display.xb",arg2,arg3,arg4,arg5,
               arg6,arg7);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x001ee96c end=0x001ee980 symbol=FUN_001ee96c lang=c99 data=0x003939d4 */
/* Clone of src/eboot/FUN_001e0748.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003939d4-0x003939f8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003b7ebc; /* loader context */
extern void FUN_0001c5f4();

/* Load the prize display layout file through the loader; the first two arguments are unused and the rest are passed on. */
void FUN_001ee96c(u32 unused0,u32 unused1,u32 arg2,int *arg3,u32 arg4 ,u32 arg5,u32 arg6,u32 arg7)
{
  FUN_0001c5f4((int)&DAT_003b7ebc,"game/700_prize/030_prize_display.xb",arg2,arg3,arg4,arg5,
               arg6,arg7);
}

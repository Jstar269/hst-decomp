/* HSTMATCH module=EBOOT.BIN start=0x0012dc2c end=0x0012dc34 symbol=FUN_0012dc2c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/lobby_stage.h"

extern void FUN_0012cea0();

/* Thunk: forwards to the primary object's method with the arguments unchanged. */
void FUN_0012dc2c(int self,int arg1,int arg2,u32 arg3,u32 arg4, u32 arg5,u32 arg6,u32 arg7)
{
  FUN_0012cea0((int *)(self - LOBBY_STAGE_PRIMARY_OFFSET),arg1,arg2,arg3,arg4,arg5,arg6,arg7);
}

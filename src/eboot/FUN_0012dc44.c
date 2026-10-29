/* HSTMATCH module=EBOOT.BIN start=0x0012dc44 end=0x0012dc4c symbol=FUN_0012dc44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/lobby_stage.h"

extern u32 * FUN_0012ccd0(u32 *param_1,short param_2);

/* Thunk: forwards to the primary object's deleting destructor. */
void FUN_0012dc44(int self,short deleteFlag)
{
  FUN_0012ccd0((u32 *)(self - LOBBY_STAGE_PRIMARY_OFFSET),deleteFlag);
}

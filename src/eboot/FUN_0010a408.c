/* HSTMATCH module=EBOOT.BIN start=0x0010a408 end=0x0010a4a8 symbol=FUN_0010a408 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_0010a408.c, corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/utility_params.h"

extern char DAT_002d8dd0[];
extern u32 * FUN_000114c0();
extern void FUN_0010a4a8();
extern void FUN_00199280();
extern int FUN_002b7c20();

/* Start a message dialog that shows an error value; logs the start-up result when it fails. */
int FUN_0010a408(MsgDialogParams *params,u32 errorValue)
{
  u32 result;
  
  FUN_000114c0(params,0,sizeof(MsgDialogParams));
  params->base.size = sizeof(MsgDialogParams);
  params->base.language = 0;
  params->base.buttonSwap = 0;
  params->base.graphicsThread = UTILITY_PRIO_GRAPHICS;
  params->base.accessThread = UTILITY_PRIO_ACCESS;
  params->base.fontThread = UTILITY_PRIO_FONT;
  params->base.soundThread = UTILITY_PRIO_SOUND;
  FUN_00199280(params);
  params->errorValue = errorValue;
  params->mode = MSGDIALOG_MODE_ERROR;
  result = FUN_002b7c20(params);
  if (0 != result) {
    FUN_0010a4a8(DAT_002d8dd0,result);
  }
  return result;
}

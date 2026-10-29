/* HSTMATCH module=hstp_trans_main.prx start=0x001101c8 end=0x00110268 symbol=FUN_001101c8 lang=c99 */
/* Clone of src/eboot/FUN_0010a408.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/utility_params.h"

extern char DAT_0037fba4[];
extern u32 * FUN_000114c0();
extern void FUN_00110268();
extern void FUN_001a5d44();
extern int FUN_002c79c0();

/* Start a message dialog that shows an error value; logs the start-up result when it fails. */
int FUN_001101c8(MsgDialogParams *params,u32 errorValue)
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
  FUN_001a5d44(params);
  params->errorValue = errorValue;
  params->mode = MSGDIALOG_MODE_ERROR;
  result = FUN_002c79c0(params);
  if (0 != result) {
    FUN_00110268(DAT_0037fba4,result);
  }
  return result;
}

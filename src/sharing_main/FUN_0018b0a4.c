/* HSTMATCH module=hstp_trans_main.prx start=0x0018b0a4 end=0x0018b0b4 symbol=FUN_0018b0a4 lang=c99 */
/* Clone of src/eboot/FUN_0017e9b0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/light_obj.h"

/* Restart the fade: progress back to zero and advancing. */
void FUN_0018b0a4(LightObj *light)
{
  light->active = 1;
  light->progress = 0.0f;
}

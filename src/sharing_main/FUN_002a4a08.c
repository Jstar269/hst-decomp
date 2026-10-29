/* HSTMATCH module=hstp_trans_main.prx start=0x002a4a08 end=0x002a4a48 symbol=FUN_002a4a08 lang=c99 */
/* Clone of src/eboot/FUN_002933fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ctl_obj.h"

/* True while the object is active, unk40 is clear and the level has not passed CTL_LEVEL_MAX. */
u32 FUN_002a4a08(CtlObj *ctl)
{
  u32 result;
  
  result = 0;
  if (((ctl->active != '\0') && (ctl->unk40 == '\0')) &&
     (ctl->level <= CTL_LEVEL_MAX)) {
    result = 1;
  }
  return result;
}

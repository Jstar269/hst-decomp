/* HSTMATCH module=hstp_trans_main.prx start=0x00261018 end=0x00261040 symbol=FUN_00261018 lang=c99 */
/* Clone of src/eboot/FUN_00250cc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/scroll_list_obj.h"

/* Returns 1 when the list's kind is 4 or 6, else 0. */
u32 FUN_00261018(ScrollListObj *self)
{
  u32 result;
  
  result = 1;
  if ((self->kind != 4) && (self->kind != 6)) {
    result = 0;
  }
  return result;
}

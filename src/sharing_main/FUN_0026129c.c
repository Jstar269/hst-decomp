/* HSTMATCH module=hstp_trans_main.prx start=0x0026129c end=0x002612ac symbol=FUN_0026129c lang=c99 */
/* Clone of src/eboot/FUN_00250f48.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/scroll_list_obj.h"

extern u32 DAT_003a4908;

/* Store value in the list and in the shared global. */
void FUN_0026129c(ScrollListObj *self,u32 value)
{
  self->unk304 = value;
  DAT_003a4908 = value;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x001e6dd4 end=0x001e6de4 symbol=FUN_001e6dd4 lang=c99 */
/* Clone of src/eboot/FUN_001d9028.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/handler_obj.h"

/* Clears the state and stores 6 in the field at 0x51c. */
void FUN_001e6dd4(HandlerObj *obj)
{
  obj->state = 0;
  obj->unk51c = 6;
}

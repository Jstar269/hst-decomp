/* HSTMATCH module=hstp_trans_main.prx start=0x002a4c68 end=0x002a4c98 symbol=FUN_002a4c68 lang=c99 */
/* Clone of src/eboot/FUN_0029365c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/komono_obj.h"

extern void FUN_00059e58();
extern void FUN_0005fec8();

void FUN_002a4c68(KomonoObj *obj)
{
  ModelHolder *sub;
  
  sub = obj->sub;
  FUN_00059e58(sub);
  FUN_0005fec8(sub);
}

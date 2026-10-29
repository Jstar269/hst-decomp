/* HSTMATCH module=hstp_trans_main.prx start=0x001f4168 end=0x001f41d4 symbol=FUN_001f4168 lang=c99 */
/* Clone of src/eboot/FUN_001e5f50.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_scene.h"

extern void FUN_00108f54();
extern void FUN_001f08e8();
extern void FUN_001f443c();

/* Free the owned objects and the part at 0x1958, then continue with the caller's three values. */
void FUN_001f4168(ResultScene *self,u32 arg1,u32 arg2,int arg3)
{
  FUN_001f08e8(self);
  FUN_00108f54(self->part1958,0);
  FUN_001f443c(self,arg1,arg2,arg3,'\0');
}

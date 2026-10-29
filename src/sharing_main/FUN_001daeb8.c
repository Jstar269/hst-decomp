/* HSTMATCH module=hstp_trans_main.prx start=0x001daeb8 end=0x001daf04 symbol=FUN_001daeb8 lang=c99 */
/* Clone of src/eboot/FUN_001cc784.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/name_box_owner.h"

extern u32 * FUN_000149a8();
extern int FUN_00014a40();

/* Sets the first name buffer when `name` fits. */
void FUN_001daeb8(NameBoxOwner *self,u32 name)
{
  u32 length;
  
  length = FUN_00014a40(name);
  if (length < NAME_BOX_NAME_LIMIT) {
    FUN_000149a8(self->nameA,name);
  }
}

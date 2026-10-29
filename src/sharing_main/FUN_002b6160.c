/* HSTMATCH module=hstp_trans_main.prx start=0x002b6160 end=0x002b61d0 symbol=FUN_002b6160 lang=c99 */
/* Clone of src/eboot/FUN_002a69d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Obj {
  char pad00[0x178];
  u32 owner;        /* 0x178 */
} Obj;

extern int DAT_003a9b90[];
extern u32 DAT_003f46a0;
extern void FUN_00111aa4();
extern void FUN_0011988c();
extern u8 * FUN_0020d1e0();

/* Select entry `index`: pass it to the owner and, when the global handle is set, look up and assign the matching value. */
void FUN_002b6160(Obj *self,int index)
{
  u32 value;
  
  FUN_00111aa4(self->owner,index,0);
  if (DAT_003f46a0 != 0) {
    value = (unsigned int)(FUN_0020d1e0(0x12,0x31,DAT_003a9b90[index]));
    FUN_0011988c(DAT_003f46a0,value,0);
  }
}

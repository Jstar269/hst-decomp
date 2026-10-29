/* HSTMATCH module=hstp_trans_main.prx start=0x00105e6c end=0x00105eb8 symbol=FUN_00105e6c lang=c99 */
/* Clone of src/eboot/FUN_00100538.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00038258();

typedef struct HandleOwner {
  char pad00[0x28];
  u32 handle;               /* 0x28 replaced by the call's result */
} HandleOwner;

/* Takes three value pairs (a0,a1) (b0,b1) (c0,c1) and passes them on as two triples. */
void FUN_00105e6c(HandleOwner *self,u32 a0,u32 a1,u32 b0, u32 b1,u32 c0,u32 c1)
{
  u32 result;
  
  result = FUN_00038258(self->handle,a1,b1,c1,a0,b0,
                       c0);
  self->handle = result;
}

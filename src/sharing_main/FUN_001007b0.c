/* HSTMATCH module=hstp_trans_main.prx start=0x001007b0 end=0x001007b8 symbol=FUN_001007b0 lang=c99 */
/* Clone of src/eboot/FUN_0019075c.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object whose pointer at 0x3c is the target of the forwarding call. */
typedef struct Forwarder {
  char pad0[0x3c];
  int *target; /* 0x3c */
} Forwarder;

extern void FUN_00100110();

/* Forwards seven arguments unchanged to the call on the target member. */
void FUN_001007b0(Forwarder *self,u32 arg1,u32 arg2,u32 arg3, u32 arg4,u32 arg5,u32 arg6,u32 arg7)
{
  FUN_00100110(self->target,arg1,arg2,arg3,arg4,arg5,arg6,arg7);
}

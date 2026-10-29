/* HSTMATCH module=EBOOT.BIN start=0x0019075c end=0x00190764 symbol=FUN_0019075c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object whose pointer at 0x3c is the target of the forwarding call. */
typedef struct Forwarder {
  char pad0[0x3c];
  int *target; /* 0x3c */
} Forwarder;

extern void FUN_0018f238();

/* Forwards seven arguments unchanged to the call on the target member. */
void FUN_0019075c(Forwarder *self,u32 arg1,u32 arg2,u32 arg3, u32 arg4,u32 arg5,u32 arg6,u32 arg7)
{
  FUN_0018f238(self->target,arg1,arg2,arg3,arg4,arg5,arg6,arg7);
}

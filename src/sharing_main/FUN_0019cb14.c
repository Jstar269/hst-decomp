/* HSTMATCH module=hstp_trans_main.prx start=0x0019cb14 end=0x0019cb58 symbol=FUN_0019cb14 lang=c99 */
/* Clone of src/eboot/FUN_00190304.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object with an embedded sub-object at 0x3c. */
typedef struct HostObj {
  const void *vtable;   /* 0x00 */
  char pad04[0x3c - 4];
  char sub3c[1];        /* 0x3c */
} HostObj;

extern u8 DAT_003b2460;
extern u32 * FUN_0001ec44();
extern void FUN_001a57f4();
extern void FUN_001a58b8();

/* Constructor: base setup, vtable, then the embedded sub-object and the object's own setup. */
HostObj * FUN_0019cb14(HostObj *self)
{
  FUN_0001ec44();
  self->vtable = &DAT_003b2460;
  FUN_001a57f4(self->sub3c);
  FUN_001a58b8(self);
  return self;
}

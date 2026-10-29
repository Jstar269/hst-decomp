/* HSTMATCH module=hstp_trans_main.prx start=0x002bec54 end=0x002bec5c symbol=FUN_002bec54 lang=c99 */
/* Clone of src/eboot/FUN_002af314.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct FloatAt18 {
  char pad00[0x18];
  float value;          /* 0x18 */
} FloatAt18;

extern u64 FUN_001ca418(float value);

/* Call the helper with the float at +0x18. */
void FUN_002bec54(FloatAt18 *self)
{
  FUN_001ca418(self->value);
  return;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x002beb28 end=0x002beb30 symbol=FUN_002beb28 lang=c99 */
/* Clone of src/eboot/FUN_002af26c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct FloatAt30 {
  char pad00[0x30];
  float value;          /* 0x30 */
} FloatAt30;

extern u64 FUN_001ca418(float value);

/* Call the helper with the float at +0x30. */
void FUN_002beb28(FloatAt30 *self)
{
  FUN_001ca418(self->value);
  return;
}

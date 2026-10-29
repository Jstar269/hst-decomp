/* HSTMATCH module=EBOOT.BIN start=0x002af314 end=0x002af31c symbol=FUN_002af314 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct FloatAt18 {
  char pad00[0x18];
  float value;          /* 0x18 */
} FloatAt18;

extern u64 FUN_001bc630(float value);

/* Call the helper with the float at +0x18. */
void FUN_002af314(FloatAt18 *self)
{
  FUN_001bc630(self->value);
  return;
}

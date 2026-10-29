/* HSTMATCH module=EBOOT.BIN start=0x002af26c end=0x002af274 symbol=FUN_002af26c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct FloatAt30 {
  char pad00[0x30];
  float value;          /* 0x30 */
} FloatAt30;

extern u64 FUN_001bc630(float value);

/* Call the helper with the float at +0x30. */
void FUN_002af26c(FloatAt30 *self)
{
  FUN_001bc630(self->value);
  return;
}

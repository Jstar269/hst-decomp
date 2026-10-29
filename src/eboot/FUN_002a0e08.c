/* HSTMATCH module=EBOOT.BIN start=0x002a0e08 end=0x002a0e34 symbol=FUN_002a0e08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct FlagHolder {
  char pad[0x14c];
  u8 flag;      /* 0x14c */
} FlagHolder;

extern void FUN_0010d4a8();

/* Sets the flag; clearing it calls FUN_0010d4a8. */
void FUN_002a0e08(FlagHolder *self,u8 value)
{
  self->flag = value;
  if (self->flag == '\0') {
    FUN_0010d4a8();
  }
}

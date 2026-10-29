/* HSTMATCH module=EBOOT.BIN start=0x001dbc04 end=0x001dbc40 symbol=FUN_001dbc04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338714;
extern void FUN_0005f1e8();

typedef struct GateObj {
  char pad00[0x3c];
  int unk3c;       /* 0x3c */
  char pad40[0xcc - 0x40];
  u8 unkcc;        /* 0xcc */
} GateObj;

void FUN_001dbc04(GateObj *self)
{
  if ((self->unk3c != 0) && (self->unkcc != '\0')) {
    FUN_0005f1e8(self->unk3c,DAT_00338714);
  }
}

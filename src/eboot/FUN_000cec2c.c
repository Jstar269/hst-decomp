/* HSTMATCH module=EBOOT.BIN start=0x000cec2c end=0x000cec58 symbol=FUN_000cec2c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0005f1e8();

typedef struct SubHolder {
  char pad00[0x3c];
  u8 active;          /* 0x3c */
  char pad3d[3];
  char sub[4];        /* 0x40 embedded sub-object */
} SubHolder;

/* Passes the embedded sub-object on when the active flag is set. */
void FUN_000cec2c(SubHolder *holder)
{
  if (holder->active != '\0') {
    FUN_0005f1e8(holder->sub,0);
  }
}

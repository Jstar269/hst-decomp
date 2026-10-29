/* HSTMATCH module=EBOOT.BIN start=0x00165004 end=0x001650a8 symbol=FUN_00165004 lang=c99 data=0x002e03c4 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed entry/table structs, #pragma opt_strength_reduction off; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e03c4-0x002e03e7) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/char_param.h"

extern void FUN_000143b0(char *buf, const char *fmt, ...);
extern int FUN_000146ec(const char *s1, const char *s2);
extern void FUN_0010a6f0(char *buf, int);

#pragma opt_strength_reduction off

/* Returns the index of the record called `name`; reports the missing name and returns 0 if there is none. */
u32 FUN_00165004(CharParamTable *table, const char *name)
{
  u32 index;
  char msg[256];

  index = 0;
  if (table->count != 0) {
    do {
      if (FUN_000146ec(name, table->entries[index].name) == 0) {
        return index;
      }
      index = index + 1;
    } while (index < table->count);
  }
  FUN_000143b0(msg, "CharacterParameter '%s' not found.", name);
  FUN_0010a6f0(msg, 0);
  return 0;
}

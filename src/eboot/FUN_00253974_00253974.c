/* HSTMATCH module=EBOOT.BIN start=0x00253974 end=0x00253a68 symbol=FUN_00253974 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: reused the loaded count as the range predicate and materialized the row offset before base addition; readability pass; exact match verified; names and types await human review. */
#include "hst/text_bank_lookup.h"
#include "hst/mode_text.h"

extern TextBank * FUN_0018c9f4(int);

/* Returns label `index` of mode `mode` (modes 5 and 6 are shifted by one). */
const char * FUN_00253974(int mode,int index)
{
  switch (mode) {
    case 5:
    case 6:
      index = index + 1;
      break;
  }
  return TextGet(FUN_0018c9f4(DAT_002ca6c0[mode].bank),DAT_002ca6c0[mode].group,index);
}

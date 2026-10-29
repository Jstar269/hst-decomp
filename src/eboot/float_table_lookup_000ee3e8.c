/* HSTMATCH module=EBOOT.BIN start=0x000ee3e8 end=0x000ee44c symbol=FUN_000ee3e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the six float constants as one float[6] local (retail frame, lw of the int-typed return); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

#define TABLE_SIZE 6

/* Object with a table index byte at 0x65. */
typedef struct TableObj {
  char pad0[0x65];
  u8 index;                     /* 0x65 selects the table entry */
} TableObj;

extern float DAT_002d6ca4;
extern float DAT_002d6ca8;
extern float DAT_002d6cac;
extern float DAT_002d6cb0;
extern float DAT_002d6cb4;
extern float DAT_002d6cb8;

/* Returns the bit pattern of the float selected by obj->index from a table of six constants. */
u32 FUN_000ee3e8(TableObj *obj)
{
  float table[TABLE_SIZE];
  table[0] = DAT_002d6ca4;
  table[1] = DAT_002d6ca8;
  table[2] = DAT_002d6cac;
  table[3] = DAT_002d6cb0;
  table[4] = DAT_002d6cb4;
  table[5] = DAT_002d6cb8;
  return *(u32 *)&table[obj->index];
}

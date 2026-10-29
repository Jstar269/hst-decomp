/* HSTMATCH module=EBOOT.BIN start=0x002a0df4 end=0x002a0e08 symbol=FUN_002a0df4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct QuadHolder {
  char pad[0xfc];
  u16 unkfc;   /* 0xfc */
  u16 unkfe;   /* 0xfe */
  u16 unk100;  /* 0x100 */
  u16 unk102;  /* 0x102 */
} QuadHolder;

void FUN_002a0df4(QuadHolder *self,u16 a,u16 b,u16 c, u16 d)
{
  self->unkfc = a;
  self->unkfe = b;
  self->unk100 = c;
  self->unk102 = d;
}

/* HSTMATCH module=EBOOT.BIN start=0x00115dc8 end=0x00115ddc symbol=FUN_00115dc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Obj_00115dc8 {
  char pad00[0x130];
  u16 unk130; /* 0x130 */
  u16 unk132; /* 0x132 */
  u16 unk134; /* 0x134 */
  u16 unk136; /* 0x136 */
} Obj_00115dc8;

/* Stores four 16-bit values; the second argument is unused. */
void FUN_00115dc8(Obj_00115dc8 *self,u32 unused,u16 v0,u16 v1,u16 v2,u16 v3)
{
  self->unk130 = v0;
  self->unk132 = v1;
  self->unk134 = v2;
  self->unk136 = v3;
}

/* HSTMATCH module=EBOOT.BIN start=0x001d7690 end=0x001d76a0 symbol=FUN_001d7690 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct OffsetObj {
  char pad00[0x24];
  int unk24;  /* 0x24 */
  int unk28;  /* 0x28 */
} OffsetObj;

/* unk24 = unk28 + delta */
void FUN_001d7690(OffsetObj *self,int delta)
{
  self->unk24 = self->unk28 + delta;
}

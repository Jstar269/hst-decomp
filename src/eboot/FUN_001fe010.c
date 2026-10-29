/* HSTMATCH module=EBOOT.BIN start=0x001fe010 end=0x001fe04c symbol=FUN_001fe010 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct Owner {
  char pad0[200];
  char unkC8[0x1250 - 200];  /* 0xc8 */
  char unk1250[1];           /* 0x1250 */
} Owner;

extern void FUN_001fdbb4();
extern void FUN_001fdd50();
extern void FUN_00201910();
extern void FUN_00201dc8();

void FUN_001fe010(Owner *self)
{
  FUN_001fdd50();
  FUN_001fdbb4(self);
  FUN_00201910(self->unkC8);
  FUN_00201dc8(self->unk1250);
}

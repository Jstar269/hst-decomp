/* HSTMATCH module=EBOOT.BIN start=0x002a6b30 end=0x002a6b68 symbol=FUN_002a6b30 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct Obj {
  char pad00[0x880];
  int unk880;       /* 0x880, when zero the extra step runs */
} Obj;

extern void FUN_001031e8();
extern void FUN_002a6668();

void FUN_002a6b30(Obj *self)
{
  if (self->unk880 == 0) {
    FUN_002a6668();
  }
  FUN_001031e8(self);
}

/* HSTMATCH module=EBOOT.BIN start=0x0023d6b0 end=0x0023d714 symbol=FUN_0023d6b0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: object typed as a padded struct, call result as int, header typedefs dropped; exact match verified; names and types await human review. */
extern void FUN_0010b980();
extern void FUN_00110a78();
extern int FUN_001fea10();

typedef struct Obj {
  char pad0[0x11b8];
  int f11b8;
  char pad1[0x1750 - 0x11bc];
  int f1750;
} Obj;

void FUN_0023d6b0(Obj *o, int p)
{
  FUN_0010b980(o->f11b8, p, 0);
  if (o->f1750 != 0) {
    int r = FUN_001fea10(0x12, 0xe, p);
    FUN_00110a78(o->f1750, r, 0);
  }
}

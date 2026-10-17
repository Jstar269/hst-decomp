/* HSTMATCH module=hstp_trans_main.prx start=0x0024d848 end=0x0024d8ac symbol=FUN_0024d848 lang=c99 */
/* Clone of src/eboot/forward_to_members_0023d6b0.c (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: object typed as a padded struct, call result as int, header typedefs dropped; exact match verified; names and types await human review. */
extern void FUN_00111b58();
extern void FUN_0011988c();
extern int FUN_0020d1e0();

typedef struct Obj {
  char pad0[0x11b8];
  int f11b8;
  char pad1[0x1750 - 0x11bc];
  int f1750;
} Obj;

void FUN_0024d848(Obj *o, int p)
{
  FUN_00111b58(o->f11b8, p, 0);
  if (o->f1750 != 0) {
    int r = FUN_0020d1e0(0x12, 0xe, p);
    FUN_0011988c(o->f1750, r, 0);
  }
}

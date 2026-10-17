/* HSTMATCH module=hstp_trans_main.prx start=0x000e30f8 end=0x000e3144 symbol=FUN_000e30f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed object with the three ints at +0xc0, +0xc4, +0xc8, byte flag unsigned char, and every failing test jumps to one shared return-0 label (matching idiom: goto to the shared return-0 label; early returns, && / || chains and else-if result variables all lay out differently); exact match verified; names and types await human review. */
extern unsigned char DAT_003e1e88;

typedef struct {
  char pad[0xc0];
  int f0;
  int f1;
  int f2;
} Obj;

int FUN_000e30f8(Obj *o)
{
  if (DAT_003e1e88 != 0) return 0;
  if (o->f1 < o->f0) goto z;
  if (o->f2 < o->f0) goto z;
  return 1;
z:
  return 0;
}

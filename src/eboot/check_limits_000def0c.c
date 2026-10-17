/* HSTMATCH module=EBOOT.BIN start=0x000def0c end=0x000def58 symbol=FUN_000def0c lang=c99 */
/* Clone of src/sharing_main/check_limits_000e30f8.c (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed object with the three ints at +0xc0, +0xc4, +0xc8, byte flag unsigned char, and every failing test jumps to one shared return-0 label (matching idiom: goto to the shared return-0 label; early returns, && / || chains and else-if result variables all lay out differently); exact match verified; names and types await human review. */
extern unsigned char DAT_00338b48;

typedef struct {
  char pad[0xc0];
  int f0;
  int f1;
  int f2;
} Obj;

int FUN_000def0c(Obj *o)
{
  if (DAT_00338b48 != 0) return 0;
  if (o->f1 < o->f0) goto z;
  if (o->f2 < o->f0) goto z;
  return 1;
z:
  return 0;
}

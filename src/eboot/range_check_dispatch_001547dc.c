/* HSTMATCH module=EBOOT.BIN start=0x001547dc end=0x00154854 symbol=FUN_001547dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global typed as a byte, range test as one || condition with >= 0x11 (the compare lands in v0), explicit int return; exact match verified; names and types await human review. */
extern unsigned char DAT_003402f0;
extern char DAT_002dc928[];
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int, int);
extern void FUN_0022bfb0(int, int);

typedef struct S { int p0; int p1; int a; int b; } S;

int FUN_001547dc(S *s, int x)
{
  int i;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(x);
    FUN_0014fd94(DAT_002dc928, s->a, s->b);
  }
  i = s->a;
  if (i < 0 || i >= 0x11) return 0;
  FUN_0022bfb0(i, s->b);
  return 0;
}

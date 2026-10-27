/* HSTMATCH module=EBOOT.BIN start=0x001547dc end=0x00154854 symbol=FUN_001547dc lang=c99 data=0x002dc928 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global typed as a byte, range test as one || condition with >= 0x11 (the compare lands in v0), explicit int return; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc928-0x002dc93b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern unsigned char DAT_003402f0;
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int, int);
extern void FUN_0022bfb0(int, int);

typedef struct S { int p0; int p1; int a; int b; } S;

int FUN_001547dc(S *s, int x)
{
  int i;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(x);
    FUN_0014fd94("ShopItem [%d, %d]\n", s->a, s->b);
  }
  i = s->a;
  if (i < 0 || i >= 0x11) return 0;
  FUN_0022bfb0(i, s->b);
  return 0;
}

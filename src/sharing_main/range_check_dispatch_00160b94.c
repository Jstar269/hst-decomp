/* HSTMATCH module=hstp_trans_main.prx start=0x00160b94 end=0x00160c0c symbol=FUN_00160b94 lang=c99 data=0x00383e10 */
/* Clone of src/eboot/range_check_dispatch_001547dc.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383e10-0x00383e23) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global typed as a byte, range test as one || condition with >= 0x11 (the compare lands in v0), explicit int return; exact match verified; names and types await human review. */
extern unsigned char DAT_003e9630;
extern void FUN_00158b2c(int);
extern void FUN_0015bb68(char *, int, int);
extern void FUN_0023ba20(int, int);

typedef struct S { int p0; int p1; int a; int b; } S;

int FUN_00160b94(S *s, int x)
{
  int i;
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(x);
    FUN_0015bb68("ShopItem [%d, %d]\n", s->a, s->b);
  }
  i = s->a;
  if (i < 0 || i >= 0x11) return 0;
  FUN_0023ba20(i, s->b);
  return 0;
}

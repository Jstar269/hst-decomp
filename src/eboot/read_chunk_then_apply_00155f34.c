/* HSTMATCH module=EBOOT.BIN start=0x00155f34 end=0x00155fac symbol=FUN_00155f34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the apply call regained its dropped third argument (the chunk size n, a2), if/else-if collapsed to `p == 0 || n < 1`, typed pointers; exact match verified; names and types await human review. */
extern void FUN_000104e0(void *);
extern void *FUN_0004cad0(int, int *, int, int);
extern int FUN_0014c454(int, void *, int);

int FUN_00155f34(int param_1, int param_2)
{
  int n;
  void *p = FUN_0004cad0(param_2, &n, 0x10, 1);
  int r;
  if (p == 0 || n < 1) {
    return 0;
  } else {
    r = FUN_0014c454(param_1, p, n);
    FUN_000104e0(p);
    return r;
  }
}

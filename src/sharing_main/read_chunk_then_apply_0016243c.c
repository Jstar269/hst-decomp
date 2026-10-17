/* HSTMATCH module=hstp_trans_main.prx start=0x0016243c end=0x001624b4 symbol=FUN_0016243c lang=c99 */
/* Clone of src/eboot/read_chunk_then_apply_00155f34.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the apply call regained its dropped third argument (the chunk size n, a2), if/else-if collapsed to `p == 0 || n < 1`, typed pointers; exact match verified; names and types await human review. */
extern void FUN_000104e0(void *);
extern void *FUN_0004cd8c(int, int *, int, int);
extern int FUN_00157f68(int, void *, int);

int FUN_0016243c(int param_1, int param_2)
{
  int n;
  void *p = FUN_0004cd8c(param_2, &n, 0x10, 1);
  int r;
  if (p == 0 || n < 1) {
    return 0;
  } else {
    r = FUN_00157f68(param_1, p, n);
    FUN_000104e0(p);
    return r;
  }
}

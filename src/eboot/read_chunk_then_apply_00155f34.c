/* HSTMATCH module=EBOOT.BIN start=0x00155f34 end=0x00155fac symbol=FUN_00155f34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the apply call regained its dropped third argument (the chunk size n, a2), if/else-if collapsed to `p == 0 || n < 1`, typed pointers; readability pass; exact match verified; names and types await human review. */
extern void FUN_000104e0(void *);
extern void *FUN_0004cad0(int, int *, int, int);
extern int FUN_0014c454(int, void *, int);

/* Loads the data for the given id, hands it to the apply call with its size, then frees it; returns 0 when nothing was loaded. */
int FUN_00155f34(int target, int id)
{
  int size;
  void *data = FUN_0004cad0(id, &size, 0x10, 1);
  int result;
  if (data == 0 || size < 1) {
    return 0;
  } else {
    result = FUN_0014c454(target, data, size);
    FUN_000104e0(data);
    return result;
  }
}

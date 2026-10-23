/* HSTMATCH module=EBOOT.BIN start=0x001b08a0 end=0x001b0958 symbol=FUN_001b08a0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00062418(int, int);

void FUN_001b08a0(int *arr, int *list, int n)
{
  int i;
  int idx;
  int v;
  int ok;


  for (i = 0; i < n; i++) {
    idx = list[i];
    ok = 0;
    if (idx < 0x1da) {
      if (arr[idx] != 0) {
        ok = 1;
      }
      else {
        ok = 0;
      }
    }
    if (ok) {
      v = arr[idx];
      if (v != 0) {
        FUN_00062418(v, 1);
        *(int *)((char *)arr + idx * sizeof(int)) = 0;
      }
    }
  }
}

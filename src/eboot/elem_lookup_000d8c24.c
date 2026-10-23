/* HSTMATCH module=EBOOT.BIN start=0x000d8c24 end=0x000d8c98 symbol=FUN_000d8c24 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

void * FUN_000d8c24(int param_1,int param_2,int param_3)
{
  int *piVar;
  void *p;
  int off;

  if (param_2 == 4) {
    param_2 = 3;
  }
  if (param_3 >= 0) {
    off = param_2 * 12;
    piVar = (int *)(off + param_1);
    if ((unsigned int)param_3 < (unsigned int)piVar[2]) {
      p = *(void **)(piVar[1] + param_3 * 4);
      if (p != 0) {
        if (*(signed char *)((int)p + 0x60) != -1) {
          return p;
        }
      }
    }
  }
  return 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x001b338c end=0x001b340c symbol=FUN_001b338c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00062418(int, int);

void FUN_001b338c(int *param_1, int index)
{
  int *p;
  int b;

  p = (int *)*param_1;
  b = 0;
  if (index < 0x1da) {
    if (p[index] != 0) {
      b = 1;
    }
    else {
      b = 0;
    }
  }
  if (b) {
    if (p[index] != 0) {
      FUN_00062418(p[index], 1);
      *(int *)((char *)p + index * sizeof(int)) = 0;
    }
  }
}

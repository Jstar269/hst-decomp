/* HSTMATCH module=EBOOT.BIN start=0x001b32f8 end=0x001b3378 symbol=FUN_001b32f8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00062418(int, int);

void FUN_001b32f8(int *param_1,int param_2)
{
  int *arr;
  int i;
  int b;

  arr = (int *)*param_1;
  i = param_2 + 0x27;
  b = 0;
  if (i < 0x1da) {
    if (arr[i] != 0) {
      b = 1;
    }
    else {
      b = 0;
    }
  }
  if (b) {
    if (arr[i] != 0) {
      FUN_00062418(arr[i], 1);
      *(int *)((char *)arr + i * sizeof(int)) = 0;
    }
  }
}

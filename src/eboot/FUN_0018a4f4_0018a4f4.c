/* HSTMATCH module=EBOOT.BIN start=0x0018a4f4 end=0x0018a5a0 symbol=FUN_0018a4f4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_002174bc(void *);

void FUN_0018a4f4(int param_1, int *param_2)
{
  int count;
  int i;

  FUN_002174bc((char *)param_1 + 0xd0);
  i = 0;
  if (0 < *(int *)(param_1 + 0x104)) {
    do {
      if (*param_2 != 0) {
        int x = *(int *)(param_1 + 0xe4) + param_2[2];
        int y = *(int *)(param_1 + 0xe8) + *(int *)(param_1 + 0xec) + param_2[3];
        *(short *)(*param_2 + 4) = x;
        *(short *)(*param_2 + 8) = x + *(int *)(param_1 + 0xdc);
        *(short *)(*param_2 + 6) = y;
        *(short *)(*param_2 + 10) = y + *(int *)(param_1 + 0xe0);
      }
      count = *(int *)(param_1 + 0x104);
      ++i;
      param_2 += 5;
    } while (i < count);
  }
}

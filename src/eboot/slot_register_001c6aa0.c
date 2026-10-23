/* HSTMATCH module=EBOOT.BIN start=0x001c6aa0 end=0x001c6b38 symbol=FUN_001c6aa0 lang=c99 helpers=FUN_001c5018@0x001c5018-0x001c5044 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_002ea6d0[];
extern void FUN_001c67e8(int a, int b);

static void FUN_001c5018(...)
{
}

void FUN_001c6aa0(int param_1, unsigned int param_2, int param_3, int param_4)
{
  FUN_001c67e8(param_1, param_4);
  if (param_2 < *(unsigned int *)(param_1 + 0x80)) {
    if (*(int *)(*(int *)(param_1 + 0x7c) + param_2 * 4) != 0) {
      FUN_001c5018(DAT_002ea6d0, param_2);
    }
    *(unsigned int *)(param_4 + 0x30) = param_2;
    *(int *)(param_4 + 0x34) = param_3;
    *(int *)(*(int *)(param_1 + 0x7c) + param_2 * 4) = param_4;
  }
}

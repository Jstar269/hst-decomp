/* HSTMATCH module=EBOOT.BIN start=0x001792b0 end=0x00179348 symbol=FUN_001792b0 lang=c99 rodata=0x002c1f78 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. (jump table in .rodata; case 0 is an empty label so its entry reuses the shared return-0 block) */
int FUN_001792b0(int param_1, int param_2, int param_3)
{
  switch (param_2) {
  case 1:
    return **(int **)(*(int *)(param_1 + 0x1d8) + param_3 * 4);
  case 2:
    return **(int **)(*(int *)(param_1 + 0x1f0) + param_3 * 4);
  case 3:
  case 4:
    return **(int **)(*(int *)(param_1 + 0x208) + param_3 * 4);
  case 5:
    return **(int **)(**(int **)(param_1 + 0x1d4) + param_3 * 4);
  case 0:
    break;
  }
  return 0;
}

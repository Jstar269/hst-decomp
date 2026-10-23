/* HSTMATCH module=EBOOT.BIN start=0x0010b150 end=0x0010b29c symbol=FUN_0010b150 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void FUN_000ffb3c(int, int);

void FUN_0010b150(int param_1)
{
  int i;

  i = *(int *)(param_1 + 0xd4);
  switch (*(int *)(param_1 + 0x118)) {
  case 1:
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + i * 4),0);
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + (i + 1) * 4),1);
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + (i + 2) * 4),1);
    break;
  case 2:
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + (i + 2) * 4),0);
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + i * 4),1);
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + (i + 1) * 4),1);
    break;
  case 0:
  default:
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + (i + 1) * 4),0);
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + i * 4),1);
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + (i + 2) * 4),1);
    break;
  }
}

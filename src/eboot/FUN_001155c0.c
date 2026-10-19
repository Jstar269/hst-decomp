/* HSTMATCH module=EBOOT.BIN start=0x001155c0 end=0x0011564c symbol=FUN_001155c0 lang=c99 rodata=0x002c11e0 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_001155c0(int param_1)
{
  if ((*(unsigned int *)(param_1 + 0x6c) & 8) != 0) {
    int x = *(int *)(param_1 + 0x88);
    if (x > 0 && x < 3) return 0;
  }
  switch (*(int *)(param_1 + 0x68)) {
  case 1:
    return 1 < *(int *)(*(int *)(param_1 + 0x58) + 0x68);
  case 2:
  case 5:
    return *(unsigned char *)(param_1 + 0x7c);
  case 6:
    return *(unsigned char *)(param_1 + 0x84);
  case 0:
  case 3:
  case 4:
  default:
    return 0;
  }
}

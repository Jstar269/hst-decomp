/* HSTMATCH module=hstp_trans_main.prx start=0x001204dc end=0x00120568 symbol=FUN_001204dc lang=c99 rodata=0x002d15c0 */
/* Clone of src/eboot/FUN_001155c0.c (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_001204dc(int param_1)
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

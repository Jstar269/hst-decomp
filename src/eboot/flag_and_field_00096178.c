/* HSTMATCH module=EBOOT.BIN start=0x00096178 end=0x0009619c symbol=FUN_00096178 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_003386b8;
int FUN_00096178(int a0)
{
  return DAT_003386b8 != 0 && *(unsigned char *)(a0 + 0x1b4) != 0;
}

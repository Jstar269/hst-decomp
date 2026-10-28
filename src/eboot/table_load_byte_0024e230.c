/* HSTMATCH module=EBOOT.BIN start=0x0024e230 end=0x0024e268 symbol=FUN_0024e230 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
signed char FUN_0024e230(int base,int a1,int a2,int a3)
{
  unsigned char b = !a1;
  char *p = (char *)(base + b * 96 + a2 * 6);
  return *(signed char *)(p + a3);
}

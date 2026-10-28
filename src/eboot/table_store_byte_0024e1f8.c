/* HSTMATCH module=EBOOT.BIN start=0x0024e1f8 end=0x0024e230 symbol=FUN_0024e1f8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_0024e1f8(int base,int a1,int a2,int a3,unsigned char val)
{
  unsigned char b = !a1;
  char *p = (char *)(base + b * 96 + a2 * 6);
  *(unsigned char *)(p + a3) = val;
}

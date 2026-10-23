/* HSTMATCH module=EBOOT.BIN start=0x0022c9ac end=0x0022c9f4 symbol=FUN_0022c9ac lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
typedef unsigned char u8;

extern u8 *DAT_003415a8;

undefined4 FUN_0022c9ac(void)
{
  int r;
  int i;
  u8 b;
  u8 *p;

  r = 1;
  i = 9;
  p = DAT_003415a8 + 9;
  do {
    b = (p[0xc200] & 2) != 0;
    if (b == 0) {
      r = 0;
      break;
    }
    i = i + -1;
    p = p + -1;
  } while (0 <= i);
  return r;
}

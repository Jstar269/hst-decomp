/* HSTMATCH module=EBOOT.BIN start=0x00194348 end=0x001943ac symbol=FUN_00194348 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

extern undefined4 DAT_00341730;
extern undefined4 DAT_00341734;
extern undefined4 DAT_00341738;
extern undefined4 DAT_0034173c;
extern undefined4 DAT_00341740;

undefined4 FUN_00194348(void)
{
  if (DAT_00341734 == 0) goto zero;
  if (DAT_00341730 == 0) goto zero;
  if (DAT_00341740 == 0) goto zero;
  if (DAT_0034173c == 0) goto zero;
  if (DAT_00341738 == 0) goto zero;
  return 1;
zero:
  return 0;
}

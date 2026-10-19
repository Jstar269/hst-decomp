/* HSTMATCH module=EBOOT.BIN start=0x0016b270 end=0x0016b2b4 symbol=FUN_0016b270 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern char DAT_00341ccc[];

int FUN_0016b270(unsigned short param_1)
{
  int r;

  if (0 <= param_1 && param_1 < 0xf)
    r = (int)&DAT_00341ccc[param_1 * 0x38] + 0xc8;
  else
    r = 0;
  return r;
}

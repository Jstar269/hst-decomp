/* HSTMATCH module=EBOOT.BIN start=0x0016b3d8 end=0x0016b45c symbol=FUN_0016b3d8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. 2-D variant of the 0x16b300 getter-range accessor recipe: guard written a >= 0 && a < 15 && c >= 0 && c < 4, offset b + a*0x38 + c*0xc + 0xc. */
typedef unsigned char undefined;
extern int FUN_0016bb88();
int FUN_0016b3d8(int a,int c)
{
  char *b;
  b = (char *)FUN_0016bb88();
  if (a >= 0 && a < 0xf && c >= 0 && c < 4) {
    return (int)(b + a * 0x38 + c * 0xc + 0xc);
  }
  return 0;
}

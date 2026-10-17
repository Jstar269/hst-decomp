/* HSTMATCH module=hstp_trans_main.prx start=0x0017759c end=0x00177620 symbol=FUN_0017759c lang=c99 */
/* Clone of src/eboot/FUN_0016b3d8.c (hstclone.py tag u3r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. 2-D variant of the 0x16b300 getter-range accessor recipe: guard written a >= 0 && a < 15 && c >= 0 && c < 4, offset b + a*0x38 + c*0xc + 0xc. */
typedef unsigned char undefined;
extern int FUN_00177d4c();
int FUN_0017759c(int a,int c)
{
  char *b;
  b = (char *)FUN_00177d4c();
  if (a >= 0 && a < 0xf && c >= 0 && c < 4) {
    return (int)(b + a * 0x38 + c * 0xc + 0xc);
  }
  return 0;
}

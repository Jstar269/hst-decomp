/* HSTMATCH module=EBOOT.BIN start=0x002af920 end=0x002afa48 symbol=FUN_002af920 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared pointer before loop index, unsigned comparison, local obj copy for delay slot move; exact match verified; names and types await human review. */

typedef unsigned char byte;
typedef unsigned int uint;

extern int DAT_00338b08;
extern int DAT_003415a8;
extern int FUN_000d8c24(int, int, int);

int FUN_002af920(int param_1)
{
  int sum = 0;
  int obj = param_1;
  byte *p;
  int i;
  int res;
  
  if (param_1 == 0) {
    obj = DAT_003415a8 + 0x80;
  }
  p = (byte *)(obj + 0x84c);
  i = 0;
  do {
    if ((uint)(*p - 4) < 2) {
      res = FUN_000d8c24(DAT_00338b08, 1, i);
      sum = sum + *(short *)(res + 0x5e);
    }
    i = i + 1;
    p = p + 1;
  } while (i < 640);

  p = (byte *)(obj + 0xacc);
  i = 0;
  do {
    if ((uint)(*p - 4) < 2) {
      res = FUN_000d8c24(DAT_00338b08, 2, i);
      sum = sum + *(short *)(res + 0x5e);
    }
    i = i + 1;
    p = p + 1;
  } while (i < 640);

  p = (byte *)(obj + 0xd4c);
  i = 0;
  do {
    if ((uint)(*p - 4) < 2) {
      res = FUN_000d8c24(DAT_00338b08, 3, i);
      sum = sum + *(short *)(res + 0x5e);
    }
    i = i + 1;
    p = p + 1;
  } while (i < 640);

  return sum;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x002bf370 end=0x002bf498 symbol=FUN_002bf370 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/calc_total_block_weight_002af920.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */

typedef unsigned char byte;
typedef unsigned int uint;

extern int DAT_003e1e48;
extern int DAT_003ea8e8;
extern int FUN_000dca74(int, int, int);

int FUN_002bf370(int param_1)
{
  int sum = 0;
  int obj = param_1;
  byte *p;
  int i;
  int res;
  
  if (param_1 == 0) {
    obj = DAT_003ea8e8 + 0x80;
  }
  p = (byte *)(obj + 0x84c);
  i = 0;
  do {
    if ((uint)(*p - 4) < 2) {
      res = FUN_000dca74(DAT_003e1e48, 1, i);
      sum = sum + *(short *)(res + 0x5e);
    }
    i = i + 1;
    p = p + 1;
  } while (i < 640);

  p = (byte *)(obj + 0xacc);
  i = 0;
  do {
    if ((uint)(*p - 4) < 2) {
      res = FUN_000dca74(DAT_003e1e48, 2, i);
      sum = sum + *(short *)(res + 0x5e);
    }
    i = i + 1;
    p = p + 1;
  } while (i < 640);

  p = (byte *)(obj + 0xd4c);
  i = 0;
  do {
    if ((uint)(*p - 4) < 2) {
      res = FUN_000dca74(DAT_003e1e48, 3, i);
      sum = sum + *(short *)(res + 0x5e);
    }
    i = i + 1;
    p = p + 1;
  } while (i < 640);

  return sum;
}

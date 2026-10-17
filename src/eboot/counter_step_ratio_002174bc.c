/* HSTMATCH module=EBOOT.BIN start=0x002174bc end=0x00217548 symbol=FUN_002174bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed object view, the limit field read into a local first and reused as the divisor, and the finished arm (counter >= limit) written first; exact match verified; names and types await human review. */
typedef struct {
  char pad0[8];
  int f8;
  char pad1[0x1c - 0xc];
  int f1c;
  unsigned char f20;
  unsigned char f21;
  char pad2[2];
  int f24;
  int f28;
  int f2c;
  int f30;
} Obj;

void FUN_002174bc(Obj *param_1)
{
  int iVar1;

  param_1->f21 = 0;
  if (param_1->f20 != 0) {
    int lim = param_1->f30;
    iVar1 = param_1->f2c + 1;
    param_1->f2c = iVar1;
    if (iVar1 >= lim) {
      param_1->f20 = 0;
      param_1->f1c = param_1->f28 + param_1->f8 * param_1->f24;
      param_1->f24 = 0;
      param_1->f21 = 1;
    }
    else {
      param_1->f1c = param_1->f28 + param_1->f24 * ((param_1->f8 * iVar1) / lim);
    }
  }
}

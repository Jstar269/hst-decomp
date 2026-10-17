/* HSTMATCH module=hstp_trans_main.prx start=0x001a5d44 end=0x001a5dd4 symbol=FUN_001a5d44 lang=c99 rodata=0x002d2fac */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: reordered the switch cases to retail body order 2,4,5,3,9,10 and typed the object as a struct; exact match verified; names and types await human review. */
typedef struct Obj {
  char pad_0[4];
  int f4;
  int f8;
} Obj;

extern unsigned int DAT_003eaae0;

void FUN_001a5d44(Obj *param_1)
{
  param_1->f8 = 1;
  switch (DAT_003eaae0) {
  case 0:
  case 1:
  case 6:
  case 7:
  case 8:
  default:
    param_1->f4 = 1;
    break;
  case 2:
    param_1->f4 = 2;
    break;
  case 4:
    param_1->f4 = 4;
    break;
  case 5:
    param_1->f4 = 5;
    break;
  case 3:
    param_1->f4 = 3;
    break;
  case 9:
    param_1->f4 = 9;
    break;
  case 10:
    param_1->f4 = 10;
    break;
  }
}

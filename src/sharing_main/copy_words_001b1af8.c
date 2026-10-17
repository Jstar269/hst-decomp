/* HSTMATCH module=hstp_trans_main.prx start=0x001b1af8 end=0x001b1b44 symbol=FUN_001b1af8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed both objects as structs, unsigned byte flag (lbu) and signed char argument; exact match verified; names and types await human review. */
typedef struct Obj {
  char pad_000[0x2fc];
  int f2fc;
  int f300;
  int f304;
  int f308;
  int f30c;
  int f310;
} Obj;

typedef struct Ctx {
  char pad_000[0x3dd];
  char f3dd;
  char pad_3de;
  unsigned char f3df;
} Ctx;

extern void FUN_00177c64(int, int);
extern Ctx *FUN_0020d694();

void FUN_001b1af8(Obj *param_1)
{
  Ctx *pCVar1;

  pCVar1 = FUN_0020d694();
  FUN_00177c64(pCVar1->f3dd, pCVar1->f3df != 0);
  param_1->f308 = param_1->f2fc;
  param_1->f30c = param_1->f300;
  param_1->f310 = param_1->f304;
}

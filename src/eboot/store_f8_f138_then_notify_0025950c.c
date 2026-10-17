/* HSTMATCH module=EBOOT.BIN start=0x0025950c end=0x002595e8 symbol=FUN_0025950c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: typed Obj struct, bool flags as ints, the && test on the two values as !((x != 0) ^ 1) && !((y != 0) ^ 1) (matching idiom: materialised sltu/xori tests), `if (bVar4 == 0)` with one shared store, and bVar1 = 0 on equality instead of a != materialisation; exact match verified; names and types await human review. */
typedef struct Obj { char pad[0xf8]; int f_f8; char pad2[0x3c]; int f_138; } Obj;
extern int FUN_00014934(int, int);
extern void FUN_0010d4a8(Obj *);

void FUN_0025950c(Obj *param_1, int param_2, int param_3, int param_4)
{
  int bVar1;
  int bVar4;
  int bVar3;
  int bVar2;

  bVar1 = 1;
  bVar4 = 1;
  if (param_4 == 0) {
    bVar3 = 1;
    bVar2 = 1;
    if (!((param_1->f_f8 != 0) ^ 1) && !((param_2 != 0) ^ 1)) bVar2 = 0;
    if ((bVar2 == 0) && (FUN_00014934(param_1->f_f8, param_2) == 0)) {
      bVar3 = 0;
    }
    if (bVar3 == 0) {
      bVar4 = 0;
    }
  }
  if (bVar4 == 0) {
    if (param_1->f_138 == param_3) bVar1 = 0;
  }
  param_1->f_f8 = param_2;
  param_1->f_138 = param_3;
  if (bVar1) {
    FUN_0010d4a8(param_1);
  }
}

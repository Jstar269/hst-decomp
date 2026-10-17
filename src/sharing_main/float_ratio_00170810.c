/* HSTMATCH module=hstp_trans_main.prx start=0x00170810 end=0x00170860 symbol=FUN_00170810 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the object as a struct, the callee takes the second argument (a1 passes through untouched), named the doubled delta in its own local; matching idiom: with the delta inline in the expression add.s has swapped operands; exact match verified; names and types await human review. */
typedef struct Obj {
  char pad_00[0x44];
  float f44;
  float f48;
} Obj;

extern float FUN_00170038(Obj *, void *);

float FUN_00170810(Obj *param_1, void *param_2)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  fVar3 = param_1->f48;
  fVar1 = FUN_00170038(param_1, param_2);
  fVar2 = param_1->f44;
  fVar4 = (fVar1 - fVar2) * 2.0f;
  return fVar3 * ((fVar4 + fVar2) / fVar2);
}

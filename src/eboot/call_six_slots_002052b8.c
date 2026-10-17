/* HSTMATCH module=EBOOT.BIN start=0x002052b8 end=0x00205374 symbol=FUN_002052b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed object views; the if/else on param_2 is a done flag (matching idiom: done = 0; if (param_2 != 0) { F(..param_3); done = 1; } if (done == 0) F(..0);), #pragma opt_strength_reduction off for the recomputed index*4, and iVar2 declared before iVar1 for the s-registers; exact match verified; names and types await human review. */
typedef struct { char pad[0x58]; int f58; } Sub;
#pragma opt_strength_reduction off
typedef struct { Sub *f0; int f4; int f8; int *fc; } Obj;
extern void FUN_0005743c(int a, int b, int c, int d);

void FUN_002052b8(Obj *param_1, int param_2, int param_3)
{
  int iVar2;
  int iVar1;
  int done;

  iVar2 = param_1->f0->f58;
  if (iVar2 != 0) {
    iVar1 = 0;
    do {
      done = 0;
      if (param_2 != 0) {
        FUN_0005743c(iVar2, iVar1, param_1->fc[iVar1], param_3);
        done = 1;
      }
      if (done == 0) {
        FUN_0005743c(iVar2, iVar1, param_1->fc[iVar1], 0);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 6);
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x0017dab8 end=0x0017db50 symbol=FUN_0017dab8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a, variant v0) corrected by hand: if/else order inverted and the float product regrouped to the retail evaluation order; exact match verified; names and types await human review. */

extern int FUN_0016bc7c();
extern int FUN_00204400();

float FUN_0017dab8(int param_1,int param_2)
{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  float fVar5;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x60);
  iVar4 = 0;
  if (iVar1 != 0) {
    iVar4 = *(int *)(iVar1 + 0x1b4);
  }
  if ((iVar4 >= 0) && (iVar4 <= 0xe)) {
    pfVar2 = (float *)FUN_00204400();
    pfVar3 = (float *)FUN_0016bc7c();
    fVar5 = *pfVar2 * (*(float *)(param_1 + 0x4c) * *pfVar3);
  }
  else {
    pfVar2 = (float *)FUN_0016bc7c();
    fVar5 = *(float *)(param_1 + 0x4c) * *pfVar2;
  }
  return fVar5;
}

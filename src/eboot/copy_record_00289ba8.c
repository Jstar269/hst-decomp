/* HSTMATCH module=EBOOT.BIN start=0x00289ba8 end=0x00289c3c symbol=FUN_00289ba8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed the copied record fields as floats; exact match verified; names and types await human review. */

int FUN_00289ba8(int *param_1,float *param_2)
{
  int iVar1;
  float *puVar2;
  
  puVar2 = (float *)*param_1;
  iVar1 = (int)puVar2 - *(int *)(param_1[1] + 8);
  if (iVar1 / 16 < *(int *)(param_1[1] + 4)) {
    *puVar2 = *param_2;
    puVar2[1] = param_2[1];
    puVar2[2] = param_2[2];
    puVar2[3] = param_2[3];
  }
  else {
    if (puVar2 != (float *)0x0) {
      *puVar2 = *param_2;
      puVar2[1] = param_2[1];
      puVar2[2] = param_2[2];
      puVar2[3] = param_2[3];
    }
    iVar1 = param_1[1];
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  }
  return *param_1;
}

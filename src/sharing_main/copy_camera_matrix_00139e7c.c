/* HSTMATCH module=hstp_trans_main.prx start=0x00139e7c end=0x00139f64 symbol=FUN_00139e7c lang=c99 */
/* Clone of src/eboot/copy_camera_matrix_0012e924.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the unused first parameter is an int (the generator's float-typed undefined4 moved the other parameter to a0); exact match verified; names and types await human review. */
extern int DAT_003da704;
extern float FUN_0000c018(float param_1);

void FUN_00139e7c(int param_1,int param_2)
{
  int iVar1;
  float fVar2;
  float uVar3;
  
  iVar1 = DAT_003da704;
  *(float *)(DAT_003da704 + 0x1d0) = *(float *)(param_2 + 0x30);
  *(float *)(iVar1 + 0x1d4) = *(float *)(param_2 + 0x34);
  *(float *)(iVar1 + 0x1d8) = *(float *)(param_2 + 0x38);
  *(float *)(iVar1 + 0x1dc) = *(float *)(param_2 + 0x3c);
  iVar1 = DAT_003da704;
  *(float *)(DAT_003da704 + 0x1e0) = *(float *)(param_2 + 0x20);
  *(float *)(iVar1 + 0x1e4) = *(float *)(param_2 + 0x24);
  *(float *)(iVar1 + 0x1e8) = *(float *)(param_2 + 0x28);
  *(float *)(iVar1 + 0x1ec) = *(float *)(param_2 + 0x2c);
  iVar1 = DAT_003da704;
  *(float *)(DAT_003da704 + 0x1f0) = *(float *)(param_2 + 0x10);
  *(float *)(iVar1 + 500) = *(float *)(param_2 + 0x14);
  *(float *)(iVar1 + 0x1f8) = *(float *)(param_2 + 0x18);
  *(float *)(iVar1 + 0x1fc) = *(float *)(param_2 + 0x1c);
  iVar1 = DAT_003da704;
  fVar2 = *(float *)(param_2 + 0x40);
  *(float *)(DAT_003da704 + 0x200) = fVar2;
  uVar3 = FUN_0000c018(fVar2 * 0.008726646f);
  *(float *)(iVar1 + 0x214) = uVar3;
  *(float *)(DAT_003da704 + 0x204) = *(float *)(param_2 + 0x44);
  *(float *)(DAT_003da704 + 0x208) = *(float *)(param_2 + 0x48);
  return;
}

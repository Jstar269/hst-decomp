/* HSTMATCH module=hstp_trans_main.prx start=0x001f2d64 end=0x001f2e60 symbol=FUN_001f2d64 lang=c99 */
/* Clone of src/eboot/FUN_001e4b4c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00108558();
extern void FUN_001f8bd4();

void FUN_001f2d64(float param_1,int param_2)
{
  int iVar1;
  
  iVar1 = (int)(param_1 + 480.0f);
  *(float *)(*(int *)(param_2 + 0x9b8) + 0x60) = (float)(*(int *)(param_2 + 0x1748) + iVar1);
  FUN_00108558(*(int *)(param_2 + 0x9b8));
  *(float *)(*(int *)(param_2 + 0x9bc) + 0x60) = (float)(*(int *)(param_2 + 0x174c) + iVar1);
  FUN_00108558(*(int *)(param_2 + 0x9bc));
  *(float *)(*(int *)(param_2 + 0x9c0) + 0x60) = (float)(*(int *)(param_2 + 0x1750) + iVar1);
  FUN_00108558(*(int *)(param_2 + 0x9c0));
  *(float *)(*(int *)(param_2 + 0x9c4) + 0x60) = (float)(*(int *)(param_2 + 0x1754) + iVar1);
  FUN_00108558(*(int *)(param_2 + 0x9c4));
  *(float *)(*(int *)(param_2 + 0x9c8) + 0x60) = (float)(*(int *)(param_2 + 0x1758) + iVar1);
  FUN_00108558(*(int *)(param_2 + 0x9c8));
  FUN_001f8bd4(*(int **)(*(int *)(param_2 + 0x3c) + 0x8c),(int)param_1);
}

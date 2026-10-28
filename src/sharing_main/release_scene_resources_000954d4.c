/* HSTMATCH module=hstp_trans_main.prx start=0x000954d4 end=0x00095578 symbol=FUN_000954d4 lang=c99 */
/* Clone of src/eboot/release_scene_resources_000935b0.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: restored the float parameter and typed both helper calls; exact match verified; names and types await human review. */

extern void FUN_00059c1c(int, float, int);
extern void FUN_0005ff00(int, float);

void FUN_000954d4(int param_1,float param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (iVar1 != 0) {
    FUN_00059c1c(iVar1,param_2,0xffffffff);
    FUN_0005ff00(iVar1,param_2);
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 0) {
    FUN_00059c1c(iVar1,param_2,0xffffffff);
    FUN_0005ff00(iVar1,param_2);
  }
  iVar1 = *(int *)(param_1 + 100);
  if (iVar1 != 0) {
    FUN_00059c1c(iVar1,param_2,0xffffffff);
    FUN_0005ff00(iVar1,param_2);
  }
}

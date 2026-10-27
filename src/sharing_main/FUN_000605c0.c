/* HSTMATCH module=hstp_trans_main.prx start=0x000605c0 end=0x00060638 symbol=FUN_000605c0 lang=c99 data=0x00376dec */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: reuse the scaled size for the unsigned boundary and preserve the selected-local branch order; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00376dec-0x00376e03) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef unsigned char undefined1;
typedef unsigned int uint;
typedef unsigned int undefined4;
extern int FUN_0000d530(void);
extern undefined1 *FUN_0000fe3c(void);
extern void FUN_000600f0(undefined4, const char *);
int FUN_000605c0(int param_1, uint param_2)
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint local_4;
  uint local_8;
  local_8 = param_2;
  uVar3 = *(int *)(param_1 + 8) * 0x20;
  local_4 = uVar3;
  if (-1U - uVar3 < param_2) {
    iVar1 = (int)FUN_0000fe3c();
    FUN_000600f0(*(undefined4 *)(iVar1 + 0xc), "bitvector length error");
    FUN_0000d530();
  }
  if (uVar3 < local_8) {
    puVar2 = &local_8;
  } else {
    puVar2 = &local_4;
  }
  return uVar3 + *puVar2;
}

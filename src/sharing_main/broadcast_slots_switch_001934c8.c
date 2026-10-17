/* HSTMATCH module=hstp_trans_main.prx start=0x001934c8 end=0x001935f0 symbol=FUN_001934c8 lang=c99 */
/* Clone of src/eboot/broadcast_slots_switch_00186d7c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: Ghidra's if/else-if chain over param_2 is a switch (case 0, 1, 2+3, 4 in source order; retail tests 4,3,2,1,0), with the 0xd0-offset call repeated per case; exact match verified; names and types await human review. */
extern void FUN_002265f0(int, int, int, int);

void FUN_001934c8(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  FUN_002265f0(*(int *)(param_1 + 0x2878) + 0xd0,param_3,param_4,param_5);
  FUN_002265f0(*(int *)(param_1 + 0x2880) + 0xd0,param_3,param_4,param_5);
  FUN_002265f0(*(int *)(param_1 + 0x28a8) + 0xd0,param_3,param_4,param_5);
  switch (param_2) {
  case 0: FUN_002265f0(*(int *)(param_1 + 0x2888) + 0xd0,param_3,param_4,param_5); break;
  case 1: FUN_002265f0(*(int *)(param_1 + 0x2894) + 0xd0,param_3,param_4,param_5); break;
  case 2:
  case 3: FUN_002265f0(*(int *)(param_1 + 0x28a0) + 0xd0,param_3,param_4,param_5); break;
  case 4: break;
  }
}

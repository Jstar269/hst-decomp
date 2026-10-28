/* HSTMATCH module=hstp_trans_main.prx start=0x001b7400 end=0x001b7540 symbol=FUN_001b7400 lang=c99 */
/* Clone of src/eboot/set_mode_flag_calls_001a9e34.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: Ghidra's goto structure rewritten as nested if/else (A != 0 && B == 0 outer, C == 0 && D != 0 inner, three call-pair copies), byte flags unsigned char; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1e04;
extern void FUN_00105470();
extern void FUN_00108f54();
extern void FUN_001118ac();
extern int FUN_001aa91c();
extern void FUN_001b7540();
extern void FUN_001b7798();
extern void FUN_001b77d4();
extern void FUN_001b7810();
extern void FUN_001b7870();
extern void FUN_001b7a1c();
extern void FUN_001b7b24();
extern void FUN_001b7d3c();

void FUN_001b7400(u32 *param_1)
{
  int iVar1;
  u32 *puVar3;
  u32 *puVar4;
  
  FUN_001aa91c();
  FUN_001118ac(param_1[0xff],0,2);
  FUN_00108f54(*param_1,0);
  puVar4 = param_1 + 0x17;
  puVar3 = param_1 + 0x1c;
  if (*(u8 *)(FUN_001aa91c() + 0x2a4) != 0 && *(u8 *)(FUN_001aa91c() + 0x4d) == 0) {
    if (*(u8 *)(DAT_003e1e04 + 0x178) == 0 && *(u8 *)(FUN_001aa91c() + 0x2b8) != 0) {
      FUN_00105470(*puVar4,1);
      FUN_00105470(*puVar3,1);
    }
    else {
      FUN_00105470(*puVar4,0);
      FUN_00105470(*puVar3,0);
    }
  }
  else {
    FUN_00105470(*puVar4,1);
    FUN_00105470(*puVar3,1);
  }
  FUN_001b7540(param_1);
  FUN_001b7798(param_1);
  FUN_001b77d4(param_1);
  FUN_001b7b24(param_1);
  FUN_001b7810(param_1);
  FUN_001b7870(param_1);
  FUN_001b7a1c(param_1);
  FUN_001b7d3c(param_1);
}

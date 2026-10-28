/* HSTMATCH module=hstp_trans_main.prx start=0x0018c540 end=0x0018c6e8 symbol=FUN_0018c540 lang=c++ */
/* Clone of src/eboot/dtor_release_buffers_0017fe4c.cpp (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: delete[] call takes the tested global as its argument (Ghidra dropped it), loop index declared before the walking pointer; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b23fc;
extern int DAT_003ea85c;
extern void FUN_00000788(...);
extern void FUN_000009e4(int);
extern void FUN_00000a00(...);
extern void FUN_0018cc90(...);
extern int FUN_0022667c(...);
extern void FUN_00104ff8(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" u32 * FUN_0018c540(u32 *param_1,short param_2)
{
  int *piVar1;
  int iVar3;
  u32 *puVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b23fc);
    if (DAT_003ea85c != 0) {
      FUN_000009e4(DAT_003ea85c);
      DAT_003ea85c = 0;
    }
    piVar1 = (int *)param_1[4];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[4] = 0;
    }
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0x48a];
      if (piVar1 != (int *)0x0) {
        delete ((VC_1 *)(piVar1));
        puVar2[0x48a] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 4);
    FUN_0018cc90(param_1);
    FUN_00000788(param_1 + 0xa68,FUN_00104ff8,0xc,10);
    FUN_00000788(param_1 + 0xa4a,FUN_00104ff8,0xc,10);
    FUN_00000788(param_1 + 0xa2c,FUN_00104ff8,0xc,10);
    FUN_0022667c(param_1 + 0x5ad,0xffffffff);
    FUN_0022667c(param_1 + 0x58a,0xffffffff);
    FUN_0022667c(param_1 + 0x567,0xffffffff);
    FUN_0022667c(param_1 + 0x544,0xffffffff);
    FUN_0022667c(param_1 + 0x521,0xffffffff);
    FUN_0022667c(param_1 + 0x4fe,0xffffffff);
    FUN_0022667c(param_1 + 0x4db,0xffffffff);
    FUN_0022667c(param_1 + 0x4b8,0xffffffff);
    FUN_0022667c(param_1 + 0x495,0xffffffff);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

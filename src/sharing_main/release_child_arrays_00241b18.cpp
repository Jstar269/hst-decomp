/* HSTMATCH module=hstp_trans_main.prx start=0x00241b18 end=0x00241c08 symbol=FUN_00241b18 lang=c++ */
/* Clone of src/eboot/release_child_arrays_00231a18.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: ordered the typed cursor and count locals to match both virtual cleanup walks; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b2b44;
extern void FUN_00000a00(...);
extern u32 * FUN_001087a8(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" u32 * FUN_00241b18(u32 *param_1,short param_2)
{
  int *piVar1;
  int iVar3;
  u32 *puVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2b44);
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0x5b];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        puVar2[0x5b] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 0xf);
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0x6a];
      if (piVar1 != (int *)0x0) {
        delete ((VC_1 *)(piVar1));
        puVar2[0x6a] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 10);
    FUN_001087a8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

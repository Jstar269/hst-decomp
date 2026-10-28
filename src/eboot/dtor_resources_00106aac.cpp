/* HSTMATCH module=EBOOT.BIN start=0x00106aac end=0x00106bb4 symbol=FUN_00106aac lang=c++ */
/* Clone of src/sharing_main/dtor_resources_0010c634.cpp (hstclone.py tag u5fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0c) corrected by hand: base destructor inlining and double null checks; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00307b38;
extern u8 DAT_00307b58;
extern u8 DAT_00307bac;
extern void FUN_000009e4(...);
extern void FUN_00000a00(...);
extern void FUN_000104e0(...);
extern u32 * FUN_000510c0(...);
}

extern "C" u32 * FUN_00106aac(u32 *param_1, short param_2)
{
  int *s2;

  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307b38);
    if (*(unsigned char *)((char *)param_1 + 88) != 0) {
      s2 = (int *)param_1[21];
      if (s2 != 0) {
        if (s2 != 0) {
          if (s2[2] != 0) {
            FUN_000009e4(s2[2]);
            s2[2] = 0;
          }
          if (s2[1] != 0) {
            FUN_000009e4(s2[1]);
            s2[1] = 0;
          }
          FUN_00000a00(s2);
        }
        param_1[21] = 0;
      }
    }
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_00307bac);
      if (param_1[20] != 0) {
        FUN_000104e0(param_1[20]);
        param_1[20] = 0;
      }
      if (param_1 != (u32 *)0x0) {
        *param_1 = (unsigned int)(&DAT_00307b58);
        FUN_000510c0(param_1, 0);
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

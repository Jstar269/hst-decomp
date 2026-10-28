/* HSTMATCH module=hstp_trans_main.prx start=0x0010c634 end=0x0010c73c symbol=FUN_0010c634 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0c) corrected by hand: base destructor inlining and double null checks; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b0e04;
extern u8 DAT_003b0e24;
extern u8 DAT_003b0e78;
extern void FUN_000009e4(...);
extern void FUN_00000a00(...);
extern void FUN_000104e0(...);
extern u32 * FUN_000519d4(...);
}

extern "C" u32 * FUN_0010c634(u32 *param_1, short param_2)
{
  int *s2;

  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0e04);
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
      *param_1 = (unsigned int)(&DAT_003b0e78);
      if (param_1[20] != 0) {
        FUN_000104e0(param_1[20]);
        param_1[20] = 0;
      }
      if (param_1 != (u32 *)0x0) {
        *param_1 = (unsigned int)(&DAT_003b0e24);
        FUN_000519d4(param_1, 0);
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

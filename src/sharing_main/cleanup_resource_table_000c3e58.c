/* HSTMATCH module=hstp_trans_main.prx start=0x000c3e58 end=0x000c3fcc symbol=FUN_000c3e58 lang=c99 */
/* Clone of src/eboot/cleanup_resource_table_000c07b8.c (hstclone.py tag km3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: pass each tested field pointer to FUN_000009e4 and keep the loop index separate from its scaled offset. */
#include "hst/types.h"

extern char DAT_003b06d4;
extern unsigned char DAT_003e1e0c;
extern void FUN_000009e4(void *);
extern void FUN_00000a00(void *);
extern u32 * FUN_0001ed28(void *, int);
extern void FUN_000c5140(void *, int);

#pragma opt_strength_reduction off

u32 * FUN_000c3e58(u32 *param_1,short param_2)
{
  int iVar1;
  u32 index;
  int offset;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b06d4);
    DAT_003e1e0c = 0;
    index = 0;
    if (param_1[0x1dd] != 0) {
      do {
        int scaled = index << 2;
        offset = (scaled + index) << 4;
        void *field44 = *(void **)((char *)param_1[0x1dc] + offset + 0x44);
        if (field44 != 0) {
          if (field44 != 0) {
            FUN_000009e4(field44);
            *(void **)((char *)param_1[0x1dc] + offset + 0x44) = 0;
          }
        } else {
          void *field40 = *(void **)((char *)param_1[0x1dc] + offset + 0x40);
          if (field40 != 0) {
            if (field40 != 0) {
              FUN_000009e4(field40);
              *(void **)((char *)param_1[0x1dc] + offset + 0x40) = 0;
            }
          }
        }
        index = index + 1;
      } while (index < param_1[0x1dd]);
    }
    if (param_1[0x1cb] != 0) {
      if (param_1[0x1cb] != 0) {
        FUN_000009e4((void *)param_1[0x1cb]);
        param_1[0x1cb] = 0;
      }
    }
    iVar1 = param_1[0x1db];
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_000009e4((void *)iVar1);
      param_1[0x1db] = 0;
    }
    if ((param_1 + 0x1df) != (u32 *)0x0 && (param_1 + 0x1df) != (u32 *)0x0) {
      FUN_000c5140(param_1 + 0x1df,0);
    }
    if ((param_1 + 0x1dc) != (u32 *)0x0 && (param_1 + 0x1dc) != (u32 *)0x0) {
      FUN_000c5140(param_1 + 0x1dc,0);
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

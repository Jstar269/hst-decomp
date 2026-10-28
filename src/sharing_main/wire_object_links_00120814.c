/* HSTMATCH module=hstp_trans_main.prx start=0x00120814 end=0x00120960 symbol=FUN_00120814 lang=c99 */
/* Clone of src/eboot/wire_object_links_001158f8.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: formed relative pointers from field addresses before subtracting nested bases and corrected a nested offset; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b0f4c;
extern u8 DAT_003b0f5c;
extern u8 DAT_003b0fa0;
extern u8 DAT_003b0fb0;
extern u8 DAT_003b0fbc;
extern u8 DAT_003b0fc8;
extern u8 DAT_003b100c;
extern u8 DAT_003b101c;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();

int * FUN_00120814(int *param_1,int param_2)
{
  if (param_1 != (int *)0x0) {
    param_1[2] = (int)&DAT_003b0f4c;
    *(u8 **)(*param_1 + 4) = &DAT_003b0fa0;
    **(u32 **)*param_1 = (unsigned int)(&DAT_003b0f5c);
    *(u8 **)(param_1[1] + 0x7c) = &DAT_003b0fb0;
    *(int *)(*(int *)*param_1 + 0xd0) = (int)((char *)param_1 + 0x30) - *(int *)*param_1;
    *(int *)(*param_1 + 0x10) = (int)((char *)param_1 + 0x110) - *param_1;
    *(int *)(param_1[1] + 0x80) = (int)(param_1 + 0x4c) - param_1[1];
    if (param_2 != 0) {
      if (param_1 + 0x4c != (int *)0x0) {
        param_1[0x6b] = (int)&DAT_003b0fbc;
        *(u8 **)param_1[0x4c] = &DAT_003b0fc8;
        *(int *)(param_1[0x4c] + 0xd0) = (int)((char *)param_1 + 0x1b0) - param_1[0x4c];
      }
      if (param_1 + 0x44 != (int *)0x0) {
        param_1[0x45] = (int)&DAT_003b100c;
        *(u8 **)param_1[0x44] = &DAT_003b101c;
        *(int *)(param_1[0x44] + 0xd0) = (int)((char *)param_1 + 0x120) - param_1[0x44];
      }
      if (param_1 + 0xc != (int *)0x0) {
        param_1[0xc] = (int)&DAT_003b0a68;
        FUN_0010642c(param_1 + 0xc,0);
      }
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

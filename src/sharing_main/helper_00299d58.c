/* HSTMATCH module=hstp_trans_main.prx start=0x00299d58 end=0x00299db0 symbol=FUN_00299d58 lang=c99 */
/* Clone of src/eboot/helper_00288624.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: modelled adjacent call fields as a 16-u8-aligned record (matching idiom: aligned local record); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f344c;
extern void FUN_001dae00();
extern u32 FUN_0029ace0();

struct WorkArgs_288624 {
  int field68;
  u8 result[4];
  int kind;
  int count;
  u32 id;
} __attribute__((aligned(16)));

void FUN_00299d58(int param_1,u32 param_2,int param_3)
{
  struct WorkArgs_288624 args;
  
  if (param_3 < 1) {
    FUN_001dae00(DAT_003f344c);
  }
  else {
    args.kind = 0x23;
    args.field68 = param_1 + 0x68;
    args.count = param_3;
    args.id = param_2;
    FUN_0029ace0(args.result,param_1 + 100,&args.field68,&args.kind);
  }
}

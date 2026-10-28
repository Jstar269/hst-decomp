/* HSTMATCH module=EBOOT.BIN start=0x00288624 end=0x0028867c symbol=FUN_00288624 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: modelled adjacent call fields as a 16-byte-aligned record (matching idiom: aligned local record); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a114;
extern void FUN_001cc6cc();
extern u32 FUN_00289544();

struct WorkArgs_288624 {
  int field68;
  u8 result[4];
  int kind;
  int count;
  u32 id;
} __attribute__((aligned(16)));

void FUN_00288624(int param_1,u32 param_2,int param_3)
{
  struct WorkArgs_288624 args;
  
  if (param_3 < 1) {
    FUN_001cc6cc(DAT_0034a114);
  }
  else {
    args.kind = 0x23;
    args.field68 = param_1 + 0x68;
    args.count = param_3;
    args.id = param_2;
    FUN_00289544(args.result,param_1 + 100,&args.field68,&args.kind);
  }
}

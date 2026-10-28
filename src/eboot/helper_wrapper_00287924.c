/* HSTMATCH module=EBOOT.BIN start=0x00287924 end=0x0028797c symbol=FUN_00287924 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: recovered the packed helper-call record and symbolic error-data address; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001b29a8();
extern u32 DAT_0034179c;
extern u32 FUN_00289544(int *, int, int *, int *);

struct ErrorCallState {
  int address;
  int result;
  int type;
  int count;
  int parameter;
  int unused[3];
};

void FUN_00287924(int param_1,u32 param_2,int param_3)
{
  struct ErrorCallState local;
  
  if (param_3 < 1) {
    FUN_001b29a8(&DAT_0034179c);
  }
  else {
    local.type = 0x33;
    local.parameter = param_2;
    local.count = param_3;
    local.address = param_1 + 0x68;
    FUN_00289544(&local.result,param_1 + 100,&local.address,&local.type);
  }
}

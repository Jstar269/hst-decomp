/* HSTMATCH module=hstp_trans_main.prx start=0x00299000 end=0x00299058 symbol=FUN_00299000 lang=c99 */
/* Clone of src/eboot/helper_wrapper_002878cc.c (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: recovered the packed helper-call record and symbolic error-data address; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001c0984();
extern u32 DAT_003eaad8;
extern u32 FUN_0029ace0(int *, int, int *, int *);

struct ErrorCallState {
  int address;
  int result;
  int type;
  int count;
  int parameter;
  int unused[3];
};

void FUN_00299000(int param_1,u32 param_2,int param_3)
{
  struct ErrorCallState local;
  
  if (param_3 < 1) {
    FUN_001c0984(&DAT_003eaad8);
  }
  else {
    local.type = 0x32;
    local.parameter = param_2;
    local.count = param_3;
    local.address = param_1 + 0x68;
    FUN_0029ace0(&local.result,param_1 + 100,&local.address,&local.type);
  }
}

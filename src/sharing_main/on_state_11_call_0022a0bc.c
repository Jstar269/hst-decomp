/* HSTMATCH module=hstp_trans_main.prx start=0x0022a0bc end=0x0022a100 symbol=FUN_0022a0bc lang=c99 */
/* Clone of src/eboot/on_state_11_call_0021ab48.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the call to FUN_001bfc3c takes the module global by address and the state value 11 as the second argument Ghidra dropped (li a1,11 before the compare); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Obj_0022a0bc {
  int f0;
  int f4;
} Obj_0022a0bc;

extern u8 DAT_003eaad8;
extern void FUN_001bfc3c(u8 *, int);
extern void FUN_0022a154(Obj_0022a0bc *, int);

void FUN_0022a0bc(Obj_0022a0bc *param_1)
{
  if (param_1->f4 == 0xb) {
    FUN_001bfc3c(&DAT_003eaad8, 0xb);
    FUN_0022a154(param_1, 0);
  }
}

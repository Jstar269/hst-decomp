/* HSTMATCH module=hstp_trans_main.prx start=0x001c4f58 end=0x001c4fe8 symbol=FUN_001c4f58 lang=c99 */
/* Clone of src/eboot/FUN_001b7298_001b7298.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_003eaad8;
extern int FUN_001c0bb0(int *, int);

void FUN_001c4f58(int param_1, int param_2)
{
  int result = 10;
  int flag = 0;

  if (*(u8 *)(param_1 + 0x90) != 0 && *(u8 *)(param_1 + 0x93) != 0)
    flag = 1;
  switch (param_2) {
  case 5:
    result = 9;
    break;
  case 4:
  case 3:
    result = flag ? 9 : 0x18;
    break;
  default:
    break;
  }
  result = FUN_001c0bb0(&DAT_003eaad8, result);
  *(int *)(param_1 + 0x58) = result;
}

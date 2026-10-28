/* HSTMATCH module=hstp_trans_main.prx start=0x00132c90 end=0x00132cd8 symbol=FUN_00132c90 lang=c99 */
/* Clone of src/eboot/match_three_ids_00127a20.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py) corrected by hand: OR chain written as an assignment chain (`if (!b) b = ...; return b;`) to get the xor/sltiu/bnez short-circuit; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e4868;
extern u32 DAT_003e486c;
extern u32 DAT_003e4874;

int FUN_00132c90(int param_1)
{
  int b;
  b = param_1 == DAT_003e4868;
  if (!b) b = param_1 == DAT_003e486c;
  if (!b) b = param_1 == DAT_003e4874;
  return b;
}

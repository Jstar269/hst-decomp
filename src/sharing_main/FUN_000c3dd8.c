/* HSTMATCH module=hstp_trans_main.prx start=0x000c3dd8 end=0x000c3e58 symbol=FUN_000c3dd8 lang=c99 */
/* Clone of src/eboot/FUN_000c0738.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the flag global typed as a u8; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b06d4;
extern u8 DAT_003e1e0c;
extern u32 DAT_003e1e10;
extern u32 * FUN_0001ec44();

u32 * FUN_000c3dd8(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b06d4);
  param_1[0x1dc] = 0;
  param_1[0x1dd] = 0;
  param_1[0x1de] = 0;
  param_1[0x1df] = 0;
  param_1[0x1e0] = 0;
  param_1[0x1e1] = 0;
  param_1[0xf] = 1;
  param_1[0x10] = 0;
  param_1[0x1a5] = 0;
  DAT_003e1e0c = 0;
  DAT_003e1e10 = 0;
  *(u8 *)(param_1 + 0x11) = 0;
  param_1[0x1cb] = 0;
  param_1[0x1db] = 0;
  param_1[0x1e2] = 0;
  param_1[0x1e3] = 0;
  return param_1;
}

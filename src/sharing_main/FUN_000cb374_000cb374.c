/* HSTMATCH module=hstp_trans_main.prx start=0x000cb374 end=0x000cb408 symbol=FUN_000cb374 lang=c99 */
/* Clone of src/eboot/FUN_000c7894_000c7894.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_003e1a0c;
extern u8 DAT_003e1e44;
extern void FUN_0005d408(int, float *);
extern void FUN_0005d4fc(int, int, float *);

void FUN_000cb374(void)
{
  float local_10[4];
  float local_20[4];

  if (DAT_003e1e44 != 0) {
    local_10[0] = 1.0f;
    local_10[3] = 1.0f;
    local_10[1] = 0.55f;
    local_10[2] = 0.75f;
    FUN_0005d408(DAT_003e1a0c, local_10);
    local_20[0] = 0.4f;
    local_20[1] = 0.2f;
    local_20[2] = 0.3f;
    local_20[3] = 1.0f;
    FUN_0005d4fc(DAT_003e1a0c, 0, local_20);
  }
}

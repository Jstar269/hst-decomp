/* HSTMATCH module=hstp_trans_main.prx start=0x00119e24 end=0x00119e58 symbol=FUN_00119e24 lang=c99 */
/* Clone of src/eboot/FUN_00111010.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct GateObj {
  char pad00[0x88];
  u8 busy;          /* 0x88 set while FUN_00108aec runs */
} GateObj;

extern GateObj *DAT_003eaaac;
extern void FUN_00108aec();

/* Runs FUN_00108aec with the global object's busy flag raised. */
void FUN_00119e24(void)
{
  DAT_003eaaac->busy = 1;
  FUN_00108aec();
  DAT_003eaaac->busy = 0;
}

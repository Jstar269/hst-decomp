/* HSTMATCH module=hstp_trans_main.prx start=0x000bde38 end=0x000bde80 symbol=FUN_000bde38 lang=c99 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/pad_status_poll_000baac8.c: string and callee addresses substituted); exact match verified; names and types await human review. */
#include "hst/types.h"
extern u8 DAT_0037b8a4[];
extern u8 DAT_0037b8cc[];
extern void FUN_000bd6f0();
extern int FUN_002c7b48(void);

/* Shuts the ad-hoc matching library down and logs the outcome; returns 1 on success. */
bool FUN_000bde38(void)
{
  int result;

  result = FUN_002c7b48();
  if (result < 0) {
    FUN_000bd6f0(DAT_0037b8a4,result);
    return 0;
  }
  FUN_000bd6f0(DAT_0037b8cc);
  return 1;
}

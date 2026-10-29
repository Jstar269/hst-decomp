/* HSTMATCH module=hstp_trans_main.prx start=0x0023576c end=0x00235790 symbol=FUN_0023576c lang=c99 */
/* Clone of src/eboot/FUN_002261f8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Gathers four words, each read through its own pointer, into a four-word record. */
void FUN_0023576c(u32 *dst,u32 *src0,u32 *src1,u32 *src2, u32 *src3)
{
  *dst = *src0;
  dst[1] = *src1;
  dst[2] = *src2;
  dst[3] = *src3;
}

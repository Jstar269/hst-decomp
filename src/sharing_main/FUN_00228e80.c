/* HSTMATCH module=hstp_trans_main.prx start=0x00228e80 end=0x00228eb0 symbol=FUN_00228e80 lang=c99 */
/* Clone of src/eboot/FUN_00219968.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/vec.h"

extern void FUN_00022440();

/* dst += src (4-float vectors). */
Float4 * FUN_00228e80(Float4 *dst,const Float4 *src)
{
  FUN_00022440(dst,dst,src);
  return dst;
}

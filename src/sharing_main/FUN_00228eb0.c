/* HSTMATCH module=hstp_trans_main.prx start=0x00228eb0 end=0x00228ee0 symbol=FUN_00228eb0 lang=c99 */
/* Clone of src/eboot/FUN_00219968.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/vec.h"

extern void FUN_0002245c();

/* dst += src (4-float vectors). */
Float4 * FUN_00228eb0(Float4 *dst,const Float4 *src)
{
  FUN_0002245c(dst,dst,src);
  return dst;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00129eb0 end=0x00129ed8 symbol=FUN_00129eb0 lang=c99 */
/* Clone of src/eboot/FUN_0011ecdc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Four words copied as plain integers. */
typedef struct Words4 {
  u32 w[4];
} Words4;

/* Copies a 16-byte record word by word; returns dst. */
Words4 * FUN_00129eb0(Words4 *dst,Words4 *src)
{
  dst->w[0] = src->w[0];
  dst->w[1] = src->w[1];
  dst->w[2] = src->w[2];
  dst->w[3] = src->w[3];
  return dst;
}

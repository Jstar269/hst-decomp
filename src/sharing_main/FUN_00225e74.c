/* HSTMATCH module=hstp_trans_main.prx start=0x00225e74 end=0x00225e94 symbol=FUN_00225e74 lang=c99 */
/* Clone of src/eboot/FUN_00216e70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/color_words.h"

/* Narrow the three channel words to bytes and add the alpha byte. */
void FUN_00225e74(ColorBytes *dst,ColorWords *src,u8 alpha)
{
  u32 green;
  u32 blue;
  
  blue = src->b;
  green = src->g;
  dst->r = (char)src->r;
  dst->g = (char)green;
  dst->b = (char)blue;
  dst->a = alpha;
}

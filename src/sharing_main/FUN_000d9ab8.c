/* HSTMATCH module=hstp_trans_main.prx start=0x000d9ab8 end=0x000d9adc symbol=FUN_000d9ab8 lang=c99 */
/* Clone of src/eboot/FUN_000d5dc8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0000430c();

/* Comparator: true when FUN_0000430c reports a before b; the first argument (the comparator object) is unused. */
bool FUN_000d9ab8(u32 self,u32 a,u32 b)
{
  int result;
  
  result = FUN_0000430c(a,b);
  return result < 0;
}

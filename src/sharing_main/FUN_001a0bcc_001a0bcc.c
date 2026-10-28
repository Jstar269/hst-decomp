/* HSTMATCH module=hstp_trans_main.prx start=0x001a0bcc end=0x001a0c10 symbol=FUN_001a0bcc lang=c99 */
/* Clone of src/eboot/FUN_001943bc_001943bc.c (hstclone.py tag u3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003eaa70;
extern u32 DAT_003eaa7c;
extern u32 DAT_003eaa80;

u32 FUN_001a0bcc(void)
{
  if (DAT_003eaa80 == 0) goto zero;
  if (DAT_003eaa7c == 0) goto zero;
  if (DAT_003eaa70 == 0) goto zero;
  return 1;
zero:
  return 0;
}

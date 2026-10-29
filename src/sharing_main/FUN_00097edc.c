/* HSTMATCH module=hstp_trans_main.prx start=0x00097edc end=0x00097f14 symbol=FUN_00097edc lang=c99 */
/* Clone of src/eboot/FUN_00095dd8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();

/* Constructor of a 0x40-byte object: sets a field, then calls the fill routine (value 0, size 0x40). */
int FUN_00097edc(int self)
{
  *(u32 *)(self + 0x2c) = 1;
  FUN_000114c0(self,0,0x40);
  return self;
}

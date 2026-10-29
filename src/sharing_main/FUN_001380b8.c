/* HSTMATCH module=hstp_trans_main.prx start=0x001380b8 end=0x0013813c symbol=FUN_001380b8 lang=c99 */
/* Clone of src/eboot/FUN_0012cc4c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Size of the temporary object built on the stack. */
#define TEMP_OBJ_SIZE 704

extern u8 DAT_003b13d4;
extern u8 DAT_003b13f0;
extern u32 DAT_003da704;
extern u32 DAT_003e48b4; /* the one live instance */
extern int FUN_0005c2f8();
extern int FUN_0005c688();
extern int FUN_0005c700();
extern u32 * FUN_0014b1a4();
extern u32 * FUN_00297ebc();

/* Constructor: builds the base and the member (word offset 0x4c8), sets both vtables, clears four words, records
   the instance, and hands a temporary object to the shared registry before destroying it. */
u32 * FUN_001380b8(u32 *self)
{
  u8 temp_obj [TEMP_OBJ_SIZE];
  
  FUN_0014b1a4();
  FUN_00297ebc(self + 0x4c8);
  *self = (unsigned int)(&DAT_003b13d4);
  self[0x4c8] = (unsigned int)(&DAT_003b13f0);
  self[0x4e4] = 0;
  self[0x4e5] = 0;
  self[0x4e6] = 0;
  self[0x4e7] = 0;
  DAT_003e48b4 = (unsigned int)(self);
  FUN_0005c2f8(temp_obj);
  FUN_0005c700(DAT_003da704,temp_obj);
  FUN_0005c688(temp_obj,0xffffffff);
  return self;
}

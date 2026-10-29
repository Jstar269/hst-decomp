/* HSTMATCH module=hstp_trans_main.prx start=0x00291520 end=0x00291588 symbol=FUN_00291520 lang=c99 */
/* Clone of src/eboot/FUN_002800ac_002800ac.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: reused and stored the allocation result on both null and initialized paths; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003a7728;
extern u32 DAT_003f3b20;
extern char DAT_003a76e8[];
extern int FUN_00000bcc();
extern int * FUN_00065884();
extern u32 FUN_00065ab8();

/* Table holder: owns one separately allocated table object and registers itself in a global. */
typedef struct TableHolder {
  int table; /* 0x00 allocated table object */
} TableHolder;

TableHolder * FUN_00291520(TableHolder *self)
{
  int table;

  self->table = 0;
  DAT_003f3b20 = (unsigned int)(self);
  table = FUN_00000bcc(0x10);
  if (table != 0) {
    table = (int)FUN_00065884(table);
  }
  self->table = table;
  FUN_00065ab8(table,DAT_003a76e8 + 0x10,1,&DAT_003a7728);
  return self;
}

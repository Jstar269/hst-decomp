/* HSTMATCH module=EBOOT.BIN start=0x002800ac end=0x00280114 symbol=FUN_002800ac lang=c99 */
/* AdhocTable ctor: data/menu/challenge/Challenge_AdhocTable.txt; see docs/DATA-TABLES.md */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: reused and stored the allocation result on both null and initialized paths; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002fe8c8;
extern u32 DAT_0034a7f0;
extern char DAT_002fe888[];
extern int FUN_00000bcc();
extern int * FUN_000649c0();
extern u32 FUN_00064bf4();

/* Table holder: owns one separately allocated table object and registers itself in a global. */
typedef struct TableHolder {
  int table; /* 0x00 allocated table object */
} TableHolder;

TableHolder * FUN_002800ac(TableHolder *self)
{
  int table;

  self->table = 0;
  DAT_0034a7f0 = (unsigned int)(self);
  table = FUN_00000bcc(0x10);
  if (table != 0) {
    table = (int)FUN_000649c0(table);
  }
  self->table = table;
  FUN_00064bf4(table,DAT_002fe888 + 0x10,1,&DAT_002fe8c8);
  return self;
}

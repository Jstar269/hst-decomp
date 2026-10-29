/* HSTMATCH module=EBOOT.BIN start=0x0024d808 end=0x0024d8dc symbol=FUN_0024d808 lang=c99 */
/* AityakuTable ctor: data/common/aityaku/aityaku.csv; see docs/DATA-TABLES.md */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/aityaku_table.h"

extern u8 DAT_002fbdbc;
extern u8 DAT_003070bc;
extern AityakuTable * DAT_0034a77c;
extern char DAT_002fbd9c[];
extern char DAT_002fbdc0[];
extern char DAT_002fbddc[];
extern char DAT_002fbde8[];
extern u64 FUN_00020f5c(float);
extern int * FUN_000649c0();
extern u32 FUN_000651b8();
extern u32 * FUN_0008c230();
extern void FUN_0024d8dc();
extern void FUN_0024d908(AityakuTable *);

/* Construct the table: load the CSV, compute the thresholds and log them. */
AityakuTable * FUN_0024d808(AityakuTable *self)
{
  int level;
  u64 threshold;
  
  FUN_000649c0();
  self->vtable = &DAT_003070bc;
  FUN_0008c230(self->sub10);
  FUN_0008c230(self->sub20);
  DAT_0034a77c = self;
  FUN_000651b8(self,DAT_002fbd9c,1,0,&DAT_002fbdbc);
  FUN_0024d908(self);
  FUN_0024d8dc(DAT_002fbdc0);
  FUN_0024d8dc(DAT_002fbddc);
  level = 0;
  do {
    threshold = FUN_00020f5c(self->threshold[level]);
    FUN_0024d8dc(DAT_002fbde8,level + 1,(int)threshold,(int)((u64)threshold >> 0x20));
    level = level + 1;
  } while (level < AITYAKU_LEVELS);
  return self;
}

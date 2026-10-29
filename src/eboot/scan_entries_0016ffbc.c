/* HSTMATCH module=EBOOT.BIN start=0x0016ffbc end=0x00170068 symbol=FUN_0016ffbc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: hold the call context and table base in locals before indexed access. */
#include "hst/types.h"
#include "hst/table_page.h"

extern void *DAT_00338b08;
extern int FUN_000d8c24(void *, int, int);

#pragma opt_strength_reduction off

/* Returns 1 when any record in the list maps to a live object whose byte-table cell equals the flagged value. */
u32 FUN_0016ffbc(TablePage *self)
{
  int obj;
  u32 count;
  u32 index;
  int *record;
  
  index = 0;
  if (self->listC.count != 0) {
LOOP_BODY:
      void *context = DAT_00338b08;
      int **entries = self->listC.items;
      record = entries[index];
      obj = FUN_000d8c24(context,3,*record);
      if (obj != 0) {
        if (*(signed char *)(obj + 0x60) >= 0) {
          if (self->tables[2][*record] == TABLE_CELL_FLAGGED) {
            return 1;
          }
        }
      }
      count = self->listC.count;
      index = index + 1;
    if (index < count) goto LOOP_BODY;
  }
  return 0;
}

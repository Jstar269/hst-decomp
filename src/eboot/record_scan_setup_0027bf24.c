/* HSTMATCH module=EBOOT.BIN start=0x0027bf24 end=0x0027c008 symbol=FUN_0027bf24 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/table_player.h"

extern TableRec *DAT_0034a7e4;
extern void FUN_0027c2c8(float, TablePlayer *, TableRec *, TableRec *);
extern int FUN_0027c774(TablePlayer *, int);

/* Scan the table for the first usable record with the given key and make it the override, then start the transition. */
void FUN_0027bf24(TablePlayer *self, int key, int kind, int param_4)
{
  int idx = -1;
  int i = 0;

  self->time = 0;
  self->offset = 0;
  while (i < TABLE_REC_COUNT) {
    TableRec *r = &DAT_0034a7e4[i];
    if (key == r->key && r->unk3c > 0) {
      idx = FUN_0027c774(self, i);
      if (idx >= 0) break;
    }
    i++;
  }
  self->override_idx = idx;
  self->override_kind = kind;
  FUN_0027c2c8((float)param_4, self,
               &DAT_0034a7e4[self->cur],
               &DAT_0034a7e4[idx]);
}

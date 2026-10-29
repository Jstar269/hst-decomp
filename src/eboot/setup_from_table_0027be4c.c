/* HSTMATCH module=EBOOT.BIN start=0x0027be4c end=0x0027bf24 symbol=FUN_0027be4c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/table_player.h"

extern TableRec *DAT_0034a7e4;
extern int FUN_0027c774(TablePlayer *, int);
extern void FUN_0027c008(TablePlayer *);
extern void FUN_0027c908(TablePlayer *, int);
extern void FUN_0001f1fc(TablePlayer *, int);

/* Reset the player, pick the first record with the given key (and a positive count) and start it. */
void FUN_0027be4c(TablePlayer *self, int key, s32 param_3)
{
  int found;
  int i;

  self->unk68 = param_3;
  self->time = 0;
  self->offset = 0;
  found = -1;
  for (i = 0; i < TABLE_REC_COUNT; i++) {
    TableRec *rec = &DAT_0034a7e4[i];
    if (key == rec->key
        && 0 < rec->unk3c) {
      found = FUN_0027c774(self, i);
      if (0 <= found)
        break;
    }
  }
  self->cur = -1;
  FUN_0027c008(self);
  FUN_0027c908(self, found);
  FUN_0001f1fc(self, 1);
  self->active = 1;
}

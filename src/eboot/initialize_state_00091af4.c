/* HSTMATCH module=EBOOT.BIN start=0x00091af4 end=0x00091bc8 symbol=FUN_00091af4 lang=c99 data=0x002d28d4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d28d4-0x002d28ea) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/model_set_full.h"

extern u8 DAT_003386f0;
extern char DAT_002d2840[];
extern char DAT_002d284c[];
extern void FUN_000944bc();

/* Reset the object to its initial state and rebuild its two bone sub-objects. */
void FUN_00091af4(ModelSetFull *self)
{
  unsigned int count;
  unsigned int global_count;
  unsigned int sentinel_count;
  int *cursor;
  int *global_cursor;
  int *sentinel_cursor;

  count = 0;
  cursor = (int *)self; /* model slots sit 0x14 words past the cursor */
  do {
    ++count;
    cursor[0x14] = 0;
    ++cursor;
  } while (count < MSET_SLOT_COUNT);
  self->unk68 = -1;
  self->unk6c = 0;
  self->unk70 = 0;
  self->unk74 = 0;
  self->unk75 = 0;
  global_count = 0;
  global_cursor = (int *)&DAT_003386f0;
  do {
    global_cursor[0] = 0;
    global_cursor[1] = 0;
    ++global_count;
    global_cursor[2] = 0;
    global_cursor += 4;
  } while (global_count < 2);
  sentinel_count = 0;
  sentinel_cursor = (int *)self; /* ids start one word past the cursor */
  do {
    ++sentinel_count;
    sentinel_cursor[1] = -1;
    ++sentinel_cursor;
  } while (sentinel_count < MSET_LINK_COUNT);
  self->unk20 = -1;
  self->entries = 0;
  FUN_000944bc(self->boneA,"Bip01Spine",DAT_002d284c);
  FUN_000944bc(self->boneB,DAT_002d2840,"Bip01Neck");
}

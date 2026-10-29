/* HSTMATCH module=EBOOT.BIN start=0x00089648 end=0x00089724 symbol=FUN_00089648 lang=c99 rodata=0x2be858 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: enumerate the full dense case range (0..24) so MWCC emits the 25-entry jump table, and place .rodata (rodata=0x2be858) so the table address matches; write the case-4 test as nested positive conditions. */
#include "hst/types.h"
#include "hst/member_session.h"

typedef struct EventTarget {
  char pad00[0x59];
  u8 unk59;       /* 0x59 cleared by events 8, 13 and 14 */
  char pad5a[0xe];
  u8 unk68;       /* 0x68 cleared by event 13 when the global flag is set */
  char pad69[0x98 - 0x69];
  u32 unk98;      /* 0x98 passed to a function on event 18 */
  char pad9c[4];
  u32 unka0;      /* 0xa0 passed to a function on event 18 */
} EventTarget;

extern u8 DAT_003386b8;
extern MemberSession * DAT_00338ac4;
extern void FUN_00119fb4();
extern void FUN_001f8858();
extern void FUN_002b7960();

/* Event handler: reacts to the event ids 4, 8, 13, 14 and 18, ignores the rest of 0..24; always returns 0. */
u32 FUN_00089648(EventTarget *self,unsigned int event)
{
  switch(event) {
  case 4:
    if (DAT_003386b8 != 0) {
      if ((DAT_00338ac4 != 0) && (2 >= DAT_00338ac4->prev_count)) {
        FUN_002b7960(0,0x28);
      }
      else {
        FUN_002b7960(0,0x26);
      }
    }
    break;
  case 8:
    self->unk59 = 0;
    break;
  case 13:
    self->unk59 = 0;
    if (DAT_003386b8 != 0) {
      self->unk68 = 0;
    }
    break;
  case 14:
    self->unk59 = 0;
    break;
  case 18:
    FUN_00119fb4(self->unk98);
    FUN_001f8858(self->unka0);
    break;
  case 0: case 1: case 2: case 3:
  case 5: case 6: case 7:
  case 9: case 10: case 11: case 12:
  case 15: case 16: case 17:
  case 19: case 20: case 21: case 22: case 23: case 24:
    break;
  }
  return 0;
}

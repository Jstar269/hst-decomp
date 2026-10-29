/* HSTMATCH module=EBOOT.BIN start=0x000b80a4 end=0x000b8118 symbol=FUN_000b80a4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000b8118(void);

typedef struct EventObj {
  char pad00[0x3d];
  u8 unk3d;       /* 0x3d set by event 0x14 */
  char pad3e[0x64 - 0x3e];
  int unk64;      /* 0x64 copy of unk68 (event 8) or unk6c (event 0xe) */
  int unk68;      /* 0x68 */
  int unk6c;      /* 0x6c */
} EventObj;

enum { EVENT_A = 8, EVENT_B = 0xe, EVENT_C = 0x14 };

/* Event handler: events 8 and 0xe select a value and run the helper, event 0x14 sets a flag; always returns 0. */
u32 FUN_000b80a4(EventObj *self, int event)
{
  switch (event) {
  case EVENT_A:
  case EVENT_B:
    if (event == EVENT_A)
      self->unk64 = self->unk68;
    else
      self->unk64 = self->unk6c;
    FUN_000b8118();
    break;
  case EVENT_C:
    self->unk3d = 1;
    break;
  default:
    break;
  }
  return 0;
}

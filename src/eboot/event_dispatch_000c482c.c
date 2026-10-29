/* HSTMATCH module=EBOOT.BIN start=0x000c482c end=0x000c48d4 symbol=FUN_000c482c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/online_game.h"

extern u32 DAT_00338ac4;
extern u32 DAT_00338b44;
extern u32 FUN_000ba78c(u32);
extern int FUN_000def58();

#define EVENT_STOP_MANAGER 0x13 /* same call the cleanup makes before deleting the manager */
#define EVENT_PEER_A 0x14
#define EVENT_PEER_B 0x19

/* Handles the three events this object reacts to; always returns 0. */
u32 FUN_000c482c(OnlineGame *self,int event)
{
  int ready;

  switch (event) {
  case EVENT_STOP_MANAGER:
    if (DAT_00338ac4 != 0) {
      FUN_000ba78c(DAT_00338ac4);
    }
    break;
  case EVENT_PEER_A:
    ready = FUN_000def58(DAT_00338b44);
    if (ready != 0) {
      self->link->flag = 1;
    }
    break;
  case EVENT_PEER_B:
    ready = FUN_000def58(DAT_00338b44);
    if (ready != 0) {
      self->link->flag = 1;
    }
    break;
  }
  return 0;
}

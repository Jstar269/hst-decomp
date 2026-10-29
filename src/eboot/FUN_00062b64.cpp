/* HSTMATCH module=EBOOT.BIN start=0x00062b64 end=0x00062c5c symbol=FUN_00062b64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/sound_player.h"

extern "C" int FUN_00076454(int a, int b);
extern "C" int FUN_000761a8(int a, int b, int c);
extern "C" void FUN_00077470(int a, int b, int c);
extern "C" int FUN_000777b4(int a);
extern "C" void FUN_0007771c(int a, int b);

/* Starts a sound from the player's source and returns its handle (-1 when there is no source). When tracking
   the last handle, the previous one is closed first and the new one is remembered. */
extern "C" int FUN_00062b64(SoundPlayer *self, int arg_a, int arg_b)
{
  if (self->source < 0) {
    return -1;
  }
  if (self->track_last != 0) {
    int old = self->last_handle;
    if (old >= 0) {
      FUN_00076454(old, 0);
      if (self->track_last != 0 && self->last_handle == old) {
        self->last_handle = -1;
      }
    }
  }
  int handle = FUN_000761a8(self->source, arg_a, arg_b);
  if (self->track_last != 0 && handle >= 0) {
    FUN_00077470(handle, 0, 0x10000);
    self->last_handle = handle;
  }
  if (handle >= 0 && FUN_000777b4(handle) == 0) {
    FUN_0007771c(handle, 2);
  }
  return handle;
}

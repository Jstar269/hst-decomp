/* HSTMATCH module=EBOOT.BIN start=0x00062e40 end=0x00062ee8 symbol=FUN_00062e40 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Closes the handle (when it is not negative), clears the cached handle at +0xc when it still
   matches, then spins up to 30 times calling FUN_00062150(30.0f)/FUN_002b7a78() until the global
   counter DAT_00331b80 has changed from the value saved on entry. */
#include "hst/sound_player.h"

#define WAIT_PASSES 30

extern "C" int DAT_00331b80;
extern "C" void FUN_00076454(int a, int b);
extern "C" void FUN_00062150(float f);
extern "C" void FUN_002b7a78();

extern "C" void FUN_00062e40(SoundPlayer *self, int handle)
{
  int old = DAT_00331b80;
  if (handle >= 0) {
    FUN_00076454(handle, 0);
    if (self->track_last != 0 && self->last_handle == handle) {
      self->last_handle = -1;
    }
  }
  int i = 0;
  do {
    if (old - 1 == DAT_00331b80) {
      break;
    }
    FUN_00062150(30.0f);
    FUN_002b7a78();
    i++;
  } while (i < WAIT_PASSES);
}

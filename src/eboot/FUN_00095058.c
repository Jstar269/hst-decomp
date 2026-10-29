/* HSTMATCH module=EBOOT.BIN start=0x00095058 end=0x000950e0 symbol=FUN_00095058 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: keep the two return blocks in the order ret1,ret0 (declare ret1 first) and end the function with an explicit `goto ret0` as the false-path fall-through; flag and the compared byte are unsigned char (andi/lbu). */

#include "hst/keyed_state.h"

extern int FUN_000950e0();

/* True when mode and key match, the frame check passes and the flag matches (or the mode is 0 or 5). */
int FUN_00095058(KeyedState *self,int mode,int key,unsigned int frame,unsigned char flag)
{
  int frame_ok;

  if (self->mode == mode) {
    if (self->key == key) {
      frame_ok = FUN_000950e0(self,frame);
      if (frame_ok != 0) {
        if (self->flag == flag) {
          goto ret1;
        }
        if (self->mode == 0) {
          goto ret1;
        }
        if (self->mode != 5) {
          goto ret0;
        }
        goto ret1;
      }
    }
  }
  goto ret0;
ret1:
  return 1;
ret0:
  return 0;
}

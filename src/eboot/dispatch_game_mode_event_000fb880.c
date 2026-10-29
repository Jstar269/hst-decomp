/* HSTMATCH module=EBOOT.BIN start=0x000fb880 end=0x000fba28 symbol=FUN_000fb880 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: symbolized global references and expressed mode dispatch with switches; exact match verified; names and types await human review. */
#include "hst/mode_screen.h"
#include "hst/game_mode_state.h"

extern GameModeState * DAT_003386b0;
extern u32 DAT_0034a820;
extern char DAT_002d823c[];
extern u8 DAT_0030ebf4;
extern void FUN_0001cad0(void *, int, char *);
extern void FUN_0001cb88(void *);
extern void FUN_000f79b8();
extern void FUN_000f7e30();
extern u32 FUN_000f9508();
extern void FUN_000fbaf4();
extern void FUN_000fbbf8();
extern void FUN_001fc3dc();
extern void FUN_001fc4e8();
extern void FUN_00291b8c();
extern void FUN_00291cdc();

enum {
  MODE_EVENT_START = 0,
  MODE_EVENT_STOP = 0x12,
  MODE_EVENT_START_ALT = 0x18
};

#define MODE_BLOCKING 9 /* in this mode only the stop and alternate-start events are handled */

/* Run the start/stop side effects around the generic event handler. */
u32 FUN_000fb880(ModeScreen *self,int event,u32 arg3,u32 arg4)
{
  u32 result;
  
  if (((DAT_003386b0->mode == MODE_BLOCKING) && (event != MODE_EVENT_STOP)) && (event != MODE_EVENT_START_ALT)) {
    return 0;
  }
  switch (event) {
    case MODE_EVENT_START:
      FUN_0001cad0(&DAT_0030ebf4,1,DAT_002d823c);
      FUN_000f79b8(self->core);
      FUN_000fbaf4(self->slot[1]);
      if (DAT_0034a820 != 0) FUN_00291b8c(DAT_0034a820,2);
      FUN_0001cb88(&DAT_0030ebf4);
      FUN_001fc3dc(self->slot[0],0);
      break;
    case MODE_EVENT_START_ALT:
      FUN_0001cad0(&DAT_0030ebf4,1,DAT_002d823c);
      FUN_000f79b8(self->core);
      FUN_000fbaf4(self->slot[1]);
      if (DAT_0034a820 != 0) FUN_00291b8c(DAT_0034a820,2);
      FUN_0001cb88(&DAT_0030ebf4);
      FUN_001fc3dc(self->slot[0],1);
      break;
  }
  result = (u32)self->core;
  result = FUN_000f9508(result,event,arg3,arg4);
  switch (event) {
    case MODE_EVENT_STOP:
      FUN_001fc4e8(self->slot[0],1);
      FUN_000fbbf8(self->slot[1]);
      FUN_000f7e30(self->core,0);
      if (DAT_0034a820 != 0) FUN_00291cdc(DAT_0034a820);
  }
  return result;
}

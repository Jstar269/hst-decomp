/* HSTMATCH module=EBOOT.BIN start=0x000b939c end=0x000b9450 symbol=FUN_000b939c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: changed FUN_000487c8 return type from bool to int to preserve retail integer testing; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pad_state.h"
#include "hst/debug_cam_host.h"

typedef struct ModeInfo {
  char pad00[0x3c];
  int state;        /* 0x3c */
} ModeInfo;

typedef struct SaveInfo {
  char pad00[0x1052];
  char viewSlot;    /* 0x1052 the current view number is kept here */
} SaveInfo;

#define MODE_STATE_PLAY 4

extern PadState * DAT_002cfc8c;
extern ModeInfo * DAT_003386b0;
extern u32 DAT_00338c20;
extern SaveInfo * DAT_00341ccc;
extern int FUN_000487c8();
extern void FUN_000b8118();
extern void FUN_000b94b8();
extern u32 FUN_000fb7b8();

/* Cycle button: advance the view while playing, then update the camera. */
void FUN_000b939c(DebugCamHost *host)
{
  int view;
  int blocked;
  
  if ((((DAT_002cfc8c->byte88.st0 == 0) &&
       (blocked = FUN_000487c8(), blocked == 0)) && (blocked = FUN_000fb7b8(DAT_00338c20), blocked == 0))
     && (DAT_003386b0->state == MODE_STATE_PLAY)) {
    view = (host->view + 1) % DEBUG_VIEW_COUNT;
    host->view = view;
    DAT_00341ccc->viewSlot = (char)view;
    host->active = host->view;
    FUN_000b8118(host);
  }
  FUN_000b94b8(host);
}

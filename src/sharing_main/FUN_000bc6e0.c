/* HSTMATCH module=hstp_trans_main.prx start=0x000bc6e0 end=0x000bc794 symbol=FUN_000bc6e0 lang=c99 */
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

extern PadState * DAT_003751d4;
extern ModeInfo * DAT_003e19f0;
extern u32 DAT_003e1f60;
extern SaveInfo * DAT_003eb004;
extern int FUN_00048958();
extern void FUN_000bb408();
extern void FUN_000bc7fc();
extern u32 FUN_00100ef4();

/* Cycle button: advance the view while playing, then update the camera. */
void FUN_000bc6e0(DebugCamHost *host)
{
  int view;
  int blocked;
  
  if ((((DAT_003751d4->byte88.st0 == 0) &&
       (blocked = FUN_00048958(), blocked == 0)) && (blocked = FUN_00100ef4(DAT_003e1f60), blocked == 0))
     && (DAT_003e19f0->state == MODE_STATE_PLAY)) {
    view = (host->view + 1) % DEBUG_VIEW_COUNT;
    host->view = view;
    DAT_003eb004->viewSlot = (char)view;
    host->active = host->view;
    FUN_000bb408(host);
  }
  FUN_000bc7fc(host);
}

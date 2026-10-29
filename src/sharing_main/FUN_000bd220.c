/* HSTMATCH module=hstp_trans_main.prx start=0x000bd220 end=0x000bd240 symbol=FUN_000bd220 lang=c99 */
/* Clone of src/eboot/FUN_000b9edc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/debug_cam_host.h"

/* Advance the second view counter and make it the active view. */
void FUN_000bd220(DebugCamHost *host)
{
  int view;
  
  view = (host->altView + 1) % DEBUG_VIEW_COUNT;
  host->altView = view;
  host->active = view;
}

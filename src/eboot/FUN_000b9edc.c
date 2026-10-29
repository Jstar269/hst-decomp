/* HSTMATCH module=EBOOT.BIN start=0x000b9edc end=0x000b9efc symbol=FUN_000b9edc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/debug_cam_host.h"

/* Advance the second view counter and make it the active view. */
void FUN_000b9edc(DebugCamHost *host)
{
  int view;
  
  view = (host->altView + 1) % DEBUG_VIEW_COUNT;
  host->altView = view;
  host->active = view;
}

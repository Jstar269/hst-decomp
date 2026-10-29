/* Host of the debug camera: current slot index and the view numbers cycled modulo DEBUG_VIEW_COUNT. */
#ifndef HST_DEBUG_CAM_HOST_H
#define HST_DEBUG_CAM_HOST_H

#define DEBUG_VIEW_COUNT 3 /* views the debug camera cycles through */

typedef struct DebugCamHost {
  char pad00[0x64];
  int active;     /* 0x64 copy of the chosen view */
  int view;       /* 0x68 view advanced by the cycle button */
  int altView;    /* 0x6c second view counter */
} DebugCamHost;

#endif

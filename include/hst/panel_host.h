/* Panel object of the 0x15a0xx-0x15a6xx sources: countdown, state, two owned widgets, two nodes and three slot objects. */
#ifndef HST_PANEL_HOST_H
#define HST_PANEL_HOST_H

#include "hst/types.h"
#include "hst/ui_node.h"

#define PANEL_HOST_NODES 2 /* nodes switched together */
#define PANEL_HOST_SLOTS 3 /* slot objects deleted by the destructor */

typedef struct PanelHost {
  const void *vtable;               /* 0x00 */
  char pad04[4];
  int countdown;                    /* 0x08 frames left before input is read */
  char pad0c[8];
  int state;                        /* 0x14 */
  int unk18;                        /* 0x18 */
  u8 unk1c;                         /* 0x1c */
  char pad1d[7];
  void *widgetA;                    /* 0x24 owned widget, updated every frame */
  void *widgetB;                    /* 0x28 second widget, updated every frame */
  UiNode *node[PANEL_HOST_NODES];   /* 0x2c */
  void *slot[PANEL_HOST_SLOTS];     /* 0x34 */
} PanelHost;

#endif

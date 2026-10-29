/* Panel state object reached through the owner's +0x15c pointer (text pick, stored text, map member). */
#ifndef HST_PANEL_DATA_H
#define HST_PANEL_DATA_H

#include "hst/types.h"
#include "hst/text_bank_lookup.h"

typedef struct PanelData {
  char pad00[0x20];
  u32 unk20;                /* 0x20 passed to the layout helper with the chosen text */
  TextBank *bank;           /* 0x24 text bank the panel reads its strings from */
  char pad28[0x34 - 0x28];
  char map34[0x5c - 0x34];  /* 0x34 map member, searched with (group, index) keys */
  void *unk5c;              /* 0x5c */
  char pad60;
  u8 unk61;                 /* 0x61 */
  u8 unk62;                 /* 0x62 */
  u8 unk63;                 /* 0x63 */
  u8 unk64;                 /* 0x64 */
  char pad65[0x68 - 0x65];
  u8 *text;                 /* 0x68 string currently shown */
  u32 unk6c;                /* 0x6c */
  u32 unk70;                /* 0x70 */
  int unk74;                /* 0x74 reset to -1 */
  int unk78;                /* 0x78 reset to -1 */
  char pad7c[0x90 - 0x7c];
  u8 unk90;                 /* 0x90 */
  char pad91[3];
  int unk94;                /* 0x94 */
  char text98[0xb0 - 0x98]; /* 0x98 copied string */
  u8 unkb0;                 /* 0xb0 */
} PanelData;

/* Owner object: only the panel pointer and one flag are used. */
typedef struct PanelOwner {
  char pad00[0xfc];
  u8 unkfc;                 /* 0xfc */
  char padfd[0x15c - 0xfd];
  PanelData *panel;         /* 0x15c */
} PanelOwner;

#endif

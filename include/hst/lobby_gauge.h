/* Lobby gauge object (class C_0021d7c4): a parts pane, a progress value and the handle of its sound. */
#ifndef HST_LOBBY_GAUGE_H
#define HST_LOBBY_GAUGE_H

#include "hst/parts_pane.h"

typedef struct LobbyGauge {
  void *vtbl;                   /* 0x00 */
  char pad04[0x16c - 4];
  PartsPane *parts;             /* 0x16c owned parts pane (FUN_0021d02c) */
  int unk170;                   /* 0x170 handle polled by FUN_002af920 */
  char pane174[0x54];           /* 0x174 second pane base (gaugelay_HL.lay) */
  int unk1c8;
  int unk1cc;                   /* 0x1cc page number, one more than the page shown */
  int unk1d0;
  float unk1d4;                 /* 0x1d4 */
  char pad1d8[0xd];
  unsigned char unk1e5;
  char pad1e6[2];
  int unk1e8;                   /* 0x1e8 */
  int unk1ec;                   /* 0x1ec */
  int rangeMin;                 /* 0x1f0 progress value at 0 percent */
  int rangeMax;                 /* 0x1f4 progress value at 100 percent */
  int source;                   /* 0x1f8 */
  int unk1fc;                   /* 0x1fc result of FUN_002af920 */
  int value;                    /* 0x200 copy of source */
  char pad204[4];
  unsigned char unk208;
  char pad209[3];
  int handle;                   /* 0x20c sound handle, -1 when none */
} LobbyGauge;

#endif

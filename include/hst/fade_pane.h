/* Fading panes of the 0x220000 sources: a timer-driven pane whose node holds an offset and an alpha. */
#ifndef HST_FADE_PANE_H
#define HST_FADE_PANE_H

#include "hst/types.h"

#define FADE_IDLE -1       /* timer value while no fade runs */
#define FADE_TIMER_MAX 99  /* the running timer saturates here until the fade ends */

/* Node moved and faded by the panes (the offset pair is shared with the other placed objects). */
typedef struct FadeNode {
  char pad00[0x60];
  float x;           /* 0x60 */
  float y;           /* 0x64 */
  char pad68[4];
  float unk6c;       /* 0x6c set to 1.0 each step by the quad pane */
  char pad70[8];
  float alpha;       /* 0x78 0..1, scaled to the vertex colour's top byte */
} FadeNode;

/* Pane driven by a timer (idle at FADE_IDLE). */
typedef struct FadePane {
  char pad00[0x54];
  u8 unk54;          /* 0x54 set to 1 when the fade has finished, 0 when it is started */
  char pad55[7];
  int timer;         /* 0x5c */
  FadeNode *node;    /* 0x60 */
  char pad64[4];
  u32 *color;        /* 0x68 packed vertex colour (alpha in the top byte) */
  char pad6c[4];
  char unk70[4];     /* 0x70 helper object copied into the colour */
  u8 unk74;          /* 0x74 */
} FadePane;

/* Pane that grows two sprite quads; only the shared flag byte is declared here. */
typedef struct FadeFlagPane {
  char pad00[0x54];
  u8 unk54;          /* 0x54 */
} FadeFlagPane;

#endif

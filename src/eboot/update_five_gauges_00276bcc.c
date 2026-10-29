/* HSTMATCH module=EBOOT.BIN start=0x00276bcc end=0x00277678 symbol=FUN_00276bcc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed struct members, flipped mirrored float comparisons, and inline span difference `(float)(panel->posRight - panel->posLeft)`; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002fe3a8[];
extern char DAT_002fe3b4[];
extern char DAT_002fe3c0[];
extern char DAT_002fe3cc[];
extern char DAT_002fe3d8[];
extern char DAT_002fe3e4[];
extern char DAT_002fe3f0[];
extern char DAT_002fe3f8[];
extern char DAT_002fe400[];
extern char DAT_002fe40c[];
extern char DAT_002fe418[];
extern char DAT_002fe424[];
extern char DAT_002fe430[];
extern char DAT_002fe43c[];
extern char DAT_002fe448[];
extern char DAT_002fe454[];
extern char DAT_002fe460[];
extern char DAT_002fe46c[];

/* Bar widget of a gauge; only the fields the update sets are named. */
typedef struct BarWidget {
  char pad0[4];
  short unk4;                   /* 0x04 left edge of the negative-side bar */
  char pad6[2];
  short unk8;                   /* 0x08 right edge of the positive-side bar */
  char padA[0x24 - 0x0a];
  int unk24;                    /* 0x24 */
  int unk28;                    /* 0x28 */
} BarWidget;

#define GAUGE_COUNT 5
#define GAUGE_STEP 2.0f         /* pixels a gauge moves per update */

typedef struct GaugePanel {
  char pad0[0x48c];
  void *layout;                 /* 0x48c layout the bar widgets are looked up in */
  char pad490[0x99c - 0x490];
  float value[GAUGE_COUNT];     /* 0x99c current bar length of each gauge, negative to the left */
  char pad9b0[0x9b8 - 0x9b0];
  short negOrigin;              /* 0x9b8 */
  char pad9ba[0x9e0 - 0x9ba];
  short posLeft;                /* 0x9e0 */
  char pad9e2[2];
  short posRight;               /* 0x9e4 */
} GaugePanel;

/* Target values of the five gauges at 0x1c. */
typedef struct GaugeTargets {
  char pad0[0x1c];
  float target[GAUGE_COUNT];    /* 0x1c */
} GaugeTargets;

extern void FUN_000ffb3c(BarWidget *, int);
extern BarWidget *FUN_001026b8(void *, char *);

/* Moves the five gauges toward their targets (two pixels per call) and updates the widgets of the side they are on. */
void FUN_00276bcc(GaugePanel *panel, GaugeTargets *param2)
{
  BarWidget *widget;
  BarWidget *bar;
  float diff;
  float target;

  widget = FUN_001026b8(panel->layout,DAT_002fe3a8);
  FUN_000ffb3c(widget,1);
  widget = FUN_001026b8(panel->layout,DAT_002fe3b4);
  FUN_000ffb3c(widget,1);
  widget = FUN_001026b8(panel->layout,DAT_002fe3c0);
  FUN_000ffb3c(widget,1);
  widget = FUN_001026b8(panel->layout,DAT_002fe3cc);
  FUN_000ffb3c(widget,1);
  widget = FUN_001026b8(panel->layout,DAT_002fe3d8);
  FUN_000ffb3c(widget,1);
  widget = FUN_001026b8(panel->layout,DAT_002fe3e4);
  FUN_000ffb3c(widget,1);
  widget = FUN_001026b8(panel->layout,DAT_002fe3f0);
  FUN_000ffb3c(widget,1);
  widget = FUN_001026b8(panel->layout,DAT_002fe3f8);
  FUN_000ffb3c(widget,1);

  widget = FUN_001026b8(panel->layout,DAT_002fe400);
  if (panel->value[0] >= 0.0f) {
    FUN_000ffb3c(widget,1);
  }
  widget = FUN_001026b8(panel->layout,DAT_002fe40c);
  if (panel->value[0] <= 0.0f) {
    FUN_000ffb3c(widget,1);
  }
  target = param2->target[0];
  if (target < 0.0f) {
    diff = target - (panel->value[0] * 2.0f) / (float)(panel->posRight - panel->posLeft);
    if ((int)diff == 0) {
      panel->value[0] = (target * (float)(panel->posRight - panel->posLeft)) / 2.0f;
    }
    else if (diff < 0.0f) {
      panel->value[0] -= GAUGE_STEP;
    }
    else {
      panel->value[0] += GAUGE_STEP;
    }
  }
  else {
    diff = target - (panel->value[0] * 2.0f) / (float)(panel->posRight - panel->posLeft);
    if ((int)diff == 0) {
      panel->value[0] = (target * (float)(panel->posRight - panel->posLeft)) / 2.0f;
    }
    else if (diff > 0.0f) {
      panel->value[0] += GAUGE_STEP;
    }
    else {
      panel->value[0] -= GAUGE_STEP;
    }
  }
  if (panel->value[0] >= 0.0f) {
    bar = FUN_001026b8(panel->layout,DAT_002fe40c);
    bar->unk24 = bar->unk28 + 1;
    bar->unk8 = (short)(int)(panel->value[0] + (float)panel->posLeft);
    FUN_000ffb3c(bar,0);
  }
  else {
    bar = FUN_001026b8(panel->layout,DAT_002fe400);
    bar->unk4 = (short)(int)(panel->value[0] + (float)panel->negOrigin);
    FUN_000ffb3c(bar,0);
  }

  widget = FUN_001026b8(panel->layout,DAT_002fe418);
  if (panel->value[1] >= 0.0f) {
    FUN_000ffb3c(widget,1);
  }
  widget = FUN_001026b8(panel->layout,DAT_002fe424);
  if (panel->value[1] <= 0.0f) {
    FUN_000ffb3c(widget,1);
  }
  target = param2->target[1];
  if (target < 0.0f) {
    diff = target - (panel->value[1] * 2.0f) / (float)(panel->posRight - panel->posLeft);
    if ((int)diff == 0) {
      panel->value[1] = (target * (float)(panel->posRight - panel->posLeft)) / 2.0f;
    }
    else if (diff < 0.0f) {
      panel->value[1] -= GAUGE_STEP;
    }
    else {
      panel->value[1] += GAUGE_STEP;
    }
  }
  else {
    diff = target - (panel->value[1] * 2.0f) / (float)(panel->posRight - panel->posLeft);
    if ((int)diff == 0) {
      panel->value[1] = (target * (float)(panel->posRight - panel->posLeft)) / 2.0f;
    }
    else if (diff > 0.0f) {
      panel->value[1] += GAUGE_STEP;
    }
    else {
      panel->value[1] -= GAUGE_STEP;
    }
  }
  if (panel->value[1] >= 0.0f) {
    bar = FUN_001026b8(panel->layout,DAT_002fe424);
    bar->unk24 = bar->unk28 + 1;
    bar->unk8 = (short)(int)(panel->value[1] + (float)panel->posLeft);
    FUN_000ffb3c(bar,0);
  }
  else {
    bar = FUN_001026b8(panel->layout,DAT_002fe418);
    bar->unk4 = (short)(int)(panel->value[1] + (float)panel->negOrigin);
    FUN_000ffb3c(bar,0);
  }

  widget = FUN_001026b8(panel->layout,DAT_002fe430);
  if (panel->value[2] >= 0.0f) {
    FUN_000ffb3c(widget,1);
  }
  widget = FUN_001026b8(panel->layout,DAT_002fe43c);
  if (panel->value[2] <= 0.0f) {
    FUN_000ffb3c(widget,1);
  }
  target = param2->target[2];
  if (target < 0.0f) {
    diff = target - (panel->value[2] * 2.0f) / (float)(panel->posRight - panel->posLeft);
    if ((int)diff == 0) {
      panel->value[2] = (target * (float)(panel->posRight - panel->posLeft)) / 2.0f;
    }
    else if (diff < 0.0f) {
      panel->value[2] -= GAUGE_STEP;
    }
    else {
      panel->value[2] += GAUGE_STEP;
    }
  }
  else {
    diff = target - (panel->value[2] * 2.0f) / (float)(panel->posRight - panel->posLeft);
    if ((int)diff == 0) {
      panel->value[2] = (target * (float)(panel->posRight - panel->posLeft)) / 2.0f;
    }
    else if (diff > 0.0f) {
      panel->value[2] += GAUGE_STEP;
    }
    else {
      panel->value[2] -= GAUGE_STEP;
    }
  }
  if (panel->value[2] >= 0.0f) {
    bar = FUN_001026b8(panel->layout,DAT_002fe43c);
    bar->unk24 = bar->unk28 + 1;
    bar->unk8 = (short)(int)(panel->value[2] + (float)panel->posLeft);
    FUN_000ffb3c(bar,0);
  }
  else {
    bar = FUN_001026b8(panel->layout,DAT_002fe430);
    bar->unk4 = (short)(int)(panel->value[2] + (float)panel->negOrigin);
    FUN_000ffb3c(bar,0);
  }

  widget = FUN_001026b8(panel->layout,DAT_002fe448);
  if (panel->value[3] >= 0.0f) {
    FUN_000ffb3c(widget,1);
  }
  widget = FUN_001026b8(panel->layout,DAT_002fe454);
  if (panel->value[3] <= 0.0f) {
    FUN_000ffb3c(widget,1);
  }
  target = param2->target[3];
  if (target < 0.0f) {
    diff = target - (panel->value[3] * 2.0f) / (float)(panel->posRight - panel->posLeft);
    if ((int)diff == 0) {
      panel->value[3] = (target * (float)(panel->posRight - panel->posLeft)) / 2.0f;
    }
    else if (diff < 0.0f) {
      panel->value[3] -= GAUGE_STEP;
    }
    else {
      panel->value[3] += GAUGE_STEP;
    }
  }
  else {
    diff = target - (panel->value[3] * 2.0f) / (float)(panel->posRight - panel->posLeft);
    if ((int)diff == 0) {
      panel->value[3] = (target * (float)(panel->posRight - panel->posLeft)) / 2.0f;
    }
    else if (diff > 0.0f) {
      panel->value[3] += GAUGE_STEP;
    }
    else {
      panel->value[3] -= GAUGE_STEP;
    }
  }
  if (panel->value[3] >= 0.0f) {
    bar = FUN_001026b8(panel->layout,DAT_002fe454);
    bar->unk24 = bar->unk28 + 1;
    bar->unk8 = (short)(int)(panel->value[3] + (float)panel->posLeft);
    FUN_000ffb3c(bar,0);
  }
  else {
    bar = FUN_001026b8(panel->layout,DAT_002fe448);
    bar->unk4 = (short)(int)(panel->value[3] + (float)panel->negOrigin);
    FUN_000ffb3c(bar,0);
  }

  widget = FUN_001026b8(panel->layout,DAT_002fe460);
  if (panel->value[4] >= 0.0f) {
    FUN_000ffb3c(widget,1);
  }
  widget = FUN_001026b8(panel->layout,DAT_002fe46c);
  if (panel->value[4] <= 0.0f) {
    FUN_000ffb3c(widget,1);
  }
  target = param2->target[4];
  if (target < 0.0f) {
    diff = target - (panel->value[4] * 2.0f) / (float)(panel->posRight - panel->posLeft);
    if ((int)diff == 0) {
      panel->value[4] = (target * (float)(panel->posRight - panel->posLeft)) / 2.0f;
    }
    else if (diff < 0.0f) {
      panel->value[4] -= GAUGE_STEP;
    }
    else {
      panel->value[4] += GAUGE_STEP;
    }
  }
  else {
    diff = target - (panel->value[4] * 2.0f) / (float)(panel->posRight - panel->posLeft);
    if ((int)diff == 0) {
      panel->value[4] = (target * (float)(panel->posRight - panel->posLeft)) / 2.0f;
    }
    else if (diff > 0.0f) {
      panel->value[4] += GAUGE_STEP;
    }
    else {
      panel->value[4] -= GAUGE_STEP;
    }
  }
  if (panel->value[4] >= 0.0f) {
    bar = FUN_001026b8(panel->layout,DAT_002fe46c);
    bar->unk24 = bar->unk28 + 1;
    bar->unk8 = (short)(int)(panel->value[4] + (float)panel->posLeft);
    FUN_000ffb3c(bar,0);
  }
  else {
    bar = FUN_001026b8(panel->layout,DAT_002fe460);
    bar->unk4 = (short)(int)(panel->value[4] + (float)panel->negOrigin);
    FUN_000ffb3c(bar,0);
  }
}

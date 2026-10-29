/* Timed status overlay object (timer, sound handle, widget and the entity it slides) shared by its methods. */
#ifndef HST_STATUS_OVERLAY_H
#define HST_STATUS_OVERLAY_H

#include "hst/types.h"

/* Entity moved by the overlay; only three float fields are touched. */
typedef struct OverlayEntity {
  char pad00[0x60];
  float unk60;              /* 0x60 */
  float unk64;              /* 0x64 */
  char pad68[0x10];
  float unk78;              /* 0x78 */
} OverlayEntity;

typedef struct StatusOverlay {
  char pad00[0x54];
  u8 done;                  /* 0x54 set when the overlay has finished, cleared when it starts */
  char pad55[7];
  int timer;                /* 0x5c frame counter, negative when not running */
  int sound;                /* 0x60 sound handle, negative when none */
  OverlayEntity *ent;       /* 0x64 */
  void *widget;             /* 0x68 */
  char pad6c[4];
  u8 hold;                  /* 0x70 keeps the timer from advancing past the hold point */
} StatusOverlay;

/* Timer value from which the entity is moved toward the mirrored start values. */
#define OVERLAY_OUT_PHASE 100
/* Frames after the start value at which a held overlay stops counting. */
#define OVERLAY_HOLD_DELAY 0x14

#endif

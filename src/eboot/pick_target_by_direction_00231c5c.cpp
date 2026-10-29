/* HSTMATCH module=EBOOT.BIN start=0x00231c5c end=0x00231f84 symbol=FUN_00231c5c lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idioms: plain else-if chain over the four 2-bit config fields ending in 'else return', float locals declared in retail register order (best score first, directions last), the activity gate materialised as 'int act = 0; if (cnt >= 2) act = 1;', and '>' spelled for the positive-direction tests; exact match verified; names and types await human review. */
#include "hst/challenge_menu.h"

typedef unsigned char u8;

#define FAR_DISTANCE 99999.0f /* start value of the best score and angle */
#define ANGLE_LIMIT 70.0f     /* largest accepted angle off the pressed direction, in degrees */
#define RADIANS_TO_DEGREES 57.29578f
#define NO_POINT -1

/* Direction state of the pad: four 2-bit fields, 0 meaning the direction is pressed. */
struct Pad {
  u8 pad[0x89];
  signed char up : 2;
  signed char right : 2;
  signed char down : 2;
  signed char left : 2;
};

extern Pad *DAT_002cfc8c;
extern char DAT_0034179c[];
extern float DAT_002f3e4c;  /* weight of the angle in the score */

extern "C" {
float sqrtf(float);
float fabsf(float);
float FUN_0000ce3c(float, float);
float FUN_0000b8a8(float);
void FUN_001b1c44(void *, int);
void FUN_00232558(ChallengeMenu *, int);
}

static inline int Active(int c) { int r; if (c > 1) r = 1; else r = 0; return r; }

/* Move the selection to the best point in the pressed direction: nearest, with a penalty for the angle off it. */
extern "C" void FUN_00231c5c(ChallengeMenu *self)
{
  float bestv = FAR_DISTANCE;
  float score;
  float ang;
  float dx;
  float dy;
  float len;
  float diry;
  float dirx;
  int best = NO_POINT;
  diry = dirx = 0.0f;
  if (DAT_002cfc8c->left == 0) {
    dirx = -1.0f;
  } else if (DAT_002cfc8c->right == 0) {
    dirx = 1.0f;
  } else if (DAT_002cfc8c->up == 0) {
    diry = -1.0f;
  } else if (DAT_002cfc8c->down == 0) {
    diry = 1.0f;
  } else {
    return;
  }
  for (int i = 0; i < POINT_COUNT; i++) {
    int act = 0;
    if (self->count[i] >= 2) act = 1;
    if (act != 0) {
      score = FAR_DISTANCE;
      ang = score;
      dx = self->x[i] - self->x[self->selected];
      dy = self->y[i] - self->y[self->selected];
      len = sqrtf(FUN_0000ce3c(dx, 2.0f) + FUN_0000ce3c(dy, 2.0f));
      if ((dirx < 0.0f && dx < 0.0f) || (dirx > 0.0f && dx > 0.0f)) {
        ang = RADIANS_TO_DEGREES * FUN_0000b8a8(fabsf(dy) / fabsf(dx));
        score = len * (1.0f + ang * DAT_002f3e4c);
      } else if ((diry < 0.0f && dy < 0.0f) || (diry > 0.0f && dy > 0.0f)) {
        ang = RADIANS_TO_DEGREES * FUN_0000b8a8(fabsf(dx) / fabsf(dy));
        score = len * (1.0f + ang * DAT_002f3e4c);
      }
      if (score < bestv && ang < ANGLE_LIMIT) {
        bestv = score;
        best = i;
      }
    }
  }
  if (best >= 0) {
    if (self->selected != best) FUN_001b1c44(DAT_0034179c, 1);
    self->selected = best;
    switch (self->mode) {
    case 0:
      break;
    case 1:
      FUN_00232558(self, self->selected);
      break;
    }
  }
}

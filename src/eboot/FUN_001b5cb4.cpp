/* HSTMATCH module=EBOOT.BIN start=0x001b5cb4 end=0x001b5ff0 symbol=FUN_001b5cb4 lang=c++ data=0x002e99b4 */
/* Hand-written reconstruction of FUN_001b5cb4; matching idioms: switch preload id with shared-body case group (1/12/0x22), Vec4 Scale/Sub inlines with callee param order, separate float temp for the final multiply; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e99b4-0x002e99bf) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/scene.h"
#include "hst/ball.h"
#include "hst/court_view.h"

struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));

/* Player object seen through one field only. */
struct Obj {
  char pad[0x4e8];
  int unk4e8;
};

#define NO_SOUND 0x75 /* sound id meaning "this kind makes no sound" */

extern "C" {
extern CourtView *DAT_003402a0;
extern Scene *DAT_003386b0;
extern char DAT_0034179c[];
extern float DAT_002e99a0;
extern float DAT_002e99a4;
extern float DAT_002e99a8;
extern float DAT_002e99ac;
extern float DAT_002e99b0;
float FUN_000224d8(const Vec4 *, const Vec4 *);
float FUN_00022e44(float);
Vec4 *FUN_00022498(Vec4 *, const Vec4 *, float);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_001b1d10(void *, int, int, int);
void FUN_001b210c(void *, int *, float, float);
void FUN_001b28f0(void *, char *);
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
  Vec4 r;
  FUN_00022498(&r, &v, s);
  return r;
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022434(&r, &a, &b);
  return r;
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

/* Play the sound for an event kind. The volume comes from the length of vec's component along axis plus a
   weighted part of the component across it, clamped; the sound only starts when the volume reaches a
   threshold. Returns the sound handle (-1 when none was started). */
extern "C" int FUN_001b5cb4(int unused, int kind, int arg, const Vec4 *vec, const Vec4 *axis)
{
  int sound = NO_SOUND;
  switch (kind) {
  case 1:
  case 12:
  case 0x22:
    sound = 0x54;
    break;
  case 0x2:
    sound = 0x1e;
    break;
  case 0x1a:
    sound = 0x1d;
    break;
  case 0x16:
    sound = 0x1f;
    break;
  case 0x30:
    sound = 0x23;
    break;
  case 0xd:
    sound = 0x20;
    break;
  case 0xe:
    sound = 0x26;
    break;
  case 0x18:
    sound = 0x27;
    break;
  case 0x19:
    sound = 0x25;
    break;
  case 0x15:
    sound = 0x28;
    break;
  case 0x17:
    sound = 0x2a;
    break;
  case 0x20:
    sound = 0x21;
    break;
  case 0x1c:
    sound = 0x2b;
    break;
  case 0x1d:
    sound = 0x2c;
    break;
  case 0x1f:
    sound = 0x2d;
    break;
  case 0x2b:
    sound = 0x22;
    break;
  }
  int handle = -1;
  if (sound != NO_SOUND) {
    Vec4 along;
    Vec4 across;
    along = Scale(*axis, FUN_000224d8(vec, axis));
    across = Sub(*vec, along);
    float lenAcross = FUN_00022e44(FUN_000224d8(&across, &across));
    float lenAlong = FUN_00022e44(FUN_000224d8(&along, &along));
    float weighted = lenAlong + DAT_002e99a4 * lenAcross; float scaled = weighted * DAT_002e99a0;
    float volume = Clamp(scaled, DAT_002e99ac, DAT_002e99b0);
    if (volume >= DAT_002e99a8) {
      handle = FUN_001b1d10(DAT_0034179c, sound, arg, 0);
      FUN_001b210c(DAT_0034179c, &handle, volume, volume);
    }
  }
  if (DAT_003402a0->mode == 9) {
    switch (kind) {
    case 2:
    case 0x1a:
    case 0x16: {
      int idx = DAT_003386b0->ball->unk234;
      if (idx >= 0) {
        Obj *player = DAT_003386b0->players[idx];
        if (player != 0 && player->unk4e8 == 1)
          FUN_001b28f0(DAT_0034179c, "court_beep");
      }
      break;
    }
    }
  }
  return handle;
}

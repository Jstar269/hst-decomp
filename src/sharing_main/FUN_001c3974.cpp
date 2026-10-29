/* HSTMATCH module=hstp_trans_main.prx start=0x001c3974 end=0x001c3cb0 symbol=FUN_001c3974 lang=c++ data=0x00391570 */
/* Hand-written reconstruction (port of src/eboot/FUN_001b5cb4.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00391570-0x0039157b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern CourtView *DAT_003e95e0;
extern Scene *DAT_003e19f0;
extern char DAT_003eaad8[];
extern float DAT_0039155c;
extern float DAT_00391560;
extern float DAT_00391564;
extern float DAT_00391568;
extern float DAT_0039156c;
float FUN_00022500(const Vec4 *, const Vec4 *);
float FUN_00022e6c(float);
Vec4 *FUN_000224c0(Vec4 *, const Vec4 *, float);
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_001bfd3c(void *, int, int, int);
void FUN_001c01a0(void *, int *, float, float);
void FUN_001c0984(void *, char *);
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
  Vec4 r;
  FUN_000224c0(&r, &v, s);
  return r;
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_0002245c(&r, &a, &b);
  return r;
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

/* Play the sound for an event kind. The volume comes from the length of vec's component along axis plus a
   weighted part of the component across it, clamped; the sound only starts when the volume reaches a
   threshold. Returns the sound handle (-1 when none was started). */
extern "C" int FUN_001c3974(int unused, int kind, int arg, const Vec4 *vec, const Vec4 *axis)
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
    along = Scale(*axis, FUN_00022500(vec, axis));
    across = Sub(*vec, along);
    float lenAcross = FUN_00022e6c(FUN_00022500(&across, &across));
    float lenAlong = FUN_00022e6c(FUN_00022500(&along, &along));
    float weighted = lenAlong + DAT_00391560 * lenAcross; float scaled = weighted * DAT_0039155c;
    float volume = Clamp(scaled, DAT_00391568, DAT_0039156c);
    if (volume >= DAT_00391564) {
      handle = FUN_001bfd3c(DAT_003eaad8, sound, arg, 0);
      FUN_001c01a0(DAT_003eaad8, &handle, volume, volume);
    }
  }
  if (DAT_003e95e0->mode == 9) {
    switch (kind) {
    case 2:
    case 0x1a:
    case 0x16: {
      int idx = DAT_003e19f0->ball->unk234;
      if (idx >= 0) {
        Obj *player = DAT_003e19f0->players[idx];
        if (player != 0 && player->unk4e8 == 1)
          FUN_001c0984(DAT_003eaad8, "court_beep");
      }
      break;
    }
    }
  }
  return handle;
}

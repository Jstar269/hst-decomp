/* HSTMATCH module=EBOOT.BIN start=0x001eed9c end=0x001ef0fc symbol=FUN_001eed9c lang=c++ rodata=0x002c8f24 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/vec.h"
#include "hst/state_switch.h"

/* Link object: only the vector at 0x10 is written. */
struct Link {
  char pad[0x10];
  Float4 vec;  /* 0x10 */
};
struct Obj {
  char pad00[0x3c];
  StateSwitch sw;      /* 0x3c state holder, updated first; its state selects the handler */
  char pad54[0x510 - 0x54];
  int unk510;          /* 0x510 */
  unsigned char active; /* 0x514 zero: nothing to do */
  char pad515[0x4f];
  Link *link;          /* 0x564 */
  float unk568;        /* 0x568 */
  char pad_56c[4];
  Float4 base;         /* 0x570 */
  float yOffset;       /* 0x580 added to base.y; eases up by 0.1 per step and is capped at 0 */
  char pad584[0x34];
  int sound;           /* 0x5b8 sound handle, -1 when none */
  unsigned char unk5bc; /* 0x5bc */
};

extern "C" {
extern char DAT_0034179c[];
void FUN_001fb9dc(void *);
void FUN_001ef2ec(Obj *);
void FUN_001ef424(Obj *);
void FUN_001ef824(Obj *);
void FUN_001f02fc(Obj *);
void FUN_001efcd8(Obj *);
void FUN_001f00c8(Obj *);
void FUN_001f0560(Obj *);
void FUN_001f0850(Obj *);
void FUN_001f10ec(Obj *);
void FUN_001f14a4(Obj *);
void FUN_001f15d0(Obj *);
void FUN_001f1968(Obj *);
void FUN_001f20d8(Obj *);
void FUN_001f2264(Obj *);
void FUN_001f25a4(Obj *);
void FUN_001f1e24(Obj *);
void FUN_001f1e8c(Obj *);
void FUN_001f1ea8(Obj *);
void FUN_001f4900(Obj *);
int FUN_001f92ec(Obj *);
int FUN_001f9354(Obj *);
void FUN_00219210(Link *);
int FUN_001b1f7c(char *, int);
int FUN_001e5a84(int);
int FUN_001e7198(int);
void FUN_001b413c(float, float, char *);

/* Runs the active state's handler, then the per-frame updates: eases the link vector, and tracks whether any of the
   sounds is playing (calling FUN_001b413c with two float arguments when that changes). */
void FUN_001eed9c(Obj *self)
{
  bool playing;
  int handle;
  if (self->active == 0) {
    return;
  }
  FUN_001fb9dc(&self->sw);
  switch (self->sw.state) {
  case 0: FUN_001ef2ec(self); break;
  case 1: FUN_001ef424(self); break;
  case 2:
  case 3: break;
  case 4: FUN_001ef824(self); break;
  case 5: FUN_001f02fc(self); break;
  case 6: FUN_001efcd8(self); break;
  case 7: FUN_001f00c8(self); break;
  case 8: FUN_001f0560(self); break;
  case 9: FUN_001f0850(self); break;
  case 10: FUN_001f10ec(self); break;
  case 11: FUN_001f14a4(self); break;
  case 12: FUN_001f15d0(self); break;
  case 13: FUN_001f1968(self); break;
  case 14: FUN_001f20d8(self); break;
  case 15: FUN_001f2264(self); break;
  case 16: FUN_001f25a4(self); break;
  case 17: FUN_001f1e24(self); break;
  case 18: FUN_001f1e8c(self); break;
  case 19: FUN_001f1ea8(self); break;
  default: break;
  }
  FUN_001f4900(self);
  if (FUN_001f92ec(self) != 0) {
    if (self->link != 0) {
      FUN_00219210(self->link);
      if (FUN_001f9354(self) != 0) {
        self->yOffset += 0.1f;
        float cur = self->yOffset;
        if (cur > 0.0f) {
          self->yOffset = 0.0f;
        }
        float w = self->base.w;
        float z = self->base.z;
        float y = self->base.y;
        float offset = self->yOffset;
        float sum = y + offset;
        Link *l = self->link;
        l->vec.x = self->base.x;
        l->vec.y = sum;
        l->vec.z = z;
        l->vec.w = w;

      }
    }
  }
  handle = self->sound;
  playing = false;
  if (handle != -1) {
    unsigned char c1 = FUN_001b1f7c(DAT_0034179c, self->sound);
    playing = c1 != 0;
    if (FUN_001b1f7c(DAT_0034179c, self->sound) == 0) {
      self->sound = -1;
    }
  }
  if (self->unk510 != 0) {
    if (FUN_001e5a84(self->unk510) != -1) {
      unsigned char c2 = FUN_001b1f7c(DAT_0034179c, FUN_001e5a84(self->unk510));
      playing = (playing | c2) != 0;
    }
  }
  if (self->unk510 != 0 && FUN_001e7198(self->unk510) != -1) {
    unsigned char c3 = FUN_001b1f7c(DAT_0034179c, FUN_001e7198(self->unk510));
    playing = (playing | c3) != 0;
  }
  if (playing && self->unk5bc == 0) {
    FUN_001b413c(0.2734375f, 0.1f, DAT_0034179c);
    self->unk5bc = 1;
  } else if (!playing && self->unk5bc != 0) {
    FUN_001b413c(1.0f, 0.3f, DAT_0034179c);
    self->unk5bc = 0;
  }
}
}
// Matching idioms (lane om2 2026-10-22): (a) the tested field loaded into an argument register
// (`lw a0,1380(s1); beqz a0`) is the dropped FIRST ARGUMENT of the call right after the test -
// `FUN_00219210()` is `FUN_00219210(self->link)`; (b) the float that is COALESCED with the
// destination of an in-place `add.s` follows the position of the SUM in the source, not the
// declaration order of the other floats: `float sum = y + offset;` written BEFORE the other
// float read gives retail's `add.s $f0,$f2,$f0` (the sum shares $f0 with its second operand)
// and the other value gets $f1; the identical sum written inline in the later store gives
// `add.s $f1,$f2,$f1` and swaps $f0/$f1 with that other value (5 words off).

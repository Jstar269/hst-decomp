/* HSTMATCH module=EBOOT.BIN start=0x000fabc0 end=0x000fadf0 symbol=FUN_000fabc0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* When the byte at +0x155 is set and the game state word (+0x3c of DAT_003386b0) is neither 9 nor 2 (or there is no game), calls 0x1ed06c with the pointer at +0x94; otherwise, if bit 0x800 of DAT_002d5ab0 is set, calls virtual slot 3 (vtable +20) on a run of member objects (some null-checked, two gated on a float at +0x78 of the object at +0x9c / +0xbc), then 0xf293c, 0xf2bf4, slot 2 of the object at +0x88, 0xf6c48 twice, and in state 6 with DAT_00338b44+0xa0 below 2 calls 0x1eab70. Matching idioms: the else branch holds the long body (retail lays the 0x1ed06c arm out first), the state test is a one-case switch. */
#include "hst/hud_scene.h"

struct HudWidget {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
};
struct HudTop : HudWidget {
  char pad[0x1b4];
  HudWidget *child;
};
struct HudPanel : HudWidget {};
struct GameA { char pad[0x3c]; int mode; };
struct GameB { char pad[0xa0]; unsigned unk_a0; };
extern int DAT_002d5ab0;
extern GameA *DAT_003386b0;
extern GameB *DAT_00338b44;
extern "C" void FUN_000f293c(void *);
extern "C" void FUN_000f2bf4(void *);
extern "C" void FUN_000f6c48(void *);
extern "C" void FUN_001eab70(void *);
extern "C" void FUN_001ed06c(void *);

/* Per-frame sweep: run virtual slot 3 on each of the scene's widgets (or, when the byte flag is set and the
   game is not in mode 9 or 2, hand the pointer to the alternate helper instead). */
extern "C" void FUN_000fabc0(HudScene *self)
{
  if (self->unk155 != 0 && (DAT_003386b0 == 0 || (DAT_003386b0->mode != 9 && DAT_003386b0->mode != 2))) {
    FUN_001ed06c(self->unk94);
  } else {
    if ((DAT_002d5ab0 & 0x800) != 0) {
      self->unk58->s3();
      if (self->unk5c != 0) self->unk5c->s3();
      if (self->unk60 != 0) self->unk60->s3();
      if (self->unk64 != 0) self->unk64->s3();
      self->unk68->s3();
      if (self->gauges[0]->value > 0.0f) self->top->s3();
      if (self->gauges[8]->value > 0.0f) self->top->child->s3();
      self->unk84->s3();
      self->unk70->s3();
      self->unk6c->s3();
      self->unk74->s3();
      self->unk78->s3();
      FUN_000f293c(self->unk7c);
      FUN_000f2bf4(self->unk80);
      self->unk88->s2();
      FUN_000f6c48(self->unk8c);
      FUN_000f6c48(self->unk90);
      switch (DAT_003386b0->mode) {
      case 6:
        if (DAT_00338b44->unk_a0 < 2) {
          FUN_001eab70(self->unk98);
        }
        break;
      }
    }
  }
}

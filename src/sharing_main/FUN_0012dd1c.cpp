/* HSTMATCH module=hstp_trans_main.prx start=0x0012dd1c end=0x0012e590 symbol=FUN_0012dd1c lang=c++ */
/* Hand-written reconstruction (port of src/eboot/FUN_00122b48.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/actor_state.h"

extern "C" {
extern u32 DAT_003da704;
extern u8 * DAT_003e19f0;
extern StateRow DAT_003e48c4[];
extern u8 * DAT_003e95c4;
extern void FUN_0012f448(...);
extern void FUN_0012f5f0(...);
extern void FUN_0012f7e4(...);
extern int FUN_001303e0(...);
extern u32 FUN_001303ec(...);
extern float FUN_001304a4(...);
extern int FUN_001304d0(...);
extern void FUN_00130984(...);
extern void FUN_00130af0(...);
extern void FUN_00131004(...);
extern void FUN_00131270(...);
extern float FUN_0013c0c8(...);
extern void FUN_0013c714(...);
extern u8 * FUN_0013d6dc(...);
extern void FUN_0017682c(...);
extern void FUN_002252e0(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

/* Per-frame update: advances the elapsed time and switches state when a state row's limit is passed, then refreshes the current child object. */
extern "C" void FUN_0012dd1c(ActorState *self)
{
  if (!self->active) {
    return;
  }
  float now;
  float clock;
  self->unk68 += 1.0f;
  if (self->unk6c > 0.0f) {
    if (self->unk64 > 0.0f) {
      clock = self->unk64;
      self->unk64 += 1.0f;
    }
    else if (self->unk60 > 0.0f) {
      clock = self->unk60;
    }
    else {
      int base = *(int *)(*(int *)(DAT_003e19f0 + 0x9c) + 0x58);
      clock = (float)base + FUN_0013c0c8(DAT_003e95c4);
    }
    if (clock < (float)FUN_001303e0(self, 3)) {
      self->unk6c -= 1.0f;
      if (self->unk6c != 1.0f && self->unk6c <= 0.0f) {
        int nextState;
        self->unk84 = 0.0f;
        if (DAT_003e48c4[self->stateIdx].unk48 != 0) {
          FUN_0013d6dc((int)DAT_003e48c4[self->stateIdx].unk48, &nextState);
          nextState = FUN_001304d0(self, nextState);
        }
        else {
          FUN_0012f448(self);
          FUN_0013d6dc((int)DAT_003e48c4[self->stateIdx].unk44, &nextState);
          nextState = FUN_001304d0(self, nextState);
        }
        self->stateIdx = -1;
        self->unk90 = (int)((float)self->unk90 + self->unk70);
        FUN_00130af0(self, nextState);
      }
    }
  }
  clock = self->unk84;
  if (clock >= 0.0f) {
    if (self->unk64 > 0.0f) {
      now = self->unk64;
      switch (*(unsigned char *)(DAT_003e19f0 + 0x4c)) {
      case 0:
        self->unk64 += 1.0f;
        break;
      }
    }
    else if (self->unk60 > 0.0f) {
      now = self->unk60;
    }
    else {
      int base = *(int *)(*(int *)(DAT_003e19f0 + 0x9c) + 0x58);
      now = (float)base + FUN_0013c0c8(DAT_003e95c4);
    }
    self->unk84 = now - (float)self->unk90;
    if (self->unk60 <= 0.0f) {
      if (self->unk94 == 0 && self->stateIdx == 7) {
        self->unk84 = 0.0f;
      }
      else if (self->unk94 != 0 || DAT_003e48c4[self->stateIdx].unk46 != 60) {
        float limit = self->unk88;
        if (self->unk84 == limit - 1.0f) {
          if (*(int *)(DAT_003e95c4 + 0x8c) == 3) {
            FUN_0013c714(DAT_003e95c4);
            return;
          }
        }
        else if (clock < limit && self->unk84 >= limit) {
          signed char mode = DAT_003e48c4[self->stateIdx].unk4e;
          if (mode == 5) {
            int nextState;
            self->unk84 = 0.0f;
            FUN_0013d6dc((int)self->slotC->unk44, &nextState);
            nextState = FUN_001304d0(self, nextState);
            self->stateIdx = -1;
            float f = self->unk88 - FUN_0013c0c8(DAT_003e95c4);
            self->unk90 = (int)((float)self->unk90 + f);
            FUN_00130af0(self, nextState);
          }
          else if (mode == 4 || mode == 1 || mode == 2) {
            int nextState;
            FUN_0013d6dc((int)self->slotC->unk44, &nextState);
            nextState = FUN_001304d0(self, nextState);
            if (DAT_003e48c4[nextState].unk4e != 0 || DAT_003e48c4[self->stateIdx].unk50 == 7) {
              self->unk84 = 0.0f;
              self->stateIdx = -1;
              float f = self->unk88 - FUN_0013c0c8(DAT_003e95c4);
              self->unk90 = (int)((float)self->unk90 + f);
              FUN_00130af0(self, nextState);
            }
          }
          else if (mode == 3 && DAT_003e48c4[self->stateIdx].unk48 != 999) {
            int nextState;
            if (self->unk64 > 0.0f) {
              self->unk84 = 0.0f;
              FUN_0013d6dc((int)DAT_003e48c4[self->stateIdx].unk44, &nextState);
              nextState = FUN_001304d0(self, nextState);
              for (int i = 0; nextState == self->stateIdx && i < 100; i++) {
                FUN_0013d6dc((int)DAT_003e48c4[self->stateIdx].unk44, &nextState);
                nextState = FUN_001304d0(self, nextState);
              }
              self->stateIdx = -1;
              FUN_00130af0(self, nextState);
              self->unk64 = (float)self->unk90;
            }
            else if (now >= FUN_001304a4(self) - 60.0f) {
            }
            else {
              self->unk84 = 0.0f;
              FUN_0012f448(self);
              FUN_0013d6dc((int)DAT_003e48c4[self->stateIdx].unk44, &nextState);
              nextState = FUN_001304d0(self, nextState);
              self->stateIdx = -1;
              float f = self->unk88 - FUN_0013c0c8(DAT_003e95c4);
              self->unk90 = (int)((float)self->unk90 + f);
              FUN_00130af0(self, nextState);
            }
          }
        }
      }
      if (self->unk94 != 0 && DAT_003e48c4[self->stateIdx].unk48 == 60 &&
          now != FUN_001304a4(self) && now > FUN_001304a4(self)) {
        int nextState;
        FUN_0013d6dc(60, &nextState);
        int chosen = FUN_001304d0(self, nextState);
        self->unk90 = (int)(1.0f + FUN_001304a4(self));
        FUN_00130af0(self, chosen);
      }
    }
  }
  if (self->unk84 >= 0.0f) {
    signed char c = self->slotB->unk50;
    if (c != 4 && c != 6) {
      FUN_0012f5f0(self);
    }
    FUN_0012f7e4(self);
  }
  else {
    signed char c = self->slotA->unk50;
    if (c != 4 && c != 6) {
      FUN_0012f5f0(self);
    }
    FUN_00131004(FUN_001303ec(self), 0);
    FUN_00130984(self, FUN_001303ec(self));
    FUN_002252e0(self->unk54, FUN_001303ec(self));
    FUN_0017682c(FUN_001303ec(self), self->slotA->unk54 > 0);
    int child = FUN_001303ec(self);
    ActorChild *slotOwner = (ActorChild *)FUN_001303ec(self);
    FUN_00131270(child, *slotOwner->slot);
    VC_0 *obj = (VC_0 *)FUN_001303ec(self);
    obj->m(DAT_003da704);
  }
}

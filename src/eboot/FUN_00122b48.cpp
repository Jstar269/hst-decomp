/* HSTMATCH module=EBOOT.BIN start=0x00122b48 end=0x001233bc symbol=FUN_00122b48 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/actor_state.h"

extern "C" {
extern u32 DAT_003313c4;
extern u8 * DAT_003386b0;
extern StateRow DAT_0033b584[];
extern u8 * DAT_00340284;
extern void FUN_00124274(...);
extern void FUN_0012441c(...);
extern void FUN_00124610(...);
extern int FUN_0012520c(...);
extern u32 FUN_00125218(...);
extern float FUN_001252d0(...);
extern int FUN_001252fc(...);
extern void FUN_00125750(...);
extern void FUN_001258bc(...);
extern void FUN_00125dd0(...);
extern void FUN_0012603c(...);
extern float FUN_00130b10(...);
extern void FUN_0013115c(...);
extern u8 * FUN_00132124(...);
extern void FUN_0016a668(...);
extern void FUN_002162dc(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

/* Per-frame update: advances the elapsed time and switches state when a state row's limit is passed, then refreshes the current child object. */
extern "C" void FUN_00122b48(ActorState *self)
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
      int base = *(int *)(*(int *)(DAT_003386b0 + 0x9c) + 0x58);
      clock = (float)base + FUN_00130b10(DAT_00340284);
    }
    if (clock < (float)FUN_0012520c(self, 3)) {
      self->unk6c -= 1.0f;
      if (self->unk6c != 1.0f && self->unk6c <= 0.0f) {
        int nextState;
        self->unk84 = 0.0f;
        if (DAT_0033b584[self->stateIdx].unk48 != 0) {
          FUN_00132124((int)DAT_0033b584[self->stateIdx].unk48, &nextState);
          nextState = FUN_001252fc(self, nextState);
        }
        else {
          FUN_00124274(self);
          FUN_00132124((int)DAT_0033b584[self->stateIdx].unk44, &nextState);
          nextState = FUN_001252fc(self, nextState);
        }
        self->stateIdx = -1;
        self->unk90 = (int)((float)self->unk90 + self->unk70);
        FUN_001258bc(self, nextState);
      }
    }
  }
  clock = self->unk84;
  if (clock >= 0.0f) {
    if (self->unk64 > 0.0f) {
      now = self->unk64;
      switch (*(unsigned char *)(DAT_003386b0 + 0x4c)) {
      case 0:
        self->unk64 += 1.0f;
        break;
      }
    }
    else if (self->unk60 > 0.0f) {
      now = self->unk60;
    }
    else {
      int base = *(int *)(*(int *)(DAT_003386b0 + 0x9c) + 0x58);
      now = (float)base + FUN_00130b10(DAT_00340284);
    }
    self->unk84 = now - (float)self->unk90;
    if (self->unk60 <= 0.0f) {
      if (self->unk94 == 0 && self->stateIdx == 7) {
        self->unk84 = 0.0f;
      }
      else if (self->unk94 != 0 || DAT_0033b584[self->stateIdx].unk46 != 60) {
        float limit = self->unk88;
        if (self->unk84 == limit - 1.0f) {
          if (*(int *)(DAT_00340284 + 0x8c) == 3) {
            FUN_0013115c(DAT_00340284);
            return;
          }
        }
        else if (clock < limit && self->unk84 >= limit) {
          signed char mode = DAT_0033b584[self->stateIdx].unk4e;
          if (mode == 5) {
            int nextState;
            self->unk84 = 0.0f;
            FUN_00132124((int)self->slotC->unk44, &nextState);
            nextState = FUN_001252fc(self, nextState);
            self->stateIdx = -1;
            float f = self->unk88 - FUN_00130b10(DAT_00340284);
            self->unk90 = (int)((float)self->unk90 + f);
            FUN_001258bc(self, nextState);
          }
          else if (mode == 4 || mode == 1 || mode == 2) {
            int nextState;
            FUN_00132124((int)self->slotC->unk44, &nextState);
            nextState = FUN_001252fc(self, nextState);
            if (DAT_0033b584[nextState].unk4e != 0 || DAT_0033b584[self->stateIdx].unk50 == 7) {
              self->unk84 = 0.0f;
              self->stateIdx = -1;
              float f = self->unk88 - FUN_00130b10(DAT_00340284);
              self->unk90 = (int)((float)self->unk90 + f);
              FUN_001258bc(self, nextState);
            }
          }
          else if (mode == 3 && DAT_0033b584[self->stateIdx].unk48 != 999) {
            int nextState;
            if (self->unk64 > 0.0f) {
              self->unk84 = 0.0f;
              FUN_00132124((int)DAT_0033b584[self->stateIdx].unk44, &nextState);
              nextState = FUN_001252fc(self, nextState);
              for (int i = 0; nextState == self->stateIdx && i < 100; i++) {
                FUN_00132124((int)DAT_0033b584[self->stateIdx].unk44, &nextState);
                nextState = FUN_001252fc(self, nextState);
              }
              self->stateIdx = -1;
              FUN_001258bc(self, nextState);
              self->unk64 = (float)self->unk90;
            }
            else if (now >= FUN_001252d0(self) - 60.0f) {
            }
            else {
              self->unk84 = 0.0f;
              FUN_00124274(self);
              FUN_00132124((int)DAT_0033b584[self->stateIdx].unk44, &nextState);
              nextState = FUN_001252fc(self, nextState);
              self->stateIdx = -1;
              float f = self->unk88 - FUN_00130b10(DAT_00340284);
              self->unk90 = (int)((float)self->unk90 + f);
              FUN_001258bc(self, nextState);
            }
          }
        }
      }
      if (self->unk94 != 0 && DAT_0033b584[self->stateIdx].unk48 == 60 &&
          now != FUN_001252d0(self) && now > FUN_001252d0(self)) {
        int nextState;
        FUN_00132124(60, &nextState);
        int chosen = FUN_001252fc(self, nextState);
        self->unk90 = (int)(1.0f + FUN_001252d0(self));
        FUN_001258bc(self, chosen);
      }
    }
  }
  if (self->unk84 >= 0.0f) {
    signed char c = self->slotB->unk50;
    if (c != 4 && c != 6) {
      FUN_0012441c(self);
    }
    FUN_00124610(self);
  }
  else {
    signed char c = self->slotA->unk50;
    if (c != 4 && c != 6) {
      FUN_0012441c(self);
    }
    FUN_00125dd0(FUN_00125218(self), 0);
    FUN_00125750(self, FUN_00125218(self));
    FUN_002162dc(self->unk54, FUN_00125218(self));
    FUN_0016a668(FUN_00125218(self), self->slotA->unk54 > 0);
    int child = FUN_00125218(self);
    ActorChild *slotOwner = (ActorChild *)FUN_00125218(self);
    FUN_0012603c(child, *slotOwner->slot);
    VC_0 *obj = (VC_0 *)FUN_00125218(self);
    obj->m(DAT_003313c4);
  }
}

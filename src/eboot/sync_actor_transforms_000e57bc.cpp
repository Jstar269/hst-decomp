/* HSTMATCH module=EBOOT.BIN start=0x000e57bc end=0x000e5948 symbol=FUN_000e57bc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7/v20) corrected by hand: typed the copied transform fields and count member; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

struct FlowState { char pad0[4]; int phase; };               /* phase 1 = running */
struct Globals { char pad0[0x88]; FlowState *flow; };

extern "C" {
extern Globals * DAT_003386b0;
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

/* Object that mirrors a 12-float transform block from its owner. */
struct XformChild { char pad0[0x70]; float xform[12]; /* 0x70 */ };

struct XformOwner {
  char pad0[0x40];
  XformChild *childA;  /* 0x40 */
  XformChild *childB;  /* 0x44 */
  char pad48[8];
  float xform[12];     /* 0x50 */
  int age;             /* 0x80 */
};

extern "C" void FUN_000e57bc(XformOwner *self)
{
  XformChild *child;
  XformChild *dead;
  int age;

  child = self->childA;
  if (child != 0) {
    child->xform[0] = self->xform[0];
    child->xform[1] = self->xform[1];
    child->xform[2] = self->xform[2];
    child->xform[3] = self->xform[3];
    child->xform[4] = self->xform[4];
    child->xform[5] = self->xform[5];
    child->xform[6] = self->xform[6];
    child->xform[7] = self->xform[7];
    child->xform[8] = self->xform[8];
    child->xform[9] = self->xform[9];
    child->xform[10] = self->xform[10];
    child->xform[11] = self->xform[11];
  }
  child = self->childB;
  if (child != 0) {
    child->xform[0] = self->xform[0];
    child->xform[1] = self->xform[1];
    child->xform[2] = self->xform[2];
    child->xform[3] = self->xform[3];
    child->xform[4] = self->xform[4];
    child->xform[5] = self->xform[5];
    child->xform[6] = self->xform[6];
    child->xform[7] = self->xform[7];
    child->xform[8] = self->xform[8];
    child->xform[9] = self->xform[9];
    child->xform[10] = self->xform[10];
    child->xform[11] = self->xform[11];
  }
  age = self->age;
  if (0 < age) {
    age = age + 1;
    self->age = age;
    if (age < 3) {
    }
    else {
      /* after a few ticks release both children */
      dead = self->childA;
      if (dead != 0) {
        delete ((VC_0 *)(dead));
        self->childA = 0;
      }
      dead = self->childB;
      if (dead != 0) {
        delete ((VC_1 *)(dead));
        self->childB = 0;
      }
    }
  }
  if (DAT_003386b0->flow->phase == 1) {
    self->age = self->age + 1;
  }
}

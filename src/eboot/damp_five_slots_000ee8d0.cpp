/* HSTMATCH module=EBOOT.BIN start=0x000ee8d0 end=0x000eea50 symbol=FUN_000ee8d0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"
#include "hst/scene.h"

extern "C" float fabsf(float);
extern "C" float FUN_0000bb44(float);
extern "C" void FUN_000ffb3c(PaneItem *, int);
extern "C" void FUN_00103128(ReplayPane *);
extern "C" void FUN_00103480(ReplayPane *);
extern "C" void FUN_0010f5d4(int, int);
extern Scene *DAT_003386b0;

/* Virtual view of a PaneLayer: slot 1 shows or hides it. */
struct LayerV
{
  virtual void v0();
  virtual void Show(int on);
};

#define SCENE_FPS 30.0f

/* Per-frame update of the replay pane: the layer offsets ease toward zero (20% per frame, snapping inside 0.1);
   while the scene counts down, the remaining seconds are shown and the digit items are hidden at zero. */
extern "C" void FUN_000ee8d0(ReplayPane *pane)
{
  if (pane->base.shown == 0)
  {
    PaneLayer *l0 = pane->layer[0];
    float cur0 = l0->offset;
    PaneLayer *l1 = pane->layer[1];
    PaneLayer *l2 = pane->layer[2];
    PaneLayer *l3 = pane->layer[3];
    PaneLayer *l4 = pane->layer[4];
    float cur1 = l1->offset;
    float next0 = 0.0f;
    float delta = next0 - cur0;
    next0 = (fabsf(delta) >= 0.1f) ? (cur0 + delta * 0.2f) : next0;
    float next1 = 0.0f;
    delta = next1 - cur1;
    next1 = (fabsf(delta) >= 0.1f) ? (cur1 + delta * 0.2f) : next1;
    l0->offset = next0;
    l1->offset = next1;
    l2->offset = next0;
    l3->offset = next1;
    l4->offset = next0;
    if (pane->base.shown == 0)
    {
      FUN_00103480(pane);
    }
    if (DAT_003386b0->unk68 != 0)
    {
      int seconds = (int)FUN_0000bb44((float)DAT_003386b0->timer / SCENE_FPS);
      ((LayerV *)pane->layer[4])->Show(0);
      FUN_0010f5d4(pane->unkA0, seconds);
      if (seconds < 1)
      {
        FUN_000ffb3c(pane->item[0], 1);
        FUN_000ffb3c(pane->item[1], 1);
        FUN_000ffb3c(pane->item[4], 1);
        FUN_000ffb3c(pane->item[5], 1);
      }
    }
    FUN_00103128(pane);
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x0008a634 end=0x0008a72c symbol=FUN_0008a634 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/play_flow.h"

extern void FUN_002aef68(void *ctx);
extern int FUN_001fb4fc(void);
extern void FUN_0015d244(int value, int mode);
extern void FUN_00234158(int *timer, int frames);
extern int DAT_0034a678;

/* Two-step handler: step 0 resets and advances; step 1 polls the context and picks the follow-up from the helper's flags. */
void FUN_0008a634(PlayFlowObj *self)
{
  switch (self->step) {
  case 0:
    self->unk48 = 0;
    self->step = self->step + 1;
    break;
  case 1:
    FUN_002aef68(self->ctx);
    if (self->sub->unk515 != 0) {
      if (FUN_001fb4fc() != 0) {
        if (self->sub->unk5a2 != 0) {
          FUN_0015d244(DAT_0034a678, 1);
          FUN_00234158(&DAT_0034a678, 75);
        }
        else {
          FUN_00234158(&DAT_0034a678, 30);
        }
      }
      else {
        FUN_0015d244(DAT_0034a678, 0);
        FUN_00234158(&DAT_0034a678, 75);
      }
    }
    else if (self->sub->unk516 != 0) {
      self->nextState = 10;
    }
    break;
  }
}

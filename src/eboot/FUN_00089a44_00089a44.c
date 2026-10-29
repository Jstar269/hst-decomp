/* HSTMATCH module=EBOOT.BIN start=0x00089a44 end=0x00089abc symbol=FUN_00089a44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: fixed the callback prototype, float constants, and integer return type; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void *DAT_00331b88;
extern void *DAT_00338c20;
extern void FUN_00063d08(float param_1,float param_2,void *param_3,int param_4);
extern void FUN_0008ad40();
extern u32 FUN_0008add8();
extern int FUN_000fb504(void *param_1);

typedef struct StateObj {
  char pad00[0x40];
  u32 state;      /* 0x40 */
} StateObj;

#define STATE_AFTER_UPDATE 4

void FUN_00089a44(StateObj *self)
{
  int ok;
  
  ok = FUN_000fb504(DAT_00338c20);
  if (ok != 0) {
    FUN_0008ad40(self);
    ok = FUN_0008add8(self);
    if (ok != 0) {
      self->state = STATE_AFTER_UPDATE;
    FUN_00063d08(65264.0f,-1.0f,DAT_00331b88,0xf);
    }
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x00117154 end=0x00117300 symbol=FUN_00117154 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The case order is inverted relative to the retail chain: MWCC lays switch bodies out in reverse source
   order, so the cases are listed ascending here to emit retail's descending compare chain. */
#include "hst/wheel_state.h"

extern int DAT_003386b0;

extern void FUN_0001f20c(WheelState *, int, int);
extern void FUN_00117300(WheelState *, int);
extern void FUN_00117c74(void);

/* Handles an event code by updating the wheel state; always returns 0. */
int FUN_00117154(WheelState *self, int event)
{
  switch (event) {
  case 0:
    FUN_00117300(self, 0);
    break;
  case 8:
    FUN_00117300(self, 1);
    break;
  case 0x14:
    if (*(int *)(DAT_003386b0 + 0x3c) != 7)
      self->unk50 = self->unk58 + 1;
    break;
  case 0xe:
    FUN_00117c74();
    FUN_00117300(self, 3);
    break;
  case 0xa:
    FUN_00117300(self, 2);
    break;
  case 0xb:
    FUN_00117300(self, 4);
    break;
  case 0xc:
    FUN_00117300(self, 4);
    break;
  case 0x12:
    self->unk4c = 0;
    self->unk50 = 0;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unk5c = -1;
    self->unk60 = -1;
    self->unk64 = -1;
    self->unk6c = -1;
    self->unk40 = 0;
    FUN_0001f20c(self, 0, 0);
    FUN_0001f20c(self, 1, 0);
    FUN_0001f20c(self, 2, 0);
    break;
  case 0x18:
    self->unk3c = 4;
    FUN_0001f20c(self, 0, 1);
    FUN_0001f20c(self, 1, 1);
    FUN_0001f20c(self, 2, 1);
    break;
  }
  return 0;
}

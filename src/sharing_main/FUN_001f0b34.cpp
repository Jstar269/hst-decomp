/* HSTMATCH module=hstp_trans_main.prx start=0x001f0b34 end=0x001f0be4 symbol=FUN_001f0b34 lang=c++ */
/* Clone of src/eboot/FUN_001e28e0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_screen.h"

extern "C" {
extern void FUN_00105470(...);
}
struct ResultSwitch { virtual void d0(); virtual void m(int); };

/* Set both switches (0, 1) and give six widgets flags 1,1,0,0,1,1. */
extern "C" void FUN_001f0b34(ResultScreen *self)
{
  self->ui->unk58->m(0);
  self->ui->unk5c->m(1);
  FUN_00105470(self->ui->unk64,1);
  FUN_00105470(self->ui->unk70,1);
  FUN_00105470(self->ui->unk68,0);
  FUN_00105470(self->ui->unk74,0);
  FUN_00105470(self->ui->unk6c,1);
  FUN_00105470(self->ui->unk78,1);
}

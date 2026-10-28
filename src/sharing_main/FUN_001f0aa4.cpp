/* HSTMATCH module=hstp_trans_main.prx start=0x001f0aa4 end=0x001f0b34 symbol=FUN_001f0aa4 lang=c++ */
/* Clone of src/eboot/FUN_001e2850.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_screen.h"

extern "C" {
extern void FUN_00105470(...);
}
struct ResultSwitch { virtual void d0(); virtual void m(int); };

/* Set the switches (1, 0) and give four widgets flag 0. */
extern "C" void FUN_001f0aa4(ResultScreen *self)
{
  self->ui->unk58->m(1);
  self->ui->unk5c->m(0);
  FUN_00105470(self->ui->unk7c,0);
  FUN_00105470(self->ui->unk84,0);
  FUN_00105470(self->ui->unk80,0);
  FUN_00105470(self->ui->unk88,0);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x001f0be4 end=0x001f0c34 symbol=FUN_001f0be4 lang=c++ */
/* Clone of src/eboot/FUN_001e2990.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_screen.h"

extern "C" {
extern void FUN_000ffb3c(...);
}
struct ResultSwitch { virtual void d0(); virtual void m(int); };

/* Set both switches to 1. */
extern "C" void FUN_001f0be4(ResultScreen *self)
{
  self->ui->unk58->m(1);
  self->ui->unk5c->m(1);
}

/* HSTMATCH module=EBOOT.BIN start=0x001e28e0 end=0x001e2990 symbol=FUN_001e28e0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_screen.h"

extern "C" {
extern void FUN_000ffb3c(...);
}
struct ResultSwitch { virtual void d0(); virtual void m(int); };

/* Set both switches (0, 1) and give six widgets flags 1,1,0,0,1,1. */
extern "C" void FUN_001e28e0(ResultScreen *self)
{
  self->ui->unk58->m(0);
  self->ui->unk5c->m(1);
  FUN_000ffb3c(self->ui->unk64,1);
  FUN_000ffb3c(self->ui->unk70,1);
  FUN_000ffb3c(self->ui->unk68,0);
  FUN_000ffb3c(self->ui->unk74,0);
  FUN_000ffb3c(self->ui->unk6c,1);
  FUN_000ffb3c(self->ui->unk78,1);
}

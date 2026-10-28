/* HSTMATCH module=EBOOT.BIN start=0x001e2850 end=0x001e28e0 symbol=FUN_001e2850 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_screen.h"

extern "C" {
extern void FUN_000ffb3c(...);
}
struct ResultSwitch { virtual void d0(); virtual void m(int); };

/* Set the switches (1, 0) and give four widgets flag 0. */
extern "C" void FUN_001e2850(ResultScreen *self)
{
  self->ui->unk58->m(1);
  self->ui->unk5c->m(0);
  FUN_000ffb3c(self->ui->unk7c,0);
  FUN_000ffb3c(self->ui->unk84,0);
  FUN_000ffb3c(self->ui->unk80,0);
  FUN_000ffb3c(self->ui->unk88,0);
}

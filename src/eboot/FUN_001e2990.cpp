/* HSTMATCH module=EBOOT.BIN start=0x001e2990 end=0x001e29e0 symbol=FUN_001e2990 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_screen.h"

extern "C" {
extern void FUN_000ffb3c(...);
}
struct ResultSwitch { virtual void d0(); virtual void m(int); };

/* Set both switches to 1. */
extern "C" void FUN_001e2990(ResultScreen *self)
{
  self->ui->unk58->m(1);
  self->ui->unk5c->m(1);
}

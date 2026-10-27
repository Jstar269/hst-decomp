/* HSTMATCH module=EBOOT.BIN start=0x00215630 end=0x002156a0 symbol=FUN_00215630 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Returns the requested mode, or 0 when mode 1 or 2 is not available: FUN_00096d1c / FUN_00096d64 are the
   "neither query 1 nor 3" / "neither query 2 nor 3" tests (src/eboot/neither_query_*.c). They are bool
   functions called with the object although they ignore it (`move a0,s1` before the second call); comparing the
   bool result with false gives retail's `andi v0,0xff` (a bare `!F()` drops it). The callees compile EXACT with
   `bool F(void *self)` in C++ too (verified for 0x00096d1c and both Sharing twins, lane try/lane-work/protos/), which would unify the prototypes.
   The mode-2 test sits in the THEN arm: retail falls through into it and keeps `mode = 0` for a failed mode-1 test
   in a `beqzl` delay slot (the else-if spelling puts the reset inline and branches to the mode-2 test instead).
   Twin of hstp_trans_main.prx 0x002244bc. */
extern "C" {
bool FUN_00096d1c(void *self);
bool FUN_00096d64(void *self);

int FUN_00215630(void *self, int mode)
{
  if (mode != 1 || FUN_00096d1c(self) != false) {
    if (mode == 2 && FUN_00096d64(self) == false)
      mode = 0;
  } else {
    mode = 0;
  }
  return mode;
}
}

/* HSTMATCH module=hstp_trans_main.prx start=0x002244bc end=0x0022452c symbol=FUN_002244bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Returns the requested mode, or 0 when mode 1 or 2 is not available: FUN_00098e54 / FUN_00098e9c are the
   "neither query 1 nor 3" / "neither query 2 nor 3" tests (src/sharing_main/neither_query_*.c). They are bool
   functions called with the object although they ignore it (`move a0,s1` before the second call); comparing the
   bool result with false gives retail's `andi v0,0xff` (a bare `!F()` drops it). The callees compile EXACT with
   `bool F(void *self)` in C++ too (verified for both, lane try/lane-work/protos/), which would unify the prototypes.
   The mode-2 test sits in the THEN arm: retail falls through into it and keeps `mode = 0` for a failed mode-1 test
   in a `beqzl` delay slot (the else-if spelling puts the reset inline and branches to the mode-2 test instead).
   Twin of EBOOT 0x00215630. */
extern "C" {
bool FUN_00098e54(void *self);
bool FUN_00098e9c(void *self);

int FUN_002244bc(void *self, int mode)
{
  if (mode != 1 || FUN_00098e54(self) != false) {
    if (mode == 2 && FUN_00098e9c(self) == false)
      mode = 0;
  } else {
    mode = 0;
  }
  return mode;
}
}

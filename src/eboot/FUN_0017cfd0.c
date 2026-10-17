/* HSTMATCH module=EBOOT.BIN start=0x0017cfd0 end=0x0017d018 symbol=FUN_0017cfd0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used a typed state layout and arranged the low-value update path to preserve retail branch and store order; exact match verified; names and types await human review. */
typedef struct { char pad[0x50]; int current; int deferred; } State;
void FUN_0017cfd0(State *self, int value) {
  if (value != self->current) {
    if (value >= 2) {
      self->deferred = value;
    } else {
      self->deferred = value;
      if (value != 0) {
        self->current = value;
        self->deferred = 0;
      }
    }
  } else if (self->deferred != 0) {
    self->deferred = 0;
  }
}

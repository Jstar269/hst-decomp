/* HSTMATCH module=hstp_trans_main.prx start=0x001896c4 end=0x0018970c symbol=FUN_001896c4 lang=c99 */
/* Clone of src/eboot/FUN_0017cfd0.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used a typed state layout and arranged the low-value update path to preserve retail branch and store order; exact match verified; names and types await human review. */
typedef struct { char pad[0x50]; int current; int deferred; } State;
void FUN_001896c4(State *self, int value) {
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

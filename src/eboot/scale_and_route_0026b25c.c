/* HSTMATCH module=EBOOT.BIN start=0x0026b25c end=0x0026b2f0 symbol=FUN_0026b25c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used fabsf and matched the float branch and mode arguments; readability pass; exact match verified; names and types await human review. */

/* Object whose offset value is eased. */
typedef struct EaseTarget {
  char pad0[0x60];
  float offset; /* 0x60 */
} EaseTarget;

/* Owner with a pointer to the slot that holds the target, and a flag word at 0x5c. */
typedef struct EaseOwner {
  char pad0[4];
  EaseTarget **target_slot; /* 0x04 */
  char pad8[0x5c - 8];
  int flag;                 /* 0x5c */
} EaseOwner;

extern void FUN_00103480();
extern void FUN_00269ab0();
extern float fabsf(float);

/* Halves the target's offset each call; once it is within 16 units, switches the layout mode (1, or 3 when the flag is set). */
void FUN_0026b25c(EaseOwner *self)
{
  float offset;
  
  offset = (*self->target_slot)->offset;
  offset = offset + -offset * 0.5f;
  (*self->target_slot)->offset = offset;
  FUN_00103480();
  if (fabsf(offset) < 16.0f) {
    if (self->flag == 0)
      FUN_00269ab0(self,1);
    else
      FUN_00269ab0(self,3);
  }
}

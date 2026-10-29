/* HSTMATCH module=EBOOT.BIN start=0x000f6730 end=0x000f6774 symbol=FUN_000f6730 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00103540(float, int);

typedef struct ValueHolder {
  int target;     /* 0x0 object told the new value (may be 0) */
  char pad4[0xc];
  int value;      /* 0x10 */
} ValueHolder;

/* Store value; if there is a target, pass it the value as a float first. */
void FUN_000f6730(ValueHolder *self,int value)
{
  if (self->target != 0) {
    FUN_00103540((float)((float)value),(int)(self->target));
  }
  self->value = value;
}

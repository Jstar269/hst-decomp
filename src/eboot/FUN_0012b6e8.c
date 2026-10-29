/* HSTMATCH module=EBOOT.BIN start=0x0012b6e8 end=0x0012b724 symbol=FUN_0012b6e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
extern float DAT_002da9d0; /* lower bound */

typedef struct FloatHolder {
  char pad00[0x400];
  float value;              /* 0x400 */
} FloatHolder;

/* Stores `value`, raised to the lower bound when below it. */
void FUN_0012b6e8(float value,FloatHolder *self)
{
  float *chosen;
  float valueCopy;
  
  valueCopy = value;
  if (value < DAT_002da9d0) {
    chosen = &DAT_002da9d0;
  }
  else {
    chosen = &valueCopy;
  }
  self->value = *chosen;
  return;
}

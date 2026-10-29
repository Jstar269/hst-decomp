/* HSTMATCH module=EBOOT.BIN start=0x002a43cc end=0x002a43d4 symbol=FUN_002a43cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
typedef struct FloatHolder {
  char pad00[0x20];
  float value;            /* 0x20 */
} FloatHolder;

float FUN_002a43cc(FloatHolder *self)
{
  return self->value;
}

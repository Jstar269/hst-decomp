/* HSTMATCH module=EBOOT.BIN start=0x002af0dc end=0x002af0e4 symbol=FUN_002af0dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
typedef struct FloatAt68 {
  char pad00[0x68];
  float value;          /* 0x68 */
} FloatAt68;

/* Getter for the float at +0x68. */
float FUN_002af0dc(FloatAt68 *self)
{
  return self->value;
}

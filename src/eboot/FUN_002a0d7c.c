/* HSTMATCH module=EBOOT.BIN start=0x002a0d7c end=0x002a0d88 symbol=FUN_002a0d7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
typedef struct FloatPairHolder {
  char pad[0x13c];
  float unk13c;  /* 0x13c */
  float unk140;  /* 0x140 */
} FloatPairHolder;

void FUN_002a0d7c(float a,float b,FloatPairHolder *self)
{
  self->unk13c = a;
  self->unk140 = b;
}

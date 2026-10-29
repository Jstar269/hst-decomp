/* HSTMATCH module=EBOOT.BIN start=0x002821a0 end=0x00282214 symbol=FUN_002821a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag fm2 near miss) corrected by hand: the default case passes the switch value as a second (variadic) argument to the log stub FUN_002803d8, which Ghidra dropped; readability pass; exact match verified; names and types await human review. */
extern char DAT_002fe988;
extern void FUN_002803d8(const char *, ...);

typedef struct ModeObj {
  char pad00[0x5c];
  int unk5c;   /* 0x5c zero selects the fixed result 2 */
  char pad60[0x80 - 0x60];
  int mode;    /* 0x80 selector 0..3 */
} ModeObj;

/* Map the object's mode to a result value (2, 3 or 4); an unknown mode is logged and gives 4. */
int FUN_002821a0(ModeObj *self)
{
  if (self->unk5c == 0) return 2;
  switch (self->mode) {
  case 3:
  case 2:
    return 2;
  case 1:
    return 3;
  case 0:
    return 4;
  default:
    FUN_002803d8(&DAT_002fe988, self->mode);
    return 4;
  }
}

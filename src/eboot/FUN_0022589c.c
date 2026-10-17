/* HSTMATCH module=EBOOT.BIN start=0x0022589c end=0x002258f8 symbol=FUN_0022589c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: merged allocation and constructor store pattern for sub-object; exact match verified; names and types await human review. */

extern void *DAT_00309608;
extern void *DAT_0034a2e0;
extern void *FUN_00000bcc(unsigned int);
extern void *FUN_0001f06c(void *);
extern void *FUN_00225090(void *);

void *FUN_0022589c(void **param_1)
{
  FUN_0001f06c(param_1);
  param_1[0] = &DAT_00309608;
  param_1[0xf] = 0;
  DAT_0034a2e0 = param_1;
  void *p = FUN_00000bcc(0x3c);
  if (p != 0) p = FUN_00225090(p);
  param_1[0xf] = p;
  return param_1;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00234e10 end=0x00234e6c symbol=FUN_00234e10 lang=c99 */
/* Clone of src/eboot/FUN_0022589c.c (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: merged allocation and constructor store pattern for sub-object; exact match verified; names and types await human review. */

extern void *DAT_003b28d4;
extern void *DAT_003f3610;
extern void *FUN_00000bcc(unsigned int);
extern void *FUN_0001ec44(void *);
extern void *FUN_00234604(void *);

void *FUN_00234e10(void **param_1)
{
  FUN_0001ec44(param_1);
  param_1[0] = &DAT_003b28d4;
  param_1[0xf] = 0;
  DAT_003f3610 = param_1;
  void *p = FUN_00000bcc(0x3c);
  if (p != 0) p = FUN_00234604(p);
  param_1[0xf] = p;
  return param_1;
}

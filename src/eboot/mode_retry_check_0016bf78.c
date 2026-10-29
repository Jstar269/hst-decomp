/* HSTMATCH module=EBOOT.BIN start=0x0016bf78 end=0x0016c030 symbol=FUN_0016bf78 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: the two switch(v) bodies share one trailing return 1 (return 1 inside each arm gives a trampoline). */
extern int DAT_0034a678;
extern int FUN_002346e0(int *);
extern int FUN_0023471c(int *);

int FUN_0016bf78(int param_1)
{
  int v;
  if (DAT_0034a678 == 0x24) return 0;
  if (DAT_0034a678 == 0x55) return param_1;
  if (param_1 != 0) {
    v = FUN_0023471c(&DAT_0034a678);
    switch (v) { case 0x29: case 0x30: return 0; }
  } else {
    v = FUN_002346e0(&DAT_0034a678);
    switch (v) { case 0x29: case 0x30: return 0; }
  }
  return 1;
}

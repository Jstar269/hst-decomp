/* HSTMATCH module=EBOOT.BIN start=0x002ada80 end=0x002adb98 symbol=FUN_002ada80 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034b5a0;
extern char DAT_00302c70[];
extern char DAT_00302c78[];
extern char DAT_00302c80[];
extern char DAT_00302c88[];
extern char DAT_00302c90[];
extern int FUN_00065740(int *, char *, int);
int FUN_002ada80(int value)
{
  int t1 = FUN_00065740(&DAT_0034b5a0, DAT_00302c70, 1);
  int t2 = FUN_00065740(&DAT_0034b5a0, DAT_00302c78, 1);
  int t3 = FUN_00065740(&DAT_0034b5a0, DAT_00302c80, 1);
  int t4 = FUN_00065740(&DAT_0034b5a0, DAT_00302c88, 1);
  int t5 = FUN_00065740(&DAT_0034b5a0, DAT_00302c90, 1);
  if (value >= t1) return 5;
  if (value >= t2) return 4;
  if (value >= t3) return 3;
  if (value >= t4) return 2;
  if (value < t5) goto below;
  return 1;
below:
  return 0;
}
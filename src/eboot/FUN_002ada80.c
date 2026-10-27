/* HSTMATCH module=EBOOT.BIN start=0x002ada80 end=0x002adb98 symbol=FUN_002ada80 lang=c99 data=0x00302c70 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x00302c70-0x00302c98) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern int DAT_0034b5a0;
extern int FUN_00065740(int *, char *, int);
int FUN_002ada80(int value)
{
  int t1 = FUN_00065740(&DAT_0034b5a0, "Kansyo", 1);
  int t2 = FUN_00065740(&DAT_0034b5a0, "Syori", 1);
  int t3 = FUN_00065740(&DAT_0034b5a0, "Sinsyo", 1);
  int t4 = FUN_00065740(&DAT_0034b5a0, "Sekihai", 1);
  int t5 = FUN_00065740(&DAT_0034b5a0, "Haiboku", 1);
  if (value >= t1) return 5;
  if (value >= t2) return 4;
  if (value >= t3) return 3;
  if (value >= t4) return 2;
  if (value < t5) goto below;
  return 1;
below:
  return 0;
}
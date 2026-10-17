/* HSTMATCH module=hstp_trans_main.prx start=0x002bd2a8 end=0x002bd3c0 symbol=FUN_002bd2a8 lang=c99 */
/* Clone of src/eboot/FUN_002ada80.c (hstclone.py tag u6cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003f48e0;
extern char DAT_003abd88[];
extern char DAT_003abd90[];
extern char DAT_003abd98[];
extern char DAT_003abda0[];
extern char DAT_003abda8[];
extern int FUN_00066a84(int *, char *, int);
int FUN_002bd2a8(int value)
{
  int t1 = FUN_00066a84(&DAT_003f48e0, DAT_003abd88, 1);
  int t2 = FUN_00066a84(&DAT_003f48e0, DAT_003abd90, 1);
  int t3 = FUN_00066a84(&DAT_003f48e0, DAT_003abd98, 1);
  int t4 = FUN_00066a84(&DAT_003f48e0, DAT_003abda0, 1);
  int t5 = FUN_00066a84(&DAT_003f48e0, DAT_003abda8, 1);
  if (value >= t1) return 5;
  if (value >= t2) return 4;
  if (value >= t3) return 3;
  if (value >= t4) return 2;
  if (value < t5) goto below;
  return 1;
below:
  return 0;
}
/* HSTMATCH module=EBOOT.BIN start=0x002ada80 end=0x002adb98 symbol=FUN_002ada80 lang=c99 data=0x00302c70 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x00302c70-0x00302c98) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern int DAT_0034b5a0;
extern int FUN_00065740(int *, char *, int);

/* Rank 0 to 5 for a score: compare against the five thresholds read from the table by name, highest first. */
int FUN_002ada80(int score)
{
  int kansyo = FUN_00065740(&DAT_0034b5a0, "Kansyo", 1);
  int syori = FUN_00065740(&DAT_0034b5a0, "Syori", 1);
  int sinsyo = FUN_00065740(&DAT_0034b5a0, "Sinsyo", 1);
  int sekihai = FUN_00065740(&DAT_0034b5a0, "Sekihai", 1);
  int haiboku = FUN_00065740(&DAT_0034b5a0, "Haiboku", 1);
  if (score >= kansyo) return 5;
  if (score >= syori) return 4;
  if (score >= sinsyo) return 3;
  if (score >= sekihai) return 2;
  if (score < haiboku) goto below;
  return 1;
below:
  return 0;
}
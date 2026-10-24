/* HSTMATCH module=EBOOT.BIN start=0x000b2f0c end=0x000b2fc0 symbol=FUN_000b2f0c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the else arm assigns the default explicitly (w = iVar2) instead of leaving it unassigned, which gives retail's bnez/b-join layout; started from the lane fm3 near miss. */
extern unsigned char *DAT_00338b08;

extern int DAT_0034a7e8;
extern char DAT_0034180e[];
extern int FUN_000d8c24(unsigned char *, int, int);

int FUN_000b2f0c(int param_1)
{
  short *p = *(short **)(param_1 + 0x154);
  int iVar2 = *p;
  int rec = FUN_000d8c24(DAT_00338b08, 0, iVar2);
  int sel = ((int)(*(signed char *)(rec + 0x62) << 0x1c)) >> 0x1c;
  int *tbl = (int *)(DAT_0034a7e8 + (sel != 0) * 0xc);
  int w;
  if (sel == 0) {
    w = iVar2;
  } else {
    w = *(short *)(DAT_0034180e + *(int *)(param_1 + 0x148) * 0x120);
  }
  return *tbl + w * 0x68;
}

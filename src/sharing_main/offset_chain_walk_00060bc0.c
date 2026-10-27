/* HSTMATCH module=hstp_trans_main.prx start=0x00060bc0 end=0x00060cac symbol=FUN_00060bc0 lang=c99 data=0x00376e78 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed Table view (+5 flag, +6 count), the compiler-unrolled walk written as a plain counted loop, early return 0 after the range-error call; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00376e78-0x00376ea5) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_00012ad0();

typedef struct {
  char pad0[5];
  unsigned char wide;
  unsigned short count;
} Table;

int *FUN_00060bc0(Table *t, int idx)
{
  int *p;
  int i;

  if (idx >= t->count) {
    FUN_00012ad0("Tim2GetPictureHeader: Illegal image no.(%d)\n");
    return 0;
  }
  if (t->wide == 0) {
    p = (int *)((char *)t + 0x10);
  } else {
    p = (int *)((char *)t + 0x80);
  }
  for (i = 0; i < idx; i++) {
    p = (int *)((char *)p + *p);
  }
  return p;
}

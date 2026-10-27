/* HSTMATCH module=EBOOT.BIN start=0x0005fdd0 end=0x0005febc symbol=FUN_0005fdd0 lang=c99 data=0x002d1028 */
/* Clone of src/sharing_main/offset_chain_walk_00060bc0.c (hstclone.py tag s10170158a1r1e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d1028-0x002d1055) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed Table view (+5 flag, +6 count), the compiler-unrolled walk written as a plain counted loop, early return 0 after the range-error call; exact match verified; names and types await human review. */
extern void FUN_00012ad0();

typedef struct {
  char pad0[5];
  unsigned char wide;
  unsigned short count;
} Table;

int *FUN_0005fdd0(Table *t, int idx)
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

/* HSTMATCH module=EBOOT.BIN start=0x001afe6c end=0x001afef4 symbol=FUN_001afe6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed object with a volatile state field read into a local before the table entry (retail loads it first), loop index declared before the walking pointer (s1/s0 order); exact match verified; names and types await human review. */
typedef struct Obj { char pad0[0x7cc]; volatile int cur; } Obj;
extern int DAT_002e5970[];
extern int DAT_002e5978[3];
extern int DAT_002e5984[];
extern void FUN_001b04d0(Obj *, int);
extern void FUN_001b08a0(Obj *, int *, int);

void FUN_001afe6c(Obj *param_1)
{
  unsigned i;
  int *p;
  FUN_001b08a0(param_1, DAT_002e5984, 2);
  FUN_001b08a0(param_1, DAT_002e5970, 2);
  for (i = 0, p = DAT_002e5978; i < 3; i++) {
    int c = param_1->cur;
    int v = *p;
    if (c != v) {
      FUN_001b04d0(param_1, v);
    }
    p++;
  }
}

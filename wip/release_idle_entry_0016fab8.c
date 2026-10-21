/* HSTMATCH module=EBOOT.BIN start=0x0016fab8 end=0x0016fbf4 symbol=FUN_0016fab8 lang=c99 */
typedef struct Entry {
  int id;
  int pad4;
  unsigned char f8;
  unsigned char f9;
  unsigned char f10;
  unsigned char f11;
  unsigned char f12;
} Entry;
typedef struct Mgr {
  char pad[0x520];
  Entry **items;
  volatile unsigned count;
} Mgr;
extern int FUN_0016b164(void);
extern void FUN_0016b6c8(int);

static inline Entry *FindById(Mgr *m, int id)
{
  unsigned i;
  for (i = 0; i < m->count; i++) {
    if (m->items[i]->id == id) {
      return m->items[i];
    }
  }
  return 0;
}

void FUN_0016fab8(Mgr *m, int target)
{
  Entry *found = FindById(m, FUN_0016b164());
  if (found == 0) {
    return;
  }
  if (target != FUN_0016b164()) {
    if (found->f11 == 0 && found->f12 == 0) {
      return;
    }
  }
  {
    unsigned i;
    for (i = 0; i < m->count; i++) {
      Entry *e = m->items[i];
      if (e->id != target) {
        if (e->f8 == 0 && e->f9 == 0 && e->f10 == 0 && e->f11 == 0 && e->f12 == 0) {
          FUN_0016b6c8(e->id);
          return;
        }
      }
    }
  }
}
// lane sn6: 64 of 79 words differ, but registers (this s1, target s0, found s2) and the overall shape match; this is the inline-FindById form with `volatile unsigned count`
// (gives retail's per-iteration `lw v1,1316(s1)` bound reload and the sltu/bnezl back edge). Open problems:
//  1. retail's index loops are NOT strength reduced (`sll a0,a2,2; addu v1,a1,a0` per pass, items base hoisted into a1); `#pragma opt_strength_reduction off` gives that form
//     but then `found` is loaded once before the compare (`lw s0,0(v1); lw v1,0(s0)`) and this/target/found take s2/s1/s0 (73 words); retail compares through a temp chain
//     (`lw v1,0(v1); lw v1,0(v1)`) and RELOADS items (`lw v1,1312(s1); addu v1,v1,a0; lw s2,0(v1)`) in the match path only.
//  2. the same `m->items[i]` appears twice in retail without CSE; tried: inline At() getter on either/both sides, do/while + goto, while + break, post-loop `found = i < count ? items[i] : 0`.
// Source shape (from Ghidra): find entry whose id == FUN_0016b164(), return if none; if target != FUN_0016b164() require found->f11 or f12 nonzero; then release the first other
// entry (id != target) whose five flag bytes +8..+12 are all zero via FUN_0016b6c8(id).
// near miss from lane sn6 (unreviewed)

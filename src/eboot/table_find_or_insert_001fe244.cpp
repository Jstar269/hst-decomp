/* HSTMATCH module=EBOOT.BIN start=0x001fe244 end=0x001fe584 symbol=FUN_001fe244 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Find-or-insert in a table of 10 32-byte entries (id, four byte fields, six int values at +8): looks for an entry with
   the same id and tag byte (b7); a hit at index 0 waits on FUN_00049094 (or sets DAT_0034a140 when `noMove`), sets the
   out flag and refreshes id/b4/b5 and every value that is not the 0x7fffffff "unset" marker; otherwise the first free
   entry (id == 0x7fffffff) is filled. A new or refreshed entry with index != 0 is moved to the front (unless `noMove`)
   by shifting the entries above it down; returns the index (0 after a move) or 0x7fffffff when nothing was found or
   free. Caller: FUN_0017d59c. Matching idioms: the saved entry is a named `Entry tmp` filled member by member (a whole
   `Entry tmp = *p` copies all 32 bytes through the stack and costs a 16-byte smaller frame), `result` is declared before
   `found` and `e` before `i`, and `result` itself is the loop counter of the shift loop. Names provisional. */
struct Vals {
  int v[6];
};
struct Entry {
  int id;
  unsigned char b4;
  unsigned char b5;
  unsigned char b6;
  unsigned char b7;
  Vals vals;
};
extern "C" {
extern unsigned char DAT_0034a140;
int FUN_00049094(int);
void FUN_002b7958(int);
}

extern "C" int FUN_001fe244(Entry *tbl, unsigned char *outFlag, int id, unsigned char b4, const int *vals,
                            int noMove, unsigned char tag)
{
  int result = 0x7fffffff;
  bool found = false;
  Entry *e;
  int i;
  for (i = 0, e = tbl; i < 10; i++, e++) {
    if (e->id == id && e->b7 == tag) {
      if (i == 0) {
        if (noMove == 0) {
          int n = 0;
          while (!FUN_00049094(1)) {
            FUN_002b7958(100000);
            n++;
            if (n > 100) break;
          }
        } else {
          DAT_0034a140 = 1;
        }
        if (outFlag != 0) *outFlag = 1;
      }
      e->id = id;
      if (e->b4 == 0) e->b4 = b4;
      e->b5 = 0;
      for (int j = 0; j < 6; j++) {
        if (vals[j] != 0x7fffffff) e->vals.v[j] = vals[j];
      }
      found = true;
      result = i;
      break;
    }
  }
  if (!found) {
    int j;
    for (j = 0, e = tbl; j < 10; j++, e++) {
      if (e->id == 0x7fffffff) {
        e->id = id;
        if (e->b4 == 0) e->b4 = b4;
        found = true;
        result = j;
        e->vals.v[0] = vals[0];
        e->vals.v[1] = vals[1];
        e->vals.v[2] = vals[2];
        e->vals.v[3] = vals[3];
        e->vals.v[4] = vals[4];
        e->vals.v[5] = vals[5];
        e->b7 = tag;
        e->b5 = 0;
        break;
      }
    }
  }
  if (found && noMove == 0 && result != 0) {
    Entry *p = tbl + result;
    Entry tmp;
    tmp.id = p->id;
    tmp.b4 = p->b4;
    tmp.b5 = p->b5;
    tmp.b6 = p->b6;
    tmp.b7 = p->b7;
    tmp.vals = p->vals;
    for (; result > 0; result--) {
      *p = p[-1];
      if (result == 1) p->b5 = 0;
      p--;
    }
    tbl->id = tmp.id;
    tbl->b4 = tmp.b4;
    tbl->b5 = tmp.b5;
    tbl->b6 = tmp.b6;
    tbl->b7 = tmp.b7;
    tbl->vals = tmp.vals;
    result = 0;
  }
  return result;
}

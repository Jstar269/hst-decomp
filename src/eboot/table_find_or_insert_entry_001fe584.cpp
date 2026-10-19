/* HSTMATCH module=EBOOT.BIN start=0x001fe584 end=0x001fe7b8 symbol=table_find_or_insert_entry_001fe584 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Find an existing entry by id or claim the first free slot, update fields, and shift the entry to index 0 unless noMove. */

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

extern "C" int table_find_or_insert_entry_001fe584(Entry *tbl, int id, unsigned char b4, const int *vals, int noMove)
{
  int result = 0x7fffffff;
  bool found = false;
  Entry *e;
  int i;
  for (i = 0, e = tbl; i < 10; i++, e++) {
    if (e->id == id) {
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

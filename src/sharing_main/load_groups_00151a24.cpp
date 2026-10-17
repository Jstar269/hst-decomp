/* HSTMATCH module=hstp_trans_main.prx start=0x00151a24 end=0x00151c50 symbol=FUN_00151a24 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Reloads the groups table (a vector of 12-byte pointer vectors at +0x7bc) from a file: free and clear every
   old group (the table is re-read after each delete), shrink the outer vector, copy the file name into +0x7c8,
   load the file (0x4cd8c) and, for each stored group, build 32-byte items (id, three floats, 1.0f) into a
   temporary vector that is appended to the table and cleared again; finally free the file block and run the
   temporary's destructor. Matching idioms: the inner-vector pointer is refreshed (`v = &groups.data[g]`)
   after the delete and at the bottom of each pass, `v->shrink(v->size, Alloc())` after the loop, and the fast
   push is `++size; data[size - 1] = item`. Names provisional. */
struct Tag {};
struct Alloc {};
struct Item {
  float x, y, z, w;
  int id;
  char pad[12];
};
struct Inner {
  Item **data;
  unsigned size;
  unsigned cap;
  void shrink(int n, Alloc) { size -= n; }
};
struct Outer {
  Inner *data;
  unsigned size;
  unsigned cap;
};
struct Tmp {
  Item **data;
  unsigned size;
  unsigned cap;
  Tmp() : data(0), size(0), cap(0) {}
  void shrink(int n, Alloc) { size -= n; }
};
struct Rec {
  int id;
  float x, y, z;
};
struct Block {
  int count;
};
struct Self {
  char pad[0x7bc];
  Outer groups;
  char path[1];
};
extern "C" {
void *FUN_00000bcc(unsigned n);
void FUN_000104e0(void *p);
char *FUN_000149a8(char *dst, const char *src);
void *FUN_0004cd8c(const char *name, int *size, int a, int b);
void FUN_00147fbc(Tmp *t, int flag);
void FUN_00151c50(Outer *o, Tmp *t);
void FUN_00152534(Outer *o, int n, Tag);
void FUN_00152ed0(Tmp *t, Item **item, Tag);
}

extern "C" void FUN_00151a24(Self *self, const char *name)
{
  for (unsigned g = 0; g < self->groups.size; g++) {
    Inner *v = &self->groups.data[g];
    for (unsigned i = 0; i < v->size; i++) {
      if (v->data[i] != 0) {
        delete v->data[i];
        v = &self->groups.data[g];
        v->data[i] = 0;
      }
      v = &self->groups.data[g];
    }
    v->shrink(v->size, Alloc());
  }
  FUN_00152534(&self->groups, self->groups.size, Tag());
  int size = 0;
  FUN_000149a8(self->path, name);
  int *blk = (int *)FUN_0004cd8c(name, &size, 16, 1);
  if (blk != 0) {
    int ngroups = blk[0];
    Rec *rec = (Rec *)(blk + 1);
    Tmp tmp;
    for (int g = 0; g < ngroups; g++) {
      int count = *(int *)rec;
      rec = (Rec *)((int *)rec + 1);
      for (int i = 0; i < count; i++) {
        Item *item = (Item *)FUN_00000bcc(32);
        item->id = rec->id;
        item->x = rec->x;
        item->y = rec->y;
        item->z = rec->z;
        item->w = 1.0f;
        rec++;
        if (tmp.size < tmp.cap) {
          ++tmp.size;
          tmp.data[tmp.size - 1] = item;
        } else {
          FUN_00152ed0(&tmp, &item, Tag());
        }
      }
      FUN_00151c50(&self->groups, &tmp);
      int n = tmp.size;
      tmp.shrink(n, Alloc());
    }
    FUN_000104e0(blk);
    FUN_00147fbc(&tmp, 0);
  }
}

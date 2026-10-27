/* HSTMATCH module=EBOOT.BIN start=0x001c69d8 end=0x001c6aa0 symbol=FUN_001c69d8 lang=c++ data=0x002ea6a8 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the inline push_back takes an unused empty Tag by value (the never-written slot above the address-taken parameter, retail's 20(sp) home) and stores through back() = at(size - 1) (unsigned index parameter keeps the unfolded `addiu -1; sll`); names and types await human review. Data: its string literals (1 strings, 0x002ea6a8-0x002ea6ce) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Registers a gimmick under the index pair (x, y): FUN_001c67e8 adds it to the vector at +0x40 when not yet present,
   FUN_001c6f70 reports an existing gimmick with the same index (logged through the empty variadic stub FUN_001c5018
   with "warning! same gimmick index (%d, %d)\n"), the pair is stored in the gimmick and the gimmick appended to the
   vector at +0x70 (FUN_001ce554 grows it). Names provisional. */
struct Alloc {};
struct Tag {};
struct Gimmick {
  char pad[0x30];
  int x;
  int y;
};
struct GVec;
extern "C" void FUN_001ce554(GVec *v, Gimmick *const *x, Alloc a);
struct GVec {
  Gimmick **data;
  unsigned size;
  unsigned capacity;
  Gimmick *&at(unsigned i) { return data[i]; }
  Gimmick *&back() { return at(size - 1); }
  void push_back(Gimmick *const &x, Tag)
  {
    if (size < capacity) {
      ++size;
      back() = x;
    } else {
      FUN_001ce554(this, &x, Alloc());
    }
  }
};
struct Mgr {
  char pad[0x70];
  GVec gimmicks;
};
extern "C" {
void FUN_001c67e8(Mgr *self, Gimmick *g);
int FUN_001c6f70(Mgr *self, int x, int y);
void FUN_001c5018(...);
}

extern "C" void FUN_001c69d8(Mgr *self, int x, int y, Gimmick *g)
{
  FUN_001c67e8(self, g);
  if (FUN_001c6f70(self, x, y))
    FUN_001c5018("warning! same gimmick index (%d, %d)\n", x, y);
  g->x = x;
  g->y = y;
  self->gimmicks.push_back(g, Tag());
}

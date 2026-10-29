/* HSTMATCH module=hstp_trans_main.prx start=0x001d4f60 end=0x001d5014 symbol=FUN_001d4f60 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Registers a gizmo under an index: FUN_001d4be0 (add the gizmo to the list at +0x40 if absent), the warning
   "warning! same gizmo index (%d)\n" when FUN_001d54e8 already finds that index in the list at +0x88, then
   gizmo->index (+0x30) = index, +0x34 = 0 and push_back into the +0x88 pointer vector {data, size, cap}.
   The gizmo parameter lives in a stack slot because push_back binds it to a const reference; FUN_001dcc30 is the
   out-of-line grow path, taking the element by address and an empty tag by value (`move v0,zero; seb a2,v0`).
   Fast path `size++; back() = x;` through `at(unsigned)` gives retail's `addiu -1; sll` (`data[size - 1]` folds
   the -1 into the store offset). Matching idiom: the inline push_back takes an unused empty Tag by value
   (default argument, no code): it reserves the never-written slot above the gizmo's (gizmo at sp+20, not sp+24). */
struct Tag {};
struct Gizmo {
  char pad[0x30];
  int index;
  int unk34;
};
struct GizmoVec;
extern "C" {
void FUN_001dcc30(GizmoVec *v, Gizmo *const *x, Tag);
void FUN_001d0468(...);
extern char DAT_00392420[];
}

struct GizmoVec {
  Gizmo **data;
  unsigned size;
  unsigned cap;
  Gizmo *&at(unsigned i) { return data[i]; }
  Gizmo *&back() { return at(size - 1); }
  void push_back(Gizmo *const &x, Tag = Tag())
  {
    if (size < cap) {
      size++;
      back() = x;
    } else {
      FUN_001dcc30(this, &x, Tag());
    }
  }
};

struct Mgr {
  char pad[0x88];
  GizmoVec gizmos;
};

extern "C" {
void FUN_001d4be0(Mgr *self, Gizmo *g);
Gizmo *FUN_001d54e8(Mgr *self, int index);

void FUN_001d4f60(Mgr *self, int index, Gizmo *g)
{
  FUN_001d4be0(self, g);
  if (FUN_001d54e8(self, index) != 0)
    FUN_001d0468(DAT_00392420, index);
  g->index = index;
  g->unk34 = 0;
  self->gizmos.push_back(g);
}
}

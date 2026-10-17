/* HSTMATCH module=EBOOT.BIN start=0x0014ee3c end=0x0014eeb4 symbol=FUN_0014ee3c lang=c++ */
/* Clone of src/sharing_main/cursor_value_0015ae44.cpp (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same class and source as src/sharing_main/cursor_value_00158838.cpp with the fields moved up by 4 bytes (container node at +8, owner at +0xc, cursor at +0x18): returns the value behind a cursor that is not the header (node + 4) of the container node, through the virtual call (slot 2) of the owner when there is one, else the field at node + 12; 0 otherwise. Matching idioms: Differs() written !(!node || cur == &node->hdr) (the materialised !(a == b) gives the xori chain), Valid() with its own bool result variable, and the early return `if (!Valid()) return 0;` followed by `if (owner) return owner->v2(); return node->hdr.f8;` (the ternary form adds a trailing b/nop that this retail copy lacks). Names provisional. */
struct VC {
  virtual void v0();
  virtual void v1();
  virtual int v2();
};

struct Hdr { int a; int b; int f8; };
struct Node {
  int pad0;
  Hdr hdr;
};

struct Obj {
  int pad0[2];
  Node *node;
  VC *owner;
  int pad1[2];
  Hdr *cur;
  bool Differs() const { return !(!node || cur == &node->hdr); }
  bool Valid() const
  {
    bool r = false;
    if (node != 0) {
      if (Differs()) r = true;
    }
    return r;
  }
  int Get() const
  {
    if (!Valid()) return 0;
    if (owner) return owner->v2();
    return node->hdr.f8;
  }
};

extern "C" int FUN_0014ee3c(Obj *self) { return self->Get(); }

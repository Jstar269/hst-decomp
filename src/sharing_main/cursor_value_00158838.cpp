/* HSTMATCH module=hstp_trans_main.prx start=0x00158838 end=0x001588b8 symbol=FUN_00158838 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Returns the value behind a cursor (+0x14) that is not the header (node + 4) of the container node at +4: through the virtual call (slot 2) of the owner at +8 when there is one, else the field at node + 12; 0 otherwise. Matching idioms: Differs() written !(!node || cur == &node->hdr) in an inline member (the materialised !(a == b) gives retail's xori chain), Valid() with its own bool result variable (so the flag survives as a2), and the early return `if (!Valid()) return 0;` before the ternary (the if/else forms drop retail's trailing b/nop). Names provisional. */
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
  int pad0;
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
    return owner ? owner->v2() : node->hdr.f8;
  }
};

extern "C" int FUN_00158838(Obj *self) { return self->Get(); }

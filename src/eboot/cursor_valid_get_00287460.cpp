/* HSTMATCH module=EBOOT.BIN start=0x00287460 end=0x002874c4 symbol=FUN_00287460 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Caller of FUN_0014cd50 (cursor_value_0014cd50.cpp): the same inline Valid()/Differs() test of the cursor object at +8 (matching idioms as documented there), then the out-of-line Get() call. Names provisional. */
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
};

struct Holder {
  int pad0;
  int pad1;
  Obj *cursor;
};

extern "C" int FUN_0014cd50(Obj *self);

extern "C" int FUN_00287460(Holder *h)
{
  Obj *o = h->cursor;
  if (!o->Valid()) return 0;
  return FUN_0014cd50(o);
}

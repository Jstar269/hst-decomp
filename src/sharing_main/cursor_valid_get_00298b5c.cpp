/* HSTMATCH module=hstp_trans_main.prx start=0x00298b5c end=0x00298bc0 symbol=FUN_00298b5c lang=c++ */
/* Clone of src/eboot/cursor_valid_get_00287460.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Caller of FUN_00158838 (cursor_value_00158838.cpp): the same inline Valid()/Differs() test of the cursor object at +8 (matching idioms as documented there), then the out-of-line Get() call. Names provisional. */
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

extern "C" int FUN_00158838(Obj *self);

extern "C" int FUN_00298b5c(Holder *h)
{
  Obj *o = h->cursor;
  if (!o->Valid()) return 0;
  return FUN_00158838(o);
}

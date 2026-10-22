/* HSTMATCH module=hstp_trans_main.prx start=0x00068b84 end=0x00068bdc symbol=FUN_00068b84 lang=c++ */
/* Clone of src/eboot/destroy_list_objects_00067730.cpp (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Walks the intrusive list whose head pointer sits at +0x44 of the object (the sentinel node is the
   4-byte field at +0x40) and calls the third virtual of every listed object (vtable slot at +16)
   with the global at DAT_003da704, then follows the next pointer at +4.
   Matching idioms: the virtual call goes through t9 (a C++ member call on a separate VC type, whose
   vptr is at offset 0), and the otherwise invisible 16-byte frame slot of retail's 32-byte frame comes
   from an inline helper taking an empty tag by value. Names provisional. */
struct VC;

struct Node {
  int f0;
  Node *f4;
  VC *f8;
};

struct VC {
  virtual void v0();
  virtual void v1();
  virtual void v2(int);
};

struct Obj {
  char pad[0x40];
  int f40;
  Node *f44;
};

struct Tag {};

static inline Node *Next(Node *n, Tag)
{
  return n->f4;
}

extern int DAT_003da704;

extern "C" void FUN_00068b84(Obj *self)
{
  Node *n = self->f44;
  Node *end = (Node *)&self->f40;
  while (n != end) {
    VC *o = n->f8;
    o->v2(DAT_003da704);
    n = Next(n, Tag());
  }
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0006a738 end=0x0006a894 symbol=FUN_0006a738 lang=c++ */
/* Clone of src/eboot/dtor_clear_items_00069270.cpp (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting-destructor shaped teardown: sets the derived vtable, walks the tree at +0x38 deleting every
   sub-object, clears the item states at +0x14, destroys the map at +0x34, unlinks the list at +0x28 and
   finally restores the base vtable and frees the object when flag > 0. */
/* matching idiom: the tested field is the first argument of the call that follows (MWCC keeps it in a0),
   the item pointer is tested twice before the deleting destructor, and the map/list members are guarded
   by nested null checks on their own addresses (four and three levels). */
typedef unsigned int uint;

struct Obj;
typedef struct NodeA NodeA;
typedef struct NodeB NodeB;
typedef struct Tree Tree;
typedef struct ItB ItB;

struct NodeA {
  NodeA *f0;
  NodeA *f4;
  NodeA *f8;
  NodeA *fc;
  void *f10;
};
struct NodeB {
  NodeB *prev;
  NodeB *next;
};
struct ItB { NodeB *node; };
struct Tree { int header; };
struct Obj {
  void *vptr;
  char pad4[0x10];
  void *f14;
  char pad18[0x10];
  int f28;
  NodeB sentinelB;
  Tree tree;
  NodeA sentinelA;
};

struct VC_0 { virtual ~VC_0(); };

extern "C" {
void FUN_000652ac(NodeA **);
void FUN_0006c25c(void *, void *);
void FUN_0006c85c(ItB *, int *, ItB *, ItB *);
void FUN_0006cc84(Tree *, int);
void FUN_00058384(void *);
void FUN_00000a00(void *);
}
extern void *DAT_003daf68;
extern char DAT_003b0480[];
extern char DAT_003b045c[];

extern "C" void *FUN_0006a738(Obj *self, short flag)
{
  if (self != 0) {
    self->vptr = &DAT_003b0480;
    {
      NodeA *it = self->sentinelA.f8;
      if (it != &self->sentinelA) {
        do {
          void *sub = it->f10;
          if (sub != 0) {
            delete (VC_0 *)sub;
            it->f10 = 0;
          }
          FUN_000652ac(&it);
        } while (it != &self->sentinelA);
      }
    }
    if (self->f14 != 0) {
      FUN_00058384(self->f14);
      if (DAT_003daf68 != 0) {
        FUN_0006c25c((char *)DAT_003daf68 + 0x10, self->f14);
      }
      self->f14 = 0;
    }
    if ((&self->tree != 0) && (&self->tree != 0) && (&self->tree != 0) && (&self->tree != 0)) {
      FUN_0006cc84(&self->tree, 0);
    }
    if ((&self->f28 != 0) && (&self->f28 != 0) && (&self->f28 != 0)) {
      ItB out;
      ItB first;
      ItB last;
      last.node = &self->sentinelB;
      first.node = self->sentinelB.next;
      FUN_0006c85c(&out, &self->f28, &first, &last);
    }
    if (self != 0) {
      self->vptr = &DAT_003b045c;
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
